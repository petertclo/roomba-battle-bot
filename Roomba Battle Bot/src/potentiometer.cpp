#include "Arduino.h"
#include "potentiometer.h"

int readPotentiometer(int pin) {
    int data = analogRead(pin); // Reads value within [0, 1023]
    
    // Maps 0 to -255, 1023 to 255
    return map(data, 0, 1023, -255, 255);
}