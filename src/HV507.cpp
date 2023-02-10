/*
  HV507.cpp - Library for the Microchip HV507 low voltage serial to high voltage parallel converter.
  Created by Joe Hill, February 10, 2023.
  Released into the public domain.
*/

#include "HV507.h"
#include "Arduino.h"

HV507::HV507()
{
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(blankPin, OUTPUT);
    pinMode(polarityPin, OUTPUT);
    pinMode(directionPin,OUTPUT);

    digitalWrite(dataPin, data);
    digitalWrite(clockPin, clock);
    digitalWrite(latchPin, latch);
    digitalWrite(blankPin, blank);
    digitalWrite(polarityPin, polarity);
    digitalWrite(directionPin, direction);
}

// move a single bit into the HV507 Shift Register
void HV507::loadBitToRegister(bool dataBit)
{
    digitalWrite(blankPin, LOW);

    digitalWrite(latchPin, LOW);
    digitalWrite(clockPin, LOW); // Set clock pin low ready for a rising edge

    digitalWrite(dataPin, dataBit);
    Serial.print(dataBit);

    digitalWrite(clockPin, HIGH); // Data is loaded into S/R on the rising edge
}

// move an array of bits into the HV507 Shift Register
void HV507::loadArrayToRegister(bool dataArray[64])
{
    digitalWrite(blankPin, LOW);
    digitalWrite(latchPin, LOW);    // latch to store data in S/R

    for(int n = 0; n <= 63; n++) {  // Send data from dataArray over serial per byte
        digitalWrite(clockPin, LOW); // Set clock pin low ready for a rising edge

        int data = dataArray[n];
        digitalWrite(dataPin, data);
        
        digitalWrite(clockPin, HIGH); // Data is loaded into S/R on the rising edge
    }
}

// load the values in the shift register to the high-voltage output
void HV507::loadRegisterToOutput()
{
    digitalWrite(latchPin, HIGH); // Unlatch to move data from S/R to HV outputs
    digitalWrite(latchPin, LOW);  // Relatch to store data in the S/R
}

void HV507::allOutputsLow()
{
    digitalWrite(blankPin, LOW);
    digitalWrite(polarityPin, LOW);
}

void HV507::allOutputsHigh()
{
    digitalWrite(blankPin, LOW);
    digitalWrite(polarityPin, HIGH);
}