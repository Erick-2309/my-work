
#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

volatile int eventCounter = 0;
volatile bool eventFlag = false;

// Routine d'interruption pour INT0 (PD2)
ISR(INT0_vect)
{
    eventCounter++;
    eventFlag = true;
}

void setup()
{
    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, INPUT);

    cli(); // Désactiver interruptions globales

    // Configurer INT0 (PD2) pour front montant
    EICRA |= (1 << ISC01) | (1 << ISC00); // front montant
    EIMSK |= (1 << INT0);                 // activer INT0
    EIFR |= (1 << INTF0);                 // effacer tout flag en attente

    sei(); // Réactiver interruptions globales

    Serial.println("Interruption INT0 configurée !");
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    if (eventFlag)
    {
        Serial.print("Détection: ");
        Serial.println(eventCounter);
        eventFlag = false;
    }
}

#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

volatile int eventCounter = 0;
volatile bool eventFlag = false;

// Routine d'interruption pour INT0 (broche D2 / PD2)
ISR(INT0_vect)
{
    eventCounter++;
    eventFlag = true;
}

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, INPUT);

    // Désactivation globale des interruptions
    SREG &= ~(1 << 7); // Efface le bit I (bit 7 du SREG) → désactive les interruptions globales
    Serial.print("SREG après désactivation (cli manuelle) : ");
    Serial.println(SREG, BIN);

    // Configuration de l’interruption externe INT0
    // Déclenchement sur front montant
    EICRA |= (1 << ISC01) | (1 << ISC00);
    Serial.println("EICRA configured for rising edge on INT0");
    Serial.print(EICRA, BIN);
    // Activation de INT0
    EIMSK |= (1 << INT0);
    Serial.println("EIMSK modified to enable INT0");
    Serial.print(EIMSK, BIN);
    // Effacement du flag d’interruption éventuel
    EIFR |= (1 << INTF0);
    Serial.println("EIFR modified to clear any pending INT0 interrupt");
    Serial.print(EIFR, BIN);

    Serial.print("EICRA : ");
    Serial.println(EICRA, BIN);
    Serial.print("EIMSK : ");
    Serial.println(EIMSK, BIN);
    Serial.print("EIFR : ");
    Serial.println(EIFR, BIN);

    // Réactivation globale des interruptions

    SREG |= (1 << 7); // Met le bit I à 1 → active les interruptions globales
    Serial.print("SREG après réactivation (sei manuelle) : ");
    Serial.println(SREG, BIN);

    Serial.println("Configuration de l'interruption INT0 terminée !");
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    if (eventFlag)
    {
        Serial.print("Détection : ");
        Serial.println(eventCounter);
        eventFlag = false;
    }
}

/*
volatile int eventCounter = 0;
volatile bool eventFlag = false;

void handleInterrupt()
{
    PORTB = 42; // Example effect
    eventCounter++;
    eventFlag = true;
}

ISR(INT0_vect)
{
    handleInterrupt();
}

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, INPUT); // INT0 on pin 2

    // Configure INT0 to trigger on rising edge
    EICRA |= (1 << ISC01) | (1 << ISC00); // Rising edge
    EIFR |= (1 << INTF0);                 // Clear pending interrupt
    EIMSK |= (1 << INT0);                 // Enable INT0
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    if (eventFlag)
    {
        Serial.print("Detection: ");
        Serial.println(eventCounter);
        eventFlag = false;
    }
}
*/