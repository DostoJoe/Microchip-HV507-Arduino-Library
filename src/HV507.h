/*
  HV507.h - Library for the Microchip HV507 low voltage serial to high voltage parallel converter.
  Created by Joe Hill, February 10, 2023.
  Released into the public domain.
*/

#ifndef HV507_h
#define HV507_h

#include "Arduino.h"

class HV507
{
    public:
        HV507(int dataPin, int clockPin, int latchPin, int blankPin, int polarityPin, int directionPin);
        void loadBitToRegister(bool dataBit);
        void loadArrayToRegister(bool dataArray[65]);
        void loadRegisterToOutput();
        void allOutputsLow();
        void allOutputsHigh();

        int data = 0;
        int clock = 0;
        int latch = 0;
        int blank = 1;
        int polarity = 1;
        int direction = 0;

        int dataPin;
        int clockPin;
        int latchPin;
        int blankPin;
        int polarityPin;
        int directionPin;
};

#endif