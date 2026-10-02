// #include <Arduino.h>
#include <avr/io.h>

// Define SPI pins by register
// #define MOSI_PIN 11
// #define MISO_PIN 12
// #define SCK_PIN 13
// #define CS_PIN 10
// pinMode(MOSI_PIN, OUTPUT);
// pinMode(MISO_PIN, INPUT);
// pinMode(SCK_PIN, OUTPUT);
// pinMode(CS_PIN, OUTPUT);
/// digitalWrite(CS_PIN, HIGH); // Ensure CS pin is high
#define DDR_SPI DDRB // PIN 11, 12, 13 on Arduino Uno
#define DD_MOSI PB3  // PB3 // Pin 11 on Arduino Uno
#define DD_MISO PB4  // PB4 // Pin 12 on Arduino Uno
#define DD_SCK PB5   // PB5 // Pin 13 on Arduino Uno
#define DD_CS PB2    // PB2 // Pin 10 on Arduino Uno
#define CS PORTB2

void SPI_MasterInit(void)
{
    PORTB |= (1 << CS);                       // Set CS pin high
    DDR_SPI |= (1 << DD_CS);                  // Set CS pin as output pinMode(CS_PIN, OUTPUT);
    DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK); // Set MOSI and SCK as Output
    DDR_SPI &= ~(1 << DD_MISO);               // Set MISO as Input

    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // SPI actif, maître, F_CPU / 16
    SPCR &= ~(1 << SPR1);                          // Set clock rate fck/16
    SPSR &= ~(1 << SPI2X);                         // Disable double speed mode
    SPCR &= ~(1 << DORD);                          // Set data order to MSB first
    SPCR &= ~((1 << CPOL) | (1 << CPHA));          // Assure CPOL = 0, CPHA = 0
}

void SPI_MasterTransmit(char cData)
{
    /* Start transmission */
    SPDR = cData; // Load data into the buffer
    while (!(SPSR & (1 << SPIF)))
        ; /* Wait for transmission complete */
}
void SPI_end()
{
    SPCR &= ~(1 << SPE); // Disable SPI   // SPI.endTransaction();
}

char SPI_MasterReceive(void)
{
    SPDR = 0xFF; // Send dummy byte to receive data
    while (!(SPSR & (1 << SPIF)))
        ;        // Wait for reception complete
    return SPDR; // Return received data
}

void SPI_select()
{
    PORTB &= ~(1 << CS); // Set CS low to select the slave
}
void SPI_deselect()
{
    PORTB |= (1 << CS); // Set CS high to deselect the slave
}

// Example usage

int main(void)
{
    SPI_MasterInit();
    while (1)
    {
        SPI_MasterInit(); // Initialize SPI
        SPI_select();
        SPI_MasterTransmit(0xB); // Transmit data 11
        // char receivedData = SPI_MasterReceive(); // Receive data
        SPI_deselect();
        // Do something with receivedData
    }
    return 0;
}

/*
// Commands to compile and upload the code to an Arduino Uno (ATmega328P)

(base) admin@MacBook-Pro-de-Admin SPI % avr-gcc spi.c -mmcu=atmega328p -DF_CPU=16000000UL -Os -o spi
(base) admin@MacBook-Pro-de-Admin SPI % avr-objcopy -O ihex spi spi.hex
(base) admin@MacBook-Pro-de-Admin SPI % avrdude -V -F -c arduino -p atmega328p -P /dev/cu.usbmodem144301 -b 115200 -D -U flash:w:spi.hex:i
Reading 236 bytes for flash from input file spi.hex
Writing 236 bytes to flash
Writing | ################################################## | 100% 0.05 s
236 bytes of flash written
Avrdude done.  Thank you.
(base) admin@MacBook-Pro-de-Admin SPI %
*/