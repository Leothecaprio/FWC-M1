#include <Arduino.h>

int D, C, B, A;

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A); // LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D); // MSB
}

void setup() {
  for (int i = 2; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(13, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) { // Loop through 0 to 9
    digitalWrite(13, HIGH);
    delay(1000);

    disp_7447((i & 0b1000) >> 3, (i & 0b0100) >> 2, (i & 0b0010) >> 1, (i & 0b0001));
    
    digitalWrite(13, LOW);
    delay(100);
  }
}