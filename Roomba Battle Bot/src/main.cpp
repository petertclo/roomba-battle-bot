#include "Arduino.h"
#include "motors.h"
#include "potentiometer.h"


void setup() {
  // Set the pin modes for motors as OUTPUT
  int motorPins [8] = {E1, E2, E3, E4, M1, M2, M3, M4}; 

  for (int i = 0; i < (sizeof motorPins / sizeof *motorPins); i++) {
    pinMode(motorPins[i], OUTPUT);
  }

}


void loop() {
  
}