
#include <SPI.h>

const int CS_PIN = 10;  // Chip Select
SPISettings mySetting(1000000, MSBFIRST, SPI_MODE3);  // SPI Mode 3

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Attendre que le port série soit prêt (utile sur Leonardo/Micro)

  SPI.begin();
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);  // Désactiver l'esclave
}

void loop() {
  
    int8_t receivedChar = 0x2;  // Lire le caractère entré dans le moniteur série

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
