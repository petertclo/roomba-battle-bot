#ifndef POTENTIOMETER_H

// Pins for two potentiometers: one for velocity and another for direction
#define POTENTIOMETER_PIN_FOR_VELOCITY A0
#define POTENTIOMETER_PIN_FOR_DIRECTION A1

uint8_t readPotentiometerMappedToByte(int pin);

#endif