#include <HV507.h>

HV507 hv(21, 25, 18, 32, 19, 33);

void setup() {
  Serial.begin(9600);
  Serial.println("HV507 bit load test");
}

void loop() {
  hv.loadBitToRegister(1);
  hv.loadRegisterToOutput();
}