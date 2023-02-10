/*
    loadArrayExample.cpp -  Example program to show loading data from an array into the shift register then loading this into the ouputs of the HV507 The outputs are then held low, then held high for a period.
    Created by Joe Hill, February 10, 2023.
    Released into the public domain.
*/

#include <HV507.h>

HV507 hv;

// some random arrays of 64 bits
bool arr1[64] = {1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1};
bool arr2[64] = {0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1};

void setup()
{
    Serial.begin(9600);
    Serial.println("HV507 array load test");
}

void loop()
{
    // array arr1  will be loaded into the shift register then loaded to the outputs of the HV507
    hv.loadArrayToRegister(arr1);
    Serial.println("arr1 is loaded into the Shift Register");
    hv.loadRegisterToOutput();
    delay(500);

    // array arr2  will be loaded into the shift register then loaded to the outputs of the HV507
    hv.loadArrayToRegister(arr2);
    Serial.println("arr2 is loaded into the Shift Register");
    hv.loadRegisterToOutput();
    delay(500);

    // set all outputs of the HV507 to low
    hv.allOutputsLow();
    Serial.println("All outputs of the HV507 set to low");
    delay(500);

    // set all outputs of the HV507 to high
    hv.allOutputsHigh();
    Serial.println("All outputs of the HV507 set to high");
    delay(500);
}