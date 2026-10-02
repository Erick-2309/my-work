#include <Arduino.h>

#define N 64               // Nombre de coefficients
#define SCALING_FACTOR 16384 // 2^14 pour revenir à Q(16,0)

// Coefficients en Q(16,14)
int16_t fixed_point_coef[N] = {
  -5793, -18755, 4594, -1676, 1906, -1619, -496, 2832, -2327, -1635, 5068, -3111, -3597, 7837, -3400, -6429,
  10659, -2805, -9959, 13060, -1185, -13749, 14549, 1394, -17309, 14797, 4703, -20049, 13694, 8195, -21557, 11360,
  11360, -21557, 8195, 13694, -20049, 4703, 14797, -17309, 1394, 14549, -13749, -1185, 13060, -9959, -2805, 10659,
  -6429, -3400, 7837, -3597, -3111, 5068, -1635, -2327, 2832, -496, -1619, 1906, -1676, 4594, -18755, -5793
};

// Tampon circulaire pour les échantillons d'entrée (Q16,0)
int16_t buffer[N] = {0};
uint8_t buffer_index = 0; 

int n = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Signal sinusoïdal généré par GBF 
  int16_t input=analogRead(A0);
  int16_t center=input-512;

  // Ajoute l'entrée au tampon
  buffer[buffer_index] = input;  // Q(16,0)

  // Appliquer le filtre FIR
  int32_t acc = 0;
  for (uint8_t i = 0; i < N; i++) {
    uint8_t index = (buffer_index + N - i) % N; // Index circulaire
    acc += (int32_t)buffer[index] *fixed_point_coef[i]; // Résultat Q(26,14) donc  Q(32,14)
  }

  // Mise à l’échelle (division par 2^14) pour revenir à Q(16,0)
  int16_t output =(acc >> 14);

  // Affichage
  Serial.print("x[n] = ");
   Serial.println(output);
  Serial.print(", y[n] = ");
 
  Serial.print(input);

  // Mettre à jour l'index du tampon
  buffer_index = (buffer_index + 1) % N;
 
  delay(100);
}

