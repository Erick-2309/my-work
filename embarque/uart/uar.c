#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
// #define BLINK_DELAY 2000000 // to avoid passing a value
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
                         RXENn = 1;   // Enable Receiver
                         
                         //
                         UBRRn = 103; // 9600 Baud rate at 16MHz
                         */
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

void recevoir(char *c)
{
    while (!(UCSR0A & (1 << RXC0)))
        ;      // Wait for data to be received
    *c = UDR0; // Get and return received data from buffer
}
int main(void)
{
    UBRR0H = 0;
    UBRR0L = 103; 

    UCSR0C = (0 << UMSEL01) | (0 << UMSEL00) | // Asynchronous mode
             (0 << UPM01) | (0 << UPM00) |     // No parity
             (1 << USBS0) |                    // 2 stop bits
             (1 << UCSZ01) | (1 << UCSZ00);    // 8 data bits

    // Enable transmitter (TX)
    UCSR0B = (1 << RXEN0); // Enable RX

    // initialisation port LEDs
    // DDRB = 0x20;  // 0x20 = 0b00100000, bit 5 à 1, les autres à 0
    // DDRD = 0xC0;  // 0xC0 = 0b11000000, bits 7 et 6 à 1, les autres à 0

    // PORTB = 0x00; // Tous les bits de PORTB à 0, LED éteinte
    // PORTD = 0x00; // Tous les bits de PORTD à 0, LEDs éteintes

    DDRB |= (1 << 5); // Met le bit 5 en sortie sans toucher aux autres bits
    DDRD |= (1 << 6) | (1 << 7);

    char c;

    while (1)
    {
        recevoir(&c);

        if (c == 'A')
        {
            PORTB |= (1 << PB5);
            _delay_ms(2000);
            PORTB &= ~(1 << PB5);
            _delay_ms(2000);
        }

        else if (c == 'B')
        {
            PORTD |= (1 << PD7);
            _delay_ms(2000);
            PORTD &= ~(1 << PD7);
            _delay_ms(2000);
        }
        else if (c == 'C')
        {
            PORTD |= (1 << PD6);
            _delay_ms(2000);
            PORTD &= ~(1 << PD6);
            _delay_ms(2000);
        }
    }

    return 0;
}

/*
while (1)
    {
        while (!(UCSR0A & (1 << RXC0)))
            ;
        char received = UDR0;
        if (received == 'A')
        {
            PORTB |= (1 << 5); // OU *PORTB =0x20; // LED on
            _delay_ms(200);
            PORTB = 0x00; // LED off
            _delay_ms(200);
        }
        if (received == 'B')
        {
            PORTD = 0x80; // LED on
            _delay_ms(200);
            PORTD = 0x00; // LED off
            _delay_ms(200);
        }
        if (received == 'C')
        {
            PORTD = 0x40; // LED on
            _delay_ms(200);
            PORTD = 0x00; // LED off
            _delay_ms(200);
        }
    }
*/
