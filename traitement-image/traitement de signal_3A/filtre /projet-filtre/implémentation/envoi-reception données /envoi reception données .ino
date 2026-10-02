#include <Arduino.h>

const int N = 64;


int16_t b[64] = {
  -5793, -18755, 4594, -1676, 1906, -1619, -496, 2832, -2327, -1635, 5068, -3111, -3597, 7837, -3400, -6429,
  10659, -2805, -9959, 13060, -1185, -13749, 14549, 1394, -17309, 14797, 4703, -20049, 13694, 8195, -21557, 11360,
  11360, -21557, 8195, 13694, -20049, 4703, 14797, -17309, 1394, 14549, -13749, -1185, 13060, -9959, -2805, 10659,
  -6429, -3400, 7837, -3597, -3111, 5068, -1635, -2327, 2832, -496, -1619, 1906, -1676, 4594, -18755, -5793
}; //Q(16,14)

int16_t xn, yn;       // Q(16,6)
int16_t x_buffer[N] = {0};
int index = 0;
int32_t sum = 0;

void setup() {
  Serial.begin(9600);

  while (!Serial); // attendre que le port série soit prêt
}

void loop() {
  if (Serial.available() >= 2) {
    xn = Serial.read() | (Serial.read() << 8); // lecture little-endian

    x_buffer[index] = xn;

    for (int i = 0; i < N; i++) {
      int idx = (index - i + N) % N;
      sum += (int32_t)b[i] * x_buffer[idx];
    }

    sum = sum >> 11; // conversion Q(16,11) → Q(16,0)
    yn = (int16_t)sum;

    index = (index + 1) % N;

    // renvoyer le résultat (little endian)
    Serial.write((uint8_t)(yn & 0xFF));
    Serial.write((uint8_t)((yn >> 8) & 0xFF));
  }
}