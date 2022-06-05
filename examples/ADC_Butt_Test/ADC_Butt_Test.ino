#include <ADCButtons.h>

ADCButtons button(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte b = button.get();
  char k = button.getKeyChar();
  if (b != 0) {
    Serial.print(b);
    Serial.print("  ");
    Serial.println(k);
  }
}