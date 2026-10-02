'''
import serial

for baud in [9600, 19200, 38400, 57600, 115200]:

    print("\n====== TEST", baud, "======")

    ser = serial.Serial(
        "/dev/tty.usbserial-0001",
        baud,
        timeout=2
    )

    d = ser.read(64)

    print(d.hex(" "))

    ser.close()
    '''

'''
import serial

ser = serial.Serial("/dev/tty.usbserial-0001",115200)

while True:
    d = ser.read(256)
    if d:
        print(d.hex(" "))

'''

import serial
import time

ser = serial.Serial("/dev/tty.usbserial-0001", 115200, timeout=0.01)

buffer = bytearray()

while True:
    data = ser.read(256)

    if data:
        buffer.extend(data)

    # Attendre une petite pause pour considérer la trame terminée
    if buffer:
        time.sleep(0.005)

        if ser.in_waiting == 0:
            print("Trame reçue :", len(buffer), "octets")
            print(buffer.hex(" "))
            buffer.clear()
