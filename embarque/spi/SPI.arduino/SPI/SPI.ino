
#include <SPI.h>

const int CS_PIN = 10;  // Chip Select
SPISettings mySetting(1000000, MSBFIRST, SPI_MODE0);  // SPI Mode 3

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Attendre que le port série soit prêt (utile sur Leonardo/Micro)

  SPI.begin();
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);  // Désactiver l'esclave
}

void loop() {
  
    int8_t receivedChar = 0x4;  // Lire le caractère entré dans le moniteur série

    SPI.beginTransaction(mySetting);

    digitalWrite(CS_PIN, LOW);                        // Activer l'esclave
    int8_t retour = SPI.transfer(receivedChar);       // Transfert SPI
    digitalWrite(CS_PIN, HIGH);                       // Désactiver l'esclave

    SPI.endTransaction();
    
    // Affichage retour (utile pour debug ou si un esclave répond)
    Serial.print("Caractère envoyé : ");
    Serial.write(receivedChar);
    Serial.print(" | Reçu : ");
    Serial.println(retour, HEX);

    delay(100);  // Pause pour éviter le spam
  
}



/*
#include <SPI.h>
const int CS_PIN = 10;
void setup() {
pinMode(CS_PIN, OUTPUT);  
digitalWrite(CS_PIN, HIGH); // Ensure CS pin is high

//SPSR = (1 << SPI2X);                                         // Set double speed for fck/8
SPCR |= (1 << CPOL) | (1 << CPHA);                           // Set clock polarity and phase (Mode 3)
}


// SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); // 1 MHz, MSB first, Mode 0

void loop() {
  uint8_t data=0x2;
  SPCR = (1 << DORD) | (1 << SPE) | (1 << MSTR) | ( 1 << SPR0); // Enable SPI, set as master, set clock rate fck/16
  SPSR = (1 << SPI2X);
  SPI_transfer(data);
  SPCR &= ~(1 << SPE); // Disable SPI   // SPI.endTransaction();
}
  
  uint8_t SPI_transfer(uint8_t data)
 
    {
    SPDR = data; // Start transmission by writing data to SPDR
    while (!(SPSR & (1 << SPIF)))
        ;        // Wait for transmission to complete
    //return SPDR; // Return received data

    }

*/