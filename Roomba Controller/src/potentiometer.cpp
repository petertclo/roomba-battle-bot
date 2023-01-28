#include "Arduino.h"
#include "potentiometer.h"

uint8_t readPotentiometerMappedToByte(int pin) {
    /* Reads a value from a potentiometer at `pin`, and maps that value to the range [0, 255]. */
    int data = analogRead(pin); // Reads value within [0, 1023]
    
    // Maps 0 to 0, 1023 to 255
    return map(data, 0, 1023, 0, 255);
}