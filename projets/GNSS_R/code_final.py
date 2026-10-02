
import os
import sys
import time
import socket
import serial
import threading
import subprocess

# Force UTF-8 en sortie, meme si le terminal/locale du systeme est
# restrictif (ex: latin-1 sur certains Raspberry Pi), pour eviter
# les UnicodeEncodeError sur des caracteres comme les accents ou le tiret long.
try:
    sys.stdout.reconfigure(encoding="utf-8")
    sys.stderr.reconfigure(encoding="utf-8")
except Exception:
    pass

# =========================
# PORTS GNSS
# =========================

GNSS1_PORT = "/dev/ttySC0"
GNSS2_PORT = "/dev/ttySC1"

BAUDRATE = 115200

# =========================
# GNSS2
# =========================

GNSS2_ACTIVE = True

# =========================
# SEGMENTATION
# =========================
# Deux modes possibles :
#   "interval" -> un nouveau fichier toutes les SEGMENT_DURATION secondes
#                 (utile pour les tests, ex: 300 = 5 minutes)
#   "daily"    -> un nouveau fichier a chaque minuit (00h00), quelle que
#                 soit l'heure de lancement du programme
#
# Pour tester par intervalles de 5 min : SEGMENT_MODE = "interval"
# Pour passer en production (1 fichier/jour) : SEGMENT_MODE = "daily"

SEGMENT_MODE = "interval"
SEGMENT_DURATION = 1800  # utilise seulement si SEGMENT_MODE == "interval"


def calculer_duree_segment():
    """
    Retourne la duree (en secondes) que doit durer le segment qui
    commence maintenant, selon le mode choisi.
    """

    if SEGMENT_MODE == "daily":
        maintenant = time.time()
        struct = time.localtime(maintenant)
        minuit_suivant = time.mktime((
            struct.tm_year, struct.tm_mon, struct.tm_mday,
            0, 0, 0, 0, 0, -1
        )) + 86400  # minuit du jour suivant
        return minuit_suivant - maintenant

    # mode "interval" (tests)
    return SEGMENT_DURATION

# =========================
# DOSSIERS
# =========================
# BIN_DIR   -> uniquement les fichiers binaires bruts (.bin)
# OBS_DIR   -> uniquement les fichiers RINEX observation (.obs)
# NAV_DIR   -> uniquement les fichiers RINEX navigation (.nav)
# STATE_DIR -> tous les fichiers de controle/etat du programme
#              (STOP_GNSS, gnss_status.txt, gnss_log.txt, gnss_alive.txt)
#              -> aucun fichier de donnees GNSS ne doit se retrouver ici

BIN_DIR = "/home/pi/Desktop/GNSS/STATIC/BIN"
OBS_DIR = "/home/pi/Desktop/GNSS/STATIC/RINEX"
NAV_DIR = "/home/pi/Desktop/GNSS/STATIC/NAVIG"
STATE_DIR = "/home/pi/Desktop/GNSS/STATIC/STATE"
os.makedirs(BIN_DIR, exist_ok=True)
os.makedirs(OBS_DIR, exist_ok=True)
os.makedirs(NAV_DIR, exist_ok=True)
os.makedirs(STATE_DIR, exist_ok=True)

# =========================
# FICHIERS DE CONTROLE
# =========================

STOP_FILE   = os.path.join(STATE_DIR, "STOP_GNSS")
STATUS_FILE = os.path.join(STATE_DIR, "gnss_status.txt")
LOG_FILE    = os.path.join(STATE_DIR, "gnss_log.txt")

# =========================
# LOG
# =========================

def log(message):
    ligne = f"{time.ctime()} | {message}"
    print(ligne, flush=True)
    with open(LOG_FILE, "a", encoding="utf-8") as f:
        f.write(ligne + "\n")

# =========================
# STATUS
# =========================

def set_status(etat, detail=""):
    try:
        with open(STATUS_FILE, "w", encoding="utf-8") as f:
            f.write(f"ETAT   : {etat}\n")
            f.write(f"DETAIL : {detail}\n")
            f.write(f"HEURE  : {time.ctime()}\n")
    except Exception:
        pass

# =========================
# INTERNET
# =========================
# Note : garde uniquement a titre informatif dans le statut du systeme
# (utile si tu veux surveiller la connectivite a distance). N'est plus
# utilise pour un quelconque envoi de fichiers depuis que Supabase a
# ete retire de ce script.

def internet_disponible():
    try:
        socket.create_connection(("8.8.8.8", 53), timeout=5)
        return True
    except Exception:
        return False

# =========================
# HEARTBEAT
# Affiche et ecrit les octets recus toutes les 10s
# (stats est remis a zero a chaque nouveau segment)
# =========================

def heartbeat(current_stats_ref):
    """
    Thread UNIQUE pour toute la duree du programme.
    current_stats_ref est un dict container: {"stats": <dict du segment actuel>}
    On lit toujours current_stats_ref["stats"], qui est remplace a chaque
    nouveau segment dans la boucle principale -> plus jamais de thread
    "fantome" qui continue a publier les anciennes valeurs figees.
    """

    # CORRECTION : gnss_alive.txt est un fichier d'ETAT (comme
    # STATUS_FILE et LOG_FILE), pas une donnee GNSS -> il va dans
    # STATE_DIR, pas dans BIN_DIR (qui ne doit contenir que des .bin).
    alive_file = os.path.join(STATE_DIR, "gnss_alive.txt")

    while True:

        try:
            stats = current_stats_ref.get("stats")

            if stats is not None:

                mb_A = stats['bytes_A'] / 1_000_000

                log(f"GNSS1 : {stats['bytes_A']} octets ({mb_A:.2f} MB)")

                if GNSS2_ACTIVE:
                    mb_B = stats['bytes_B'] / 1_000_000
                    log(f"GNSS2 : {stats['bytes_B']} octets ({mb_B:.2f} MB)")

                with open(alive_file, "w", encoding="utf-8") as f:
                    f.write(f"HEURE : {time.ctime()}\n")
                    f.write(f"GNSS1 : {stats['bytes_A']} octets ({mb_A:.2f} MB)\n")
                    if GNSS2_ACTIVE:
                        f.write(f"GNSS2 : {stats['bytes_B']} octets ({mb_B:.2f} MB)\n")

                set_status(
                    "ACQUISITION",
                    f"GNSS1: {mb_A:.2f} MB"
                )

        except Exception:
            pass

        time.sleep(10)

# =========================
# GNSS PRESENT ?
# =========================

def attendre_gnss(port):

    log(f"Verification {port}...")

    while True:
        try:
            ser = serial.Serial(port, BAUDRATE, timeout=1)
            data = ser.read(1024)
            ser.close()
            if len(data) > 100:
                log(f"{port} OK ({len(data)} octets)")
                return
        except Exception as e:
            log(str(e))
        time.sleep(5)

# =========================
# CONVERSION RINEX
# =========================
# Cette fonction convertit UN fichier binaire en fichiers RINEX
# (.obs + .nav) via l'outil convbin. Elle est appelee par
# convertir_segment_en_rinex() ci-dessous.

def convertir(bin_file, obs_file, nav_file, label):

    log(f"Conversion {label}...")

    result = subprocess.run(
        [
            "./convbin",
            "-r", "stq",
            "-v", "3.04",
            "-od",
            "-os",
            "-o", obs_file,
            "-n", nav_file,
            "-g", "/dev/null",
            "-h", "/dev/null",
            "-q", "/dev/null",
            "-l", "/dev/null",
            bin_file
        ],
        capture_output=True
    )

    stdout_text = result.stdout.decode("utf-8", errors="ignore")
    stderr_text = result.stderr.decode("utf-8", errors="ignore")

    resume_convbin = None
    texte_complet = stdout_text + "\n" + stderr_text

    for ligne in texte_complet.splitlines():
        if "O=" in ligne:
            resume_convbin = ligne.strip()

    if resume_convbin:
        log(f"convbin {label} -> {resume_convbin}")

    taille_bin = os.path.getsize(bin_file) if os.path.exists(bin_file) else 0
    taille_obs = os.path.getsize(obs_file) if os.path.exists(obs_file) else 0
    taille_nav = os.path.getsize(nav_file) if os.path.exists(nav_file) else 0

    log(
        f"{label} - "
        f"BIN={taille_bin}B "
        f"OBS={taille_obs}B "
        f"NAV={taille_nav}B"
    )

    return taille_bin, taille_obs, taille_nav

# =========================
# CONVERSION D'UN SEGMENT TERMINE (GNSS1 + GNSS2)
# =========================
# Fonction "chef d'orchestre" : convertit le binaire de GNSS1 (et de
# GNSS2 si actif) en fichiers RINEX. Appelee dans un thread separe
# depuis le main, pour ne pas bloquer l'ecriture du segment suivant
# pendant que la conversion du segment precedent est en cours.
#
# IMPORTANT : cette fonction n'est utile QUE si elle est appelee.
# Si tu ne veux QUE les fichiers binaires (pas de RINEX), commente
# l'appel a cette fonction dans le main (voir plus bas) -> tu obtiens
# uniquement le .bin, la conversion n'a jamais lieu.

def convertir_segment_en_rinex(bin_file_A, obs_file_A, nav_file_A, bin_file_B, obs_file_B, nav_file_B):

    try:
        convertir(bin_file_A, obs_file_A, nav_file_A, "GNSS1")
    except Exception as e:
        log(f"ERREUR conversion GNSS1 : {e}")

    if GNSS2_ACTIVE:
        try:
            convertir(bin_file_B, obs_file_B, nav_file_B, "GNSS2")
        except Exception as e:
            log(f"ERREUR conversion GNSS2 : {e}")

# ==================================================
# MAIN
# ==================================================

log("Demarrage")

if internet_disponible():
    set_status("INTERNET_OK", "Connexion disponible")
else:
    set_status("OFFLINE", "Pas de connexion")

attendre_gnss(GNSS1_PORT)
if GNSS2_ACTIVE:
    attendre_gnss(GNSS2_PORT)

def ouvrir_port(port, label):
    """
    Ouvre le port serie avec des tentatives repetees en cas d'echec
    (port momentanement occupe, cable qui decroche, etc.), au lieu
    de planter le script sans log.
    """
    while True:
        try:
            ser = serial.Serial(port, BAUDRATE, timeout=0)
            log(f"{label} ouvert avec succes sur {port}")
            return ser
        except Exception as e:
            log(f"Erreur ouverture {label} ({port}) : {e} -> nouvelle tentative dans 5s")
            set_status("ERREUR", f"Impossible d'ouvrir {label} : {e}")
            time.sleep(5)


serA = ouvrir_port(GNSS1_PORT, "GNSS1")

if GNSS2_ACTIVE:
    serB = ouvrir_port(GNSS2_PORT, "GNSS2")

stop_requested = False

# Un seul thread heartbeat pour toute la duree du programme.
# On lui passe un container mutable ; on change son contenu a chaque
# nouveau segment au lieu de recreer un thread a chaque fois.
current_stats_ref = {"stats": None}

heartbeat_thread = threading.Thread(
    target=heartbeat,
    args=(current_stats_ref,),
    daemon=True
)
heartbeat_thread.start()

try:
    while not stop_requested:

        # --- nouveau segment : nouveaux noms de fichiers ---
        timestamp = time.strftime("%Y%m%d_%H%M%S")

        bin_name_A = f"binary_GNSS1_{timestamp}.bin"
        obs_name_A = f"Rinex_GNSS1_{timestamp}.obs"
        nav_name_A = f"Navig_GNSS1_{timestamp}.nav"
        bin_file_A = os.path.join(BIN_DIR, bin_name_A)
        obs_file_A = os.path.join(OBS_DIR, obs_name_A)
        nav_file_A = os.path.join(NAV_DIR, nav_name_A)

        bin_name_B = f"binary_GNSS2_{timestamp}.bin"
        obs_name_B = f"Rinex_GNSS2_{timestamp}.obs"
        nav_name_B = f"Navig_GNSS2_{timestamp}.nav"
        bin_file_B = os.path.join(BIN_DIR, bin_name_B)
        obs_file_B = os.path.join(OBS_DIR, obs_name_B)
        nav_file_B = os.path.join(NAV_DIR, nav_name_B)

        stats = {"bytes_A": 0}
        if GNSS2_ACTIVE:
            stats["bytes_B"] = 0

        # on remplace juste la reference lue par le thread heartbeat unique
        current_stats_ref["stats"] = stats

        log(f"Nouveau segment -> {bin_file_A}")
        if GNSS2_ACTIVE:
            log(f"Nouveau segment -> {bin_file_B}")

        segment_start = time.time()
        duree_segment_prevue = calculer_duree_segment()

        if SEGMENT_MODE == "daily":
            log(f"Mode DAILY -> ce segment durera {duree_segment_prevue/3600:.2f} h (jusqu'a minuit)")
        else:
            log(f"Mode INTERVAL -> ce segment durera {duree_segment_prevue:.0f} s")

        fA = open(bin_file_A, "wb")
        fB = open(bin_file_B, "wb") if GNSS2_ACTIVE else None

        try:
            while True:

                try:
                    # --- STOP manuel : on sort immediatement, mais le fichier
                    #     binaire deja ecrit sera quand meme traite plus bas
                    #     (si la conversion RINEX est activee, voir plus bas) ---
                    if os.path.exists(STOP_FILE):
                        os.remove(STOP_FILE)
                        log("STOP detecte -> arret propre (segment en cours traite quand meme)")
                        stop_requested = True
                        break

                    # --- fin de segment (duree prevue ecoulee) ---
                    if time.time() - segment_start >= duree_segment_prevue:
                        log("Duree du segment atteinte -> rotation du fichier")
                        break

                    # --- GNSS1 ---
                    dataA = serA.read(8192)
                    if dataA:
                        fA.write(dataA)
                        stats["bytes_A"] += len(dataA)

                    # --- GNSS2 ---
                    if GNSS2_ACTIVE:
                        dataB = serB.read(8192)
                        if dataB:
                            fB.write(dataB)
                            stats["bytes_B"] += len(dataB)

                    time.sleep(0.001)

                except KeyboardInterrupt:
                    # Ctrl+C attrape ICI (et pas plus haut) pour que le
                    # segment en cours soit quand meme traite correctement
                    # au lieu d'etre coupe net.
                    log("Ctrl+C detecte -> arret propre (segment en cours traite quand meme)")
                    stop_requested = True
                    break

        finally:
            fA.close()
            if fB is not None:
                fB.close()

        # --- duree reelle du segment ---
        duree_sec = int(time.time() - segment_start)
        h = duree_sec // 3600
        m = (duree_sec % 3600) // 60
        s = duree_sec % 60
        duree = f"{h:02d}:{m:02d}:{s:02d}"
        log(f"Segment termine, duree : {duree}")
        log(f"Fichier(s) binaire(s) disponible(s) : {bin_file_A}" + (f" et {bin_file_B}" if GNSS2_ACTIVE else ""))

        # ============================================================
        # CONVERSION EN RINEX (ETAPE OPTIONNELLE)
        # ------------------------------------------------------------
        # Actuellement ACTIVE (les lignes ci-dessous sont decommentees) :
        # chaque segment produit .bin + .obs + .nav.
        #
        # Pour revenir a UNIQUEMENT le fichier binaire (pas de RINEX),
        # remets un "#" devant les 4 lignes ci-dessous (a partir de
        # "thread_traitement = threading.Thread" jusqu'a "thread_traitement.start()")
        # -> thread_traitement restera alors a None (valeur par defaut
        # juste au-dessus), et le reste du programme continuera de
        # fonctionner normalement (voir le "if thread_traitement is not
        # None" plus bas).
        #
        # ATTENTION SI TU (DE)COMMENTES CE BLOC : bien respecter
        # l'alignement (indentation) exact des lignes, sinon Python
        # renverra une erreur au lancement.
        # ============================================================

        thread_traitement = None  # reste a None si la conversion RINEX n'est pas activee

        ### DECOMMENTE OU COMMENTE  CE BLOC POURDESACTIVER OU  ACTIVER LA CONVERSION RINEX ### # bien respecter l'alignement losrque vous decomenterez si non il y aura des erreurs au lancement 

        thread_traitement = threading.Thread(
            target=convertir_segment_en_rinex,
            args=(bin_file_A, obs_file_A, nav_file_A, bin_file_B, obs_file_B, nav_file_B),
            daemon=True
        )
        thread_traitement.start()
        ### FIN DU BLOC A DECOMMENTER ###


        set_status("ACQUISITION", f"Segment {timestamp} termine | duree {duree}")

        # --- si c'est le dernier segment (arret demande) ET que la
        #     conversion RINEX est activee, on attend qu'elle se termine
        #     avant de quitter le programme, sinon le thread (daemon)
        #     serait tue immediatement et le dernier fichier ne serait
        #     jamais converti. Si la conversion RINEX est desactivee
        #     (thread_traitement est reste a None), cette etape est
        #     simplement ignoree. ---
        if stop_requested and thread_traitement is not None:
            log("Attente de la fin de la conversion RINEX du dernier segment...")
            thread_traitement.join()
            log("Dernier segment traite -> fin propre")

except KeyboardInterrupt:
    log("Ctrl+C -> arret propre")

finally:
    serA.close()
    if GNSS2_ACTIVE:
        serB.close()

set_status("TERMINE", "Acquisition arretee")
log("Script termine")
