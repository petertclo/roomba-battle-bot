#ifndef POTENTIOMETER_H

// Change the A0 and A1 appropriately 
#define POTENTIOMETER_PIN_FOR_M1 A0
#define POTENTIOMETER_PIN_FOR_M2 A1

uint8_t readPotentiometerMappedToByte(int pin);

#endif