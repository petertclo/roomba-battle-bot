#include <Arduino.h>
#include <VirtualWire.h>
#include "transmitter.h"
#include "potentiometer.h"

void setup() {
  // Debugging purposes
  Serial.begin(9600);
  Serial.println("setup");

  // Sets up the transmitter 
  vw_set_tx_pin(TRANSMIT_PIN);

  // Although a receiver is not part of a controller, setting the receiver pin prevents VirtualWire from using its default pin
  vw_set_rx_pin(RECEIVE_PIN); 

  vw_setup(BITS_PER_SECOND);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  // Reference: https://www.pjrc.com/teensy/td_libs_VirtualWire.html 
  // Reference: https://forum.arduino.cc/t/virtualwire-integer-sending/76650/9 

  // Reads velocity and direction data from two linear potentiometers from the controller
  uint8_t potentiometerDataForVelocity= readPotentiometerMappedToByte(POTENTIOMETER_PIN_FOR_VELOCITY);
  uint8_t potentiometerDataForDirection = readPotentiometerMappedToByte(POTENTIOMETER_PIN_FOR_DIRECTION);

  uint8_t potentiometerDataForMotors[] = {PASS_0, PASS_1, PASS_2, PASS_3, potentiometerDataForVelocity, potentiometerDataForDirection};

  // Print statements for debugging purposes
  Serial.print("Transmitter sent a message: ");
  Serial.print("VELOCITY: ");
  Serial.print(potentiometerDataForMotors[VELOCITY_INDEX]);
  Serial.print(", DIRECTION: ");
  Serial.print(potentiometerDataForMotors[ANGLE_INDEX]);
  Serial.println();

  // The LED light is flashed on and off to indicate data transmission
  digitalWrite(LED_BUILTIN, HIGH);

  // Sends 4 predetermined passcodes, velocity, and direction data 
  vw_send((uint8_t *) potentiometerDataForMotors, sizeof(potentiometerDataForMotors));
  vw_wait_tx();

  // Prints out the time it took to send the data
  Serial.print(millis() - currentTime);

  digitalWrite(LED_BUILTIN, LOW);
}