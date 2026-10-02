

import serial
import struct
import time

PORT = "/dev/tty.usbmodem57860483031"
BAUD = 115200

def send_raw_enable_packet(ser):
    """ Envoie la commande binaire pour forcer le SkyTraq à sortir le RAW (0xE5) """
    payload = bytes([
        0x1F,  # ID de commande : Configure Binary Output
        0x01,  # Fréquence de sortie : 1Hz
        0x01,  # Meas_time ENABLE (Message 0xDC)
        0x01,  # Raw_meas ENABLE  (Message 0xE5 ⭐ TRÈS IMPORTANT)
        0x01,  # SV_CH_Status ENABLE
        0x01,  # RCV_State ENABLE
        0x03   # Subframe enable
    ])
    
    # Construction de la trame binaire SkyTraq
    start = b'\xA0\xA1'
    length = len(payload).to_bytes(2, "big")
    cs = 0
    for b in payload:
        cs ^= b
    end = b'\x0D\x0A'
    packet = start + length + payload + bytes([cs]) + end
    
    print("-> Envoi de la commande d'activation du flux binaire RAW...")
    ser.write(packet)
    time.sleep(0.5)  # Laisse le temps au récepteur de traiter l'ordre

def parse_skytraq_raw_e5(payload):
    """Décode le payload d'un message SkyTraq 0xE5 réel ou simulé"""
    if len(payload) < 9:
        return

    msg_id = payload[0]
    
    # Optionnel : Affiche une notification si le récepteur confirme la commande (ACK = 0x83)
    if msg_id == 0x83:
        print("   [Récepteur] Commande binaire acceptée avec succès (ACK) !")
        return
        
    if msg_id != 0xE5:
        return  # Ignore les autres messages de configuration
    
    msg_version = payload[1]
    num_sv = payload[2]
    
    gps_week = struct.unpack(">H", payload[3:5])[0]
    gps_tow = struct.unpack(">I", payload[5:9])[0] / 1000.0
    
    print(f"\n⚡ --- [Message 0xE5 détecté sur le port série] ---")
    print(f"Version: {msg_version} | Satellites actifs suivis: {num_sv}")
    print(f"Temps GPS: Semaine {gps_week}, TOW: {gps_tow} s")
    
    offset = 9
    bytes_per_sv = 20  
    
    for i in range(num_sv):
        sv_data = payload[offset : offset + bytes_per_sv]
        if len(sv_data) < bytes_per_sv:
            break
            
        sv_id = sv_data[0]
        constellation = sv_data[1]
        
        raw_pseudorange = struct.unpack(">I", sv_data[2:6])[0]
        raw_carrier_phase = struct.unpack(">I", sv_data[6:10])[0]
        doppler = struct.unpack(">i", sv_data[10:14])[0] / 10.0  
        snr = sv_data[14]  
        
        print(f"  -> Satellite [PRN {sv_id}] (Constellation: {constellation})")
        print(f"     Pseudo-distance brute : {raw_pseudorange} m")
        print(f"     Phase de la porteuse  : {raw_carrier_phase} cycles")
        print(f"     Doppler               : {doppler} Hz")
        print(f"     Rapport Signal/Bruit  : {snr} dB-Hz")
        
        offset += bytes_per_sv

def main():
    try:
        ser = serial.Serial(PORT, BAUD, timeout=0.1)
        print(f"Connecté au récepteur sur {PORT}")
        
        # OBLIGATOIRE : On active le flux RAW au démarrage du script Python
        send_raw_enable_packet(ser)
        
        print("En attente de données (NMEA ou Binaire RAW)... (Ctrl+C pour quitter)")
    except Exception as e:
        print(f"Erreur d'ouverture du port série: {e}")
        return

    buffer = bytearray()

    while True:
        try:
            data = ser.read(100)
            if not data:
                continue
            
            buffer.extend(data)

            while len(buffer) >= 7:
                if buffer[0] == 0xA0 and buffer[1] == 0xA1:
                    payload_length = struct.unpack(">H", buffer[2:4])[0]
                    total_packet_length = 4 + payload_length + 1 + 2

                    if len(buffer) < total_packet_length:
                        break

                    packet = buffer[:total_packet_length]
                    payload = packet[4 : 4 + payload_length]

                    parse_skytraq_raw_e5(payload)

                    del buffer[:total_packet_length]

                elif buffer[0] == ord('$'):
                    if b'\r\n' in buffer:
                        line_end = buffer.index(b'\r\n') + 2
                        nmea_line = buffer[:line_end].decode('ascii', errors='ignore').strip()
                        print(f"[NMEA] {nmea_line}")
                        del buffer[:line_end]
                    else:
                        break
                else:
                    del buffer[0]

        except KeyboardInterrupt:
            print("\nArrêt du script par l'utilisateur.")
            break
        except Exception as e:
            print(f"Erreur durant la lecture: {e}")
            break

    ser.close()

if __name__ == "__main__":
    main()



'''

# Ce script Python permet de lire à la fois les messages NMEA classiques et les messages binaires RAW (0xE5) du chipset SkyTraq via le port série.
# Il envoie d'abord une commande binaire pour activer le flux RAW, puis il écoute en continu les données entrantes, détecte les trames binaires et les trames NMEA, et affiche les informations extraites de manière lisible dans la console.

import serial
import struct
import time

PORT = "/dev/tty.usbmodem57860483031"
BAUD = 115200

def send_raw_enable_packet(ser):
    """Envoie l'ordre au chipset SkyTraq d'activer les sorties binaires RAW et de temps"""
    payload = bytes([
        0x1F,  # Message ID : Configure Binary Output
        0x01,  # Taux de rafraîchissement = 1Hz
        0x01,  # Meas_time ENABLE (Génère le message binaire 0xDC, fonctionne SANS antenne)
        0x01,  # Raw_meas ENABLE  (Génère le message binaire 0xE5, exige une antenne)
        0x01,  # SV_CH_Status ENABLE
        0x01,  # RCV_State ENABLE
        0x03   # Subframe enable
    ])
    
    # Construction du paquet SkyTraq standard
    start = b'\xA0\xA1'
    length = len(payload).to_bytes(2, "big")
    cs = 0
    for b in payload:
        cs ^= b
    end = b'\x0D\x0A'
    packet = start + length + payload + bytes([cs]) + end
    
    print("Activation des messages binaires RAW...")
    ser.write(packet)
    time.sleep(0.5)

def parse_skytraq_binary(msg_id, payload):
    """Parseur central pour les messages binaires SkyTraq"""
    
    # -------------------------------------------------------------------------
    # CAS 1 : Message 0xDC (Measurement Time) -> REÇU MÊME SANS ANTENNE !
    # -------------------------------------------------------------------------
    if msg_id == 0xDC:
        print(f"\n🟢 [Binaire 0xDC détecté] - Horloge interne du récepteur active")
        # Extraction de la version et du nombre de satellites suivis (sera à 0)
        version = payload[1]
        num_sv = payload[2]
        print(f"   Version du firmware: {version} | Satellites en cours de tracking: {num_sv}")
        return

    # -------------------------------------------------------------------------
    # CAS 2 : Message 0xE5 (Raw Measurements) -> EXIGE UNE ANTENNE CONNECTÉE
    # -------------------------------------------------------------------------
    elif msg_id == 0xE5:
        if len(payload) < 9:
            return
        msg_version = payload[1]
        num_sv = payload[2]
        gps_week = struct.unpack(">H", payload[3:5])[0]
        gps_tow = struct.unpack(">I", payload[5:9])[0] / 1000.0
        
        print(f"\n⚡ --- [Binaire 0xE5 : Mesures Brutes GNSS-R] ---")
        print(f"   Satellites: {num_sv} | Temps GPS: Semaine {gps_week}, TOW: {gps_tow} s")
        
        offset = 9
        bytes_per_sv = 20  
        for i in range(num_sv):
            sv_data = payload[offset : offset + bytes_per_sv]
            if len(sv_data) < bytes_per_sv:
                break
            sv_id = sv_data[0]
            constellation = sv_data[1]
            raw_pseudorange = struct.unpack(">I", sv_data[2:6])[0]
            raw_carrier_phase = struct.unpack(">I", sv_data[6:10])[0]
            doppler = struct.unpack(">i", sv_data[10:14])[0] / 10.0  
            snr = sv_data[14]  
            
            print(f"    -> SV [PRN {sv_id}] (Const: {constellation}) | Phase: {raw_carrier_phase} | SNR: {snr} dB-Hz")
            offset += bytes_per_sv

def main():
    try:
        ser = serial.Serial(PORT, BAUD, timeout=0.1)
        print(f"Connecté au récepteur sur {PORT}")
        # Envoi de la commande d'activation au chipset
        send_raw_enable_packet(ser)
        print("En attente de données (NMEA ou Binaire RAW)... (Ctrl+C pour quitter)")
    except Exception as e:
        print(f"Erreur d'ouverture du port série: {e}")
        return

    buffer = bytearray()

    while True:
        try:
            data = ser.read(100)
            if not data:
                continue
            
            buffer.extend(data)

            while len(buffer) >= 7:
                # 1. Détection et extraction des trames binaires SkyTraq
                if buffer[0] == 0xA0 and buffer[1] == 0xA1:
                    payload_length = struct.unpack(">H", buffer[2:4])[0]
                    total_packet_length = 4 + payload_length + 1 + 2

                    if len(buffer) < total_packet_length:
                        break

                    packet = buffer[:total_packet_length]
                    payload = packet[4 : 4 + payload_length]
                    msg_id = payload[0]

                    # Envoi au parseur binaire
                    parse_skytraq_binary(msg_id, payload)

                    del buffer[:total_packet_length]

                # 2. Détection et extraction des trames de texte NMEA
                elif buffer[0] == ord('$'):
                    if b'\r\n' in buffer:
                        line_end = buffer.index(b'\r\n') + 2
                        nmea_line = buffer[:line_end].decode('ascii', errors='ignore').strip()
                        print(f"[NMEA] {nmea_line}")
                        del buffer[:line_end]
                    else:
                        break
                
                # 3. Nettoyage si données corrompues au début du buffer
                else:
                    del buffer[0]

        except KeyboardInterrupt:
            print("\nArrêt du script par l'utilisateur.")
            break
        except Exception as e:
            print(f"Erreur durant la lecture: {e}")
            break

    ser.close()

if __name__ == "__main__":
    main()
'''