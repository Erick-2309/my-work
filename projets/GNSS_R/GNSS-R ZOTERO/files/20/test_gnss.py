'''
import serial

port = '/dev/tty.usbmodem57860483031' 
baudrate = 115200

ser = serial.Serial(port, baudrate, timeout=1)

print("Lecture GNSS en cours...\n")


while True:
    try:
        #line = ser.readline().decode('ascii', errors='replace').strip() # Lire une ligne du flux GNSS et décoder en ASCII
        line = ser.readline().decode(errors='ignore').strip()

        if line: # Si la ligne n'est pas vide, l'afficher
            print(line)
            

    except KeyboardInterrupt: 
        print("\nArrêt.")
        break


    '''
''''
import serial
import time

ser = serial.Serial(
    '/dev/tty.usbmodem57860483031',
    115200,
    timeout=1
)

time.sleep(2)

# Réduire les phrases NMEA
cmd = "$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"

ser.write(cmd.encode())

print("Commande envoyée")

while True:
    line = ser.readline().decode(errors='ignore').strip()

    if line:
        print(line)
        
'''

import serial

ser = serial.Serial('/dev/tty.usbmodem57860483031', 115200)

wanted = ["$GPGGA", "$GNRMC"]

while True:
    line = ser.readline().decode(errors='ignore').strip()

    if any(line.startswith(x) for x in wanted):
        print(line)