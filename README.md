# Microchip HV507 Arduino Library

This is a library for the HV507 low-voltage to high-voltage serial-to-parallel converter.

Written by Joe Hill for use in a high voltage electrotactile haptic feedback control circuit.

# Pin Addressing

Pin defaults are as shown below. Each pin assignment can be changed when initialising the HV507 or per variable

|     HV507 Pin     |   ESP32 pin #  |
| :----------------:| :------------: |
|      dataPin      |       21       |
|     clockPin      |       25       |
|     latchPin      |       18       |
|     blankPin      |       32       |
|    polarityPin    |       19       |
|   directionPin    |       33       |

Defaults values for the initialisation of each pin are as follows. If these values change, there may be unwanded effects.

|     HV507 Pin   | Default Value  |
| :--------------:| :------------: |
|       data      |       0        |
|      clock      |       0        |
|      latch      |       0        |
|      blank      |       1        |
|     polarity    |       1        |
|    direction    |       0        |