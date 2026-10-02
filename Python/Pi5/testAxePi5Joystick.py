# ============================================================
# IMPORTS
# ============================================================
import cv2 as cv
import numpy as np
import time
import serial
from picamera2 import Picamera2
import matplotlib.pyplot as plt
from collections import deque

# ============================================================
# CONFIGURATION
# ============================================================

plateau_locked = False
xp_ref, yp_ref, rp_ref = 0, 0, 0

SERVO_FLAT = 90
PID_AMPLITUDE = 140 # Amplitude max de correction
ALPHA = 0.75 # Lissage exponentiel (0 = pas de lissage, 1 = fig)

# Port serie (Verifie bien que c'est le bon port, souvent /dev/ttyACM0 ou USB0)
SERIAL_PORT = "/dev/ttyACM0" 
SERIAL_BAUD = 115200

# ============================================================
# SERIAL ARDUINO
# ============================================================

try:
    ser = serial.Serial(SERIAL_PORT, SERIAL_BAUD, timeout=0.1)
    ser.flush() # Vide les buffers
    time.sleep(2)
    print("Arduino connecte sur", SERIAL_PORT)
except Exception as e:
    print(f"ERREUR : Arduino non detecte sur {SERIAL_PORT}")
    print(e)
    exit()

def send_servo_angle_pid(angle):
    # Securite bornes
    angle = int(max(0, min(180, angle)))
    # Envoi format "angle1,angle2\n" (ici on envoie le meme angle aux 2 moteurs pour l'exemple)
    msg = f"{angle},{angle}\n"
    ser.write(msg.encode('utf-8'))

# ============================================================
# PID CLASS
# ============================================================

class PID:
    def __init__(self, Kp, Ki, Kd):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.prev_error = 0
        self.integral = 0

    def compute(self, error, dt):
        self.integral += error * dt
        # Anti-windup (limite l'integrale pour eviter qu'elle s'emballe)
        self.integral = max(min(self.integral, 50), -50)
        
        derivative = (error - self.prev_error) / dt if dt > 0 else 0
        self.prev_error = error
        return self.Kp * error + self.Ki * self.integral + self.Kd * derivative

    def reset(self):
        self.prev_error = 0
        self.integral = 0

# Reglages PID (A ajuster selon ton systeme)
pid_x = PID(Kp=0.25, Ki=0.002, Kd=0.15)
# ============================================================
# CAMERA SETUP
# ============================================================

picam2 = Picamera2()
config = picam2.create_video_configuration(
    main={"size": (800, 600), "format": "RGB888"}
)
picam2.configure(config)
picam2.set_controls({"FrameDurationLimits": (16666, 16666)}) # ~60 FPS
picam2.start()

# ============================================================
# VARIABLES GLOBALES
# ============================================================

xp, yp, rp = 400, 300, 280
last_time = time.time()
arduino_mode = "WAITING..." # Sera mis a jour par le retour serie

current_angle = float(SERVO_FLAT)
target_angle = float(SERVO_FLAT)
xb_old = xp

# ============================================================
# GRAPHIQUE LIVE (Matplotlib)
# ============================================================

graph_window = 300
err_history = deque(maxlen=graph_window)
pid_history = deque(maxlen=graph_window)
angle_history = deque(maxlen=graph_window)

plt.ion()
fig, ax = plt.subplots(figsize=(8, 4))
line_err, = ax.plot([], [], label="Erreur", color='red')
line_pid, = ax.plot([], [], label="PID Out", color='blue')
line_angle, = ax.plot([], [], label="Angle Servo", color='green')

ax.set_ylim(-1.5, 1.5) # Echelle normalisee
ax.set_xlim(0, graph_window)
ax.legend()
ax.grid(True)

def update_pid_graph():
    if len(err_history) > 1:
        x_data = np.arange(len(err_history))
        line_err.set_data(x_data, list(err_history))
        line_pid.set_data(x_data, list(pid_history))

        norm_angles = [(a - 90)/45.0 for a in angle_history]
        line_angle.set_data(x_data, norm_angles)

        ax.set_xlim(0, len(err_history))
        fig.canvas.draw_idle()
        plt.pause(0.001)

# ============================================================
# MAIN LOOP
# ============================================================

print("Demarrage du systeme...")

try:
    while True:
        # ---------------- 1. LECTURE SERIE (FEEDBACK ARDUINO) ----------------
        # On regarde si l'Arduino nous parle (pour savoir si on est en Auto ou Manuel)
        if ser.in_waiting > 0:
            try:
                line = ser.readline().decode('utf-8').strip()
                # L'arduino envoie "MODE: AUTO" ou "MODE: MANUEL" quand on appuie
                if "MODE:" in line:
                    arduino_mode = line.split(":")[1].strip()
                    if arduino_mode == "MANUEL":
                        pid_x.reset() # Reset PID quand on passe en manuel
            except:
                pass

        # ---------------- 2. ACQUISITION IMAGE ----------------
        frame = picam2.capture_array()
        frame_bgr = cv.cvtColor(frame, cv.COLOR_RGB2BGR)
        
        # Copie pour affichage propre
        display_frame = frame_bgr.copy()
        
        # ---------------- 3. DETECTION PLATEAU (Initialisation) ----------------
        if not plateau_locked:
            gray = cv.cvtColor(frame_bgr, cv.COLOR_BGR2GRAY)
            blur = cv.medianBlur(gray, 5)
            circles = cv.HoughCircles(blur, cv.HOUGH_GRADIENT, 2, gray.shape[0],
                                      param1=120, param2=150, minRadius=160, maxRadius=300)
            if circles is not None:
                circles = np.uint16(np.around(circles))
                xp_ref, yp_ref, rp_ref = circles[0][0]
                plateau_locked = True
                xp, yp, rp = xp_ref, yp_ref, rp_ref
                print(f"Plateau verrouille : x={xp}, y={yp}, r={rp}")

        # Dessin zone safe
        if plateau_locked:
             cv.circle(display_frame, (xp, yp), rp, (0, 255, 0), 2)

        # ---------------- 4. DETECTION BALLE ----------------
        hsv = cv.cvtColor(frame_bgr, cv.COLOR_BGR2HSV)
        
        # Masque pour ne chercher que DANS le plateau
        maskSafe = np.zeros(frame_bgr.shape[:2], dtype="uint8")
        cv.circle(maskSafe, (xp, yp), int(rp * 0.95), 255, -1)
        
        # Seuillage couleur (Balle Bleue)
        lower_blue = np.array([95, 80, 60])
        upper_blue = np.array([135, 255, 255])
        maskBlue = cv.inRange(hsv, lower_blue, upper_blue)
        maskBlue = cv.bitwise_and(maskBlue, maskBlue, mask=maskSafe)
        maskBlue = cv.medianBlur(maskBlue, 5)

        contours, _ = cv.findContours(maskBlue, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

        balle_found = False
        xb, yb = xp, yp # Par defaut au centre

        # Trouver la plus grosse balle
        if contours:
            largest_cnt = max(contours, key=cv.contourArea)
            if cv.contourArea(largest_cnt) > 80:
                M = cv.moments(largest_cnt)
                if M["m00"] != 0:
                    xb = int(M["m10"] / M["m00"])
                    yb = int(M["m01"] / M["m00"])
                    balle_found = True
                    cv.circle(display_frame, (xb, yb), 10, (0, 0, 255), -1)
                    # ---------------- 5. CALCUL PID ----------------
        
        # Filtre sur la position (Low Pass Filter) pour rduire le bruit
        xb_filt = 0.6 * xb_old + 0.4 * xb
        xb_old = xb_filt
        
        # Calcul Delta Temps
        now = time.time()
        dt = max(now - last_time, 0.005)
        last_time = now

        pid_out = 0
        
        if balle_found:
            # Erreur par rapport au centre (normalisee entre -1 et 1 environ)
            dx = (xb_filt - xp)
            err = dx / float(rp) 
            
            # Calcul PID
            raw_pid = pid_x.compute(err, dt)
            pid_out = np.clip(raw_pid, -1, 1)
            
            # Mise a jour graphiques
            err_history.append(err)
            pid_history.append(pid_out)
        else:
            # Si pas de balle, on suppose qu'elle est perdue ou au centre
            err_history.append(0)
            pid_history.append(0)
        if not balle_found:
            pid_x.reset()
            target_angle = SERVO_FLAT
            current_angle += (target_angle - current_angle) * ALPHA

            if arduino_mode == "AUTO":
                send_servo_angle_pid(current_angle)

            continue

        # ---------------- 6. CONVERSION EN ANGLE & ENVOI ----------------
        
        # Angle cible (Base 90 + PID * Amplitude)
        # Note : On envoie TOUJOURS le calcul. L'Arduino decide de l'utiliser ou non.
        target_angle = SERVO_FLAT + (pid_out * PID_AMPLITUDE)
        
        # Lissage du mouvement servo (Smoothing)
        current_angle += (target_angle - current_angle) * ALPHA
        
        # Envoi a l'Arduino
        # Envoi UNIQUEMENT si Arduino en AUTO
        if arduino_mode == "AUTO":
            send_servo_angle_pid(current_angle)

        
        angle_history.append(current_angle)

        # ---------------- 7. AFFICHAGE ET DEBUG ----------------
        
        # Update graph matplotlib (attention a peut ralentir, on le fait 1 fois sur 5)
        if len(angle_history) % 5 == 0:
           update_pid_graph()
        # ================= AFFICHAGE CENTRES & DISTANCE =================

        # Centre du plateau
        cv.circle(display_frame, (xp, yp), 8, (0, 255,0), -1)  # Rouge

        # Ligne horizontale entre centre plateau et balle
        cv.line(
            display_frame,
            (xp, yp),
            (int(xb_filt), yp),
            (0, 255, 255),
            2
        )

        # Distance X en pixels
        dx_pixels = int(xb_filt - xp)

        cv.putText(
            display_frame,
            f"dx = {dx_pixels}px",
            (min(xp, int(xb_filt)) + 10, yp - 10),
            cv.FONT_HERSHEY_SIMPLEX,
            0.7,
            (0, 255, 255),
            2
        )


        cv.putText(display_frame, f"MODE ARDUINO: {arduino_mode}", (20, 40), 
                   cv.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 255), 2)
        cv.putText(display_frame, f"Angle Calc: {int(current_angle)}", (20, 80), 
                   cv.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)

        cv.imshow("Vision Raspberry", display_frame)
        # cv.imshow("Mask", maskBlue) # Decommenter pour debug couleur

        if cv.waitKey(1) & 0xFF == ord("q"):
            break

except KeyboardInterrupt:
    print("Arret utilisateur...")

finally:
    picam2.stop()
    ser.close()
    cv.destroyAllWindows()
    plt.close()
    print("Ferme proprement.")
