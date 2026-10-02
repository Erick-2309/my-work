#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL // 16 MHz clock for ATmega328P
/*
// UCSR0C
UMSELn1 = 0; // Asynchronous USART
UMSELn0 = 0; // Asynchronous USART
UPMn0 = 0;   // No Parity
UPMn1 = 0;   // No Parity
USBSn1 = 1;  // 2-bit Stop
UCSZn0 = 1;  // 8-bit data
UCSZn1 = 1;  // 8-bit data

// UCSRB0B
UCSZn2 = 0; // 8-bit data
TXENn = 1;  // Enable Transmitter

//
UBRRn = 103; // 9600 Baud rate at 16MHz

*/
#define BLINK_DELAY 2000000 // to avoid passing a value
/*
void myDelay()
{
    long i = BLINK_DELAY;
    do
    {
        asm("nop"); // if nothing written here, the compiler will remove the function
        asm("nop"); // if nothing written here, the compiler will remove the function
        // ... // better than a for loop
    } while (--i);
}*/
void transmettre(char c)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;     // Wait for empty transmit buffer
    UDR0 = c; // Send character
}
int main(void)
{
    UBRR0H = 0;   // Set baud rate high byte to 0
    UBRR0L = 103; // Set baud rate low byte for 9600 bps at 16MHz
    // uart_init();

    UCSR0C = (0 << UMSEL01) | (0 << UMSEL00) | // Asynchronous mode
             (0 << UPM01) | (0 << UPM00) |     // No parity
             (1 << USBS0) |                    // 2 stop bits
             (1 << UCSZ01) | (1 << UCSZ00);    // 8 data bits

    // Enable transmitter (TX)
    UCSR0B = (1 << TXEN0); // Enable TX

    while (1)
    {
        transmettre('A');
        // PORTB ^= (1 << PB5); // Toggle LED
        _delay_ms(2000);

        transmettre('B');
        // PORTD ^= (1 << PD7); // Toggle LED
        _delay_ms(2000);

        transmettre('C');
        // PORTD ^= (1 << PD6); // Toggle LED
        _delay_ms(2000);
    }
    return 0;
}

/*
compilation : avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -o uar.elf uar.c
              avr-objcopy -O ihex uar.elf uar.hex
              avrdude -c usbtiny -p m328p -U flash:w:uar.hex

              ou avec Makefile : make all
              pour effacer : avrdude -c usbtiny -p m328p -U flash:w:uar.hex
              ou avec Makefile : make clean

              pour lire la memoire flash : avrdude -c usbtiny -p m328p -U flash:r:backup.hex:i

              pour lire la memoire eeprom : avrdude -c usbtiny -p m328p -U eeprom:r:backup_eeprom.hex:i

              pour programmer la memoire eeprom : avrdude -c usbtiny -p m328p -U eeprom:w:backup_eeprom.hex:i

              pour lire les fuses : avrdude -c usbtiny -p m328p -U lfuse:r:lfuse_backup.hex:i -U hfuse:r:hfuse_backup.hex:i -U efuse:r:efuse_backup.hex:i

              pour programmer les fuses : avrdude -c usbtiny -p m328p -U lfuse:w:lfuse_backup.hex:i -U hfuse:w:hfuse_backup.hex:i -U efuse:w:efuse_backup.hex:i

              pour verifier le contenu de la memoire flash : avrdude -c usbtiny -p m328p -U flash:v:uar.hex:i

              pour verifier le contenu de la memoire eeprom : avrdude -c usbtiny -p m328p -U eeprom:v:backup_eeprom.hex:i

              pour verifier les fuses : avrdude -c usbtiny -p m328p -U lfuse:v:lfuse_backup.hex:i -U hfuse:v:hfuse_backup.hex:i -U efuse:v:efuse_backup.hex:i



(base) admin@MacBook-Pro-de-Admin UART % avr-gcc uar.c -mmcu=atmega328p -DF_CPU=16000000UL -Os -o uar
(base) admin@MacBook-Pro-de-Admin UART % avr-objcopy -O ihex uar uar.hex
(base) admin@MacBook-Pro-de-Admin UART % avrdude -V -F -c arduino -p atmega328p -P /dev/cu.usbmodem146301 -b 115200 -D -U flash:w:uar.hex:i
Reading 298 bytes for flash from input file uar.hex
Writing 298 bytes to flash
Writing | ################################################## | 100% 0.07 s
298 bytes of flash written
Avrdude done.  Thank you.
(base) admin@MacBook-Pro-de-Admin UART % avr-gcc uat.c -mmcu=atmega328p -DF_CPU=16000000UL -Os -o uat
(base) admin@MacBook-Pro-de-Admin UART % avr-objcopy -O ihex uat uat.hex
(base) admin@MacBook-Pro-de-Admin UART % avrdude -V -F -c arduino -p atmega328p -P /dev/cu.usbmodem146301 -b 115200 -D -U flash:w:uat.hex:i
Reading 242 bytes for flash from input file uat.hex
Writing 242 bytes to flash
Writing | ################################################## | 100% 0.05 s
242 bytes of flash written
Avrdude done.  Thank you.
(base) admin@MacBook-Pro-de-Admin UART %
*/

// Objectif : établir une  communication série entre les deux ATMEGA  de deux carte arduino en utilisant le port série matériel (UART) intégré au microcontrôleur ATMEGA328P. Et surtout, pour une meilleuere optimisation de la memoire flash, on s'attaquera aux registres pour configurer l'UART (en C & assembler) et non pas en utilisant les fonctions de la bibliothèque <avr/io.h>.

// Le premier ATMEGA (configuré en transmeteur ) envoie des caractères 'A', 'B' et 'C' toutes les 2 secondes
// Le second ATMEGA (configuré en recepteur ) reçoit les caractères et allume la LED connectée au port (PB5) si le caractère reçu est 'A', la LED connectée au port  (PD7) si le caractère reçu est 'B' et la LED connectée au port  (PD6) si le caractère reçu est 'C' pendant 2 secondes

// NOTONS QUE : L'UART (Universal Asynchronous Receiver Transmitter) est un protocole de communication série asynchrone qui permet l'échange de données entre deux dispositifs.
// Lorsqu'une donnée est transmise via l'UART , elle est envoyée (sur 8 bits) bit par bit, avec un bit de start au début et un ou plusieurs bits de stop à la fin. Le récepteur utilise ces bits pour synchroniser la réception des données. Aussi il y a les bits de parité qui sont optionnels et servent à détecter les erreurs de transmission.

// L'UART est configurée en mode asynchrone, sans parité, avec 2 bits de stop et 8 bits de données. Le débit en bauds est de 9600 bauds avec une horloge de 16 MHz. soit 9600 8N2 (8 bits de données, No parity, 2 bits de stop).

// Compilation :
// 🧩 Écris ton programme en C & assembleur natif
// 🛠️ Compile ton programme
// 💾 Génère le fichier HEX
// 🔄 Convertis le binaire en HEX
// 📲 Programme la puce directement via ta carte Arduino
// 📡 Utilise un logiciel de terminal série pour voir les caractères transmis
// 📟 Observe les LEDs s'allumer en fonction des caractères reçus
