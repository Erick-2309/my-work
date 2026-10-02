import cv2 as cv
import numpy as np
import time
import pygame
import serial
from picamera2 import Picamera2

# GRAPH
import matplotlib.pyplot as plt
from collections import deque

############################################
# CONFIG
############################################
plateau_locked = False
xp_ref, yp_ref, rp_ref = 0, 0, 0

SERVO_FLAT = 90
SERVO_MIN = 45
SERVO_MAX = 140
PID_AMPLITUDE = 140
ALPHA = 0.75

SERIAL_PORT = "/dev/ttyACM0"
SERIAL_BAUD = 115200

############################################
# SERIAL ARDUINO
############################################

try:
    ser = serial.Serial(SERIAL_PORT, SERIAL_BAUD, timeout=1)
    time.sleep(2)
    print("Arduino connecté")
except:
    print("ERREUR : Arduino non détecté")
    exit()

def send_servo_angle(angle):
    angle = int(max(0, min(150, angle)))
    ser.write(f"{angle},{angle}\n".encode())

############################################
# JOYSTICK
############################################

pygame.init()
pygame.joystick.init()
joystick_actif = False

if pygame.joystick.get_count() > 0:
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    joystick_actif = True
    print("Joystick OK")
else:
    print("No joystick")

############################################
# PID
############################################

class PID:
    def __init__(self, Kp, Ki, Kd):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.prev_error = 0
        self.integral = 0

    def compute(self, error, dt):
        self.integral += error * dt
        derivative = (error - self.prev_error) / dt if dt > 0 else 0
        self.prev_error = error
        return self.Kp * error + self.Ki * self.integral + self.Kd * derivative

    def reset(self):
        self.prev_error = 0
        self.integral = 0

pid_x = PID(Kp=0.25, Ki=0.002, Kd=0.15)

############################################
# CAMERA
############################################

picam2 = Picamera2()
config = picam2.create_video_configuration(
    main={"size": (800, 600), "format": "RGB888"}
)
picam2.configure(config)
picam2.set_controls({"FrameDurationLimits": (16666, 16666)})
picam2.start()

############################################
# VARIABLES
############################################

xp, yp, rp = 400, 300, 280
last_time = time.time()
mode = "auto"
last_btn_state = False

current_angle = float(SERVO_FLAT)
target_angle = float(SERVO_FLAT)

xb_old = xp

############################################
# GRAPH
############################################

graph_window = 300
err_history = deque(maxlen=graph_window)
pid_history = deque(maxlen=graph_window)
angle_history = deque(maxlen=graph_window)

plt.ion()
fig, ax = plt.subplots(figsize=(8, 4))

line_err, = ax.plot([], [], label="Erreur", color="blue")
line_pid, = ax.plot([], [], label="PID", color="red")
line_angle, = ax.plot([], [], label="Servo", color="green")

ax.set_ylim(-1.2, 1.2)
ax.set_xlim(0, graph_window)
ax.legend()
ax.grid(True)

def update_pid_graph():
    x = np.arange(len(err_history))
    line_err.set_data(x, list(err_history))
    line_pid.set_data(x, list(pid_history))
    line_angle.set_data(x, list(angle_history))
    fig.canvas.draw()
    fig.canvas.flush_events()

############################################
# MAIN LOOP
############################################

try:
    while True:

        frame = picam2.capture_array()
        frame_bgr = cv.cvtColor(frame, cv.COLOR_RGB2BGR)
        hsv = cv.cvtColor(frame_bgr, cv.COLOR_BGR2HSV)

        # PLATEAU
        gray = cv.cvtColor(frame_bgr, cv.COLOR_BGR2GRAY)
        blur = cv.medianBlur(gray, 5)
        circles = cv.HoughCircles(
            blur, cv.HOUGH_GRADIENT, 2, gray.shape[0],
            param1=120, param2=150, minRadius=160, maxRadius=300
        )

        maskPlateau = np.zeros_like(frame_bgr)
        # MASQUE INTERIEUR DE SECURITE (on enlève le bord)
        maskSafe = np.zeros_like(maskPlateau[:, :, 0])
        safe_radius = int(rp * 0.90)  # 90% du rayon
        cv.circle(maskSafe, (xp, yp), safe_radius, 255, -1)


        if circles is not None and not plateau_locked:
            circles = np.uint16(np.around(circles))
            xp_ref, yp_ref, rp_ref = circles[0][0]
            plateau_locked = True
            print("Plateau verrouillé :", xp_ref, yp_ref, rp_ref)

        if plateau_locked:
            xp, yp, rp = xp_ref, yp_ref, rp_ref
            cv.circle(frame_bgr, (xp, yp), rp, (0, 255, 0), 2)
            cv.circle(maskPlateau, (xp, yp), rp, (255, 255, 255), -1)

        # BALLE BLEUE
        lower_blue = np.array([95, 80, 60])
        upper_blue = np.array([135, 255, 255])

        maskBlue = cv.inRange(hsv, lower_blue, upper_blue)
        maskBlue = cv.bitwise_and(maskBlue, maskSafe)
        maskBlue = cv.medianBlur(maskBlue, 5)

        contours, _ = cv.findContours(maskBlue, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

        balle_found = False
        xb, yb = xp, yp

        for cnt in contours:
            if cv.contourArea(cnt) > 80:
                (x, y), r = cv.minEnclosingCircle(cnt)
                dist_center = np.sqrt((x - xp)**2 + (y - yp)**2)
                if dist_center > rp * 0.9:
                    continue

                M = cv.moments(cnt)
                if M["m00"] != 0:
                    xb = int(M["m10"] / M["m00"])
                    yb = int(M["m01"] / M["m00"])
                    balle_found = True
                    cv.circle(frame_bgr, (xb, yb), 5, (255, 0, 0), -1)

        # FILTRE
        xb_filt = 0.6 * xb_old + 0.4 * xb
        xb_old = xb_filt

        # DISTANCE EN PIXELS
        dx = int(xb_filt - xp)
        dy = int(yb - yp)
        distance_px = int(np.sqrt(dx*dx + dy*dy))

        # TEMPS
        now = time.time()
        dt = max(now - last_time, 0.005)
        last_time = now

        # INPUT JOYSTICK
        pygame.event.pump()
        if joystick_actif:
            btn = joystick.get_button(3)  # bouton carré / X selon manette
            if btn and not last_btn_state:
                mode = "manual" if mode == "auto" else "auto"
                pid_x.reset()
                target_angle = current_angle
                print("Mode:", mode)
            last_btn_state = btn

        # AUTO
        target_x = xp

        if mode == "auto" and balle_found:
            pos_norm = dx / float(rp)
            #err = 0 if abs(pos_norm) < 0.009 else pos_norm
            err = pos_norm

            pid_out = np.clip(pid_x.compute(err, dt), -1, 1)
            target_angle = SERVO_FLAT + pid_out * PID_AMPLITUDE
            
            print(
            "err:", round(err, 3),
            "pid_out:", round(pid_out, 3),
            "angle:", int(target_angle)
    )
        else:
            pid_out = 0
            err = 0

            target_angle = SERVO_FLAT
            
        # MODE MANUEL
        if mode == "manual" and joystick_actif:
            joy_val = joystick.get_axis(3)  # axe horizontal droit
            if abs(joy_val) < 0.1:
                joy_val = 0

            target_angle = SERVO_FLAT + joy_val * PID_AMPLITUDE

        # SMOOTHING
        current_angle += (target_angle - current_angle) * ALPHA

        send_servo_angle(current_angle)

        # AFFICHAGE POINTS
        cv.circle(frame_bgr, (xp, yp), 6, (0, 0, 255), -1)          # centre plateau
        cv.circle(frame_bgr, (int(xb_filt), yb), 6, (255, 0, 0), -1) # balle
        cv.circle(frame_bgr, (target_x, yp), 6, (0, 255, 255), -1)  # target
        
        # LIGNE ENTRE CENTRE PLATEAU ET BALLE (AXE X)
        pt_plateau = (xp, yp)
        pt_balle_x = (int(xb_filt), yp)

        cv.line(frame_bgr, pt_plateau, pt_balle_x, (255, 255, 0), 2)

        # TEXTE dx AU MILIEU DE LA LIGNE
        mid_x = int((xp + xb_filt) / 2)
        mid_y = yp - 10

        cv.putText(
            frame_bgr,
            f"{dx}px",
            (mid_x, mid_y),
            cv.FONT_HERSHEY_SIMPLEX,
            0.6,
            (255, 255, 0),
            2
)


        # TEXTE DISTANCE
        cv.putText(
            frame_bgr,
            f"dx = {dx}px | dist = {distance_px}px",
            (20, 30),
            cv.FONT_HERSHEY_SIMPLEX,
            0.7,
            (255, 255, 255),
            2
        )

        cv.imshow("Vision", frame_bgr)
        cv.imshow("Mask Blue", maskBlue)

        if cv.waitKey(1) & 0xFF == ord('q'):
            break

except KeyboardInterrupt:
    print("Stop")

finally:
    picam2.stop()
    ser.close()
    pygame.quit()
    cv.destroyAllWindows()
