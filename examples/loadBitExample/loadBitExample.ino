/*
  loadBitExample.cpp - Example program to show loading data bit by bit into the shift register then loading this into the ouputs of the HV507.
  Created by Joe Hill, February 10, 2023.
  Released into the public domain.
*/

#include <HV507.h>

HV507 hv;

void setup()
{
    Serial.begin(9600);
    Serial.println("HV507 bit load test");
}

void loop()
{
    // two bits will be loaded into the shift register then loaded to the outputs of the HV507
    hv.loadBitToRegister(1);
    Serial.println("A 1 is loaded into the Shift Register");
    delay(500);

    hv.loadBitToRegister(0);
    Serial.println("A 0 is loaded into the Shift Register");
    delay(500);

    hv.loadRegisterToOutput();
}