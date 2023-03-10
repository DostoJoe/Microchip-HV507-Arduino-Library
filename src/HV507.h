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
        HV507();
        void loadBitToRegister(bool dataBit);
        void loadArrayToRegister(bool dataArray[64]);
        void loadRegisterToOutput();
        void allOutputsLow();
        void allOutputsHigh();

        int data = 0;
        int clock = 1;
        int latch = 0;
        int blank = 1;
        int polarity = 1;
        int direction = 0;

        int dataPin = 21;
        int clockPin = 32;
        int latchPin = 25;
        int blankPin = 19;
        int polarityPin = 18;
        int directionPin = 33;
};

#endif