# Microchip HV507 Arduino Library Documentation

This library is a work in progress and may not include all functionality needed for every project as the uses for this IC appear to be extremely varied. This library will allow the basic functionallity of the IC to be easily used.
<br />
<br />  

    HV507()

This initialises each pin as an output then writes the initial values to each pin.
<br />
<br />

    loadBitToRegister(bool dataBit)

Load a single bit into the shift register of the HV507.
<br />
<br />

    loadArrayToRegister(bool dataArray[64])

Load an array of 64 bits into the shift register of the HV507.  
<br />
<br />

    loadRegisterToOutput()

Load the values in the shift register to the outputs of the HV507.  
<br />
<br />

    allOutputsLow()

Set the value of all HV507 outputs to low.  
<br />
<br />

    allOutputsHigh()

Set the value of all HV507 outputs to High.  