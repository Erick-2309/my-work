# Commandes terrain — GNSS Pi Zero 2W

Toutes les commandes à utiliser depuis un téléphone ou un PC via SSH.

---

## workflow 

La Pi s'allume → code démarre automatiquement dans tmux

      ↓
      
Asseder a la pi via SSH depuis le téléphone → ( pour cela il faut installer l'application "terminal"  il faut egalement que votre téléphone partage sa connection avec la pi)
      
      ↓
      
Chemin vers le programme ( ~/Desktop/GNSS/STATIC)

      ↓
      
rejoindre la session tmux pour voir l'acquisition en live(tmux attach -t gnss)
Pour quitter tmux sans tuer le script : `Ctrl+B` puis `D` 

      ↓
  
Arrêter proprement l'acquisition  (touch /home/pi/Desktop/GNSS/STATIC/STATE/STOP_GNSS)

      ↓
      
Relance sans redémarrer :(tmux kill-session -t gnss 2>/dev/null; tmux new-session -d -s gnss 'cd /home/pi/Desktop/GNSS/STATIC/ && python3 test_gnss.py')





# Lancement manuel 


## chemin vers le programme 
```
cd ~/Desktop/GNSS/STATIC
```

## Lancer le script (résiste à la déconnexion SSH)

```
tmux kill-session -t gnss 2>/dev/null; tmux new-session -d -s gnss 'cd /home/pi/Desktop/GNSS/STATIC/ && python3 test_gnss.py'
```

Le script tourne dans une session tmux. Même si tu fermes SSH ou que le hotspot coupe, il continue.

---

## Vérifier que ça tourne bien 

### Option 1 — voir l'état en un mot
```bash
cat /home/pi/Desktop/GNSS/STATIC/STATE/gnss_status.txt
```
Exemple de réponse :
```
ETAT   : ACQUISITION
DETAIL : 12.34 MB recus | binary_20260615_143000.bin
HEURE  : Sat Jun 15 14:32:10 2026
```

### Option 2 — voir que le script est vivant (mis à jour toutes les 2s)
```bash
cat /home/pi/Desktop/GNSS/STATIC/STATE/gnss_alive.txt
```

### Option 3 — voir les logs en direct
```bash
tail -f /home/pi/Desktop/GNSS/STATIC/STATE/gnss_log.txt
```


### Option 5 — rejoindre la session tmux pour voir le terminal live
```
tmux attach -t gnss
```
Pour quitter tmux sans tuer le script : `Ctrl+B` puis `D`

---

## Arrêter proprement l'acquisition

```
touch /home/pi/Desktop/GNSS/STATIC/STATE/STOP_GNSS
```

Le script détecte ce fichier, arrête la lecture, lance la conversion RTK, puis sauvegarde tout. Ne pas couper brutalement.

---

## Vérifier les fichiers enregistrés

```
ls -lh /home/pi/Desktop/GNSS/STATIC
```

Les fichiers de données ont le timestamp dans leur nom :
- `binary_20260615_143000.bin` — données brutes
- `Rinex_20260615_143000.obs` — observations RINEX
- `navig_20260615_143000.nav` — navigation RINEX

















## Mise en place du lancement automatique au boot

Crée le service systemd :

```
bashsudo nano /etc/systemd/system/gnss.service
```

Colle exactement ceci :

```
ini[Unit]
Description=Acquisition GNSS
After=network.target

[Service]
Type=forking
User=pi
ExecStart=/usr/bin/tmux new-session -d -s gnss 'cd /home/pi/Desktop/GNSS/STATIC && python3 test_gnss.py'
RemainAfterExit=yes

[Install]
WantedBy=multi-user.target
```

pour modifier la configuration
```sudo nano /etc/systemd/system/gnss.service```

Active et démarre :

```
bashsudo systemctl daemon-reload
sudo systemctl enable gnss.service
sudo systemctl start gnss.service
```

Vérifie que ça tourne :

```
bashsudo systemctl status gnss.service
tmux attach -t gnss
```


##Désactiver définitivement (ne se relance plus jamais au boot) :

```
bashsudo systemctl disable gnss.service
```

##Arrêter pour cette session seulement (repart au prochain boot) :

```
bashsudo systemctl stop gnss.service
```
##Vérifier l'état :

```
bashsudo systemctl status gnss.service
```

##Si tu vois disabled → plus de lancement automatique. Si tu veux le réactiver plus tard :

```
bashsudo systemctl enable gnss.service
```
