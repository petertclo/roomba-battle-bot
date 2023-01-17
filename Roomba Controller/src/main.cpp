#include <Arduino.h>
#include <VirtualWire.h>
#include "transmitter.h"
#include "potentiometer.h"

void setup() {

  Serial.begin(9600);
  Serial.println("setup");

  // Sets up the transmitter 
  vw_set_tx_pin(TRANSMIT_PIN);

  // Although a receiver is not part of a controller, setting the receiver pin is a good idea to avoid VirtualWire using its default pin
  vw_set_rx_pin(RECEIVE_PIN); 
  vw_setup(BITS_PER_SECOND);
  // vw_set_ptt_pin(TRANSMIT_ENABLE_PIN);

  pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(ANTENNA_PIN, OUTPUT);

}


void loop() {
  // Reference: https://www.pjrc.com/teensy/td_libs_VirtualWire.html 
  // Reference: https://forum.arduino.cc/t/virtualwire-integer-sending/76650/9 

  uint8_t potentiometerDataForVelocity= readPotentiometerMappedToByte(POTENTIOMETER_PIN_FOR_VELOCITY);
  uint8_t potentiometerDataForDirection = readPotentiometerMappedToByte(POTENTIOMETER_PIN_FOR_ANGLE);

  uint8_t potentiometerDataForMotors[] = {potentiometerDataForVelocity, potentiometerDataForDirection};

  Serial.print("Transmitter sent a message: ");
  Serial.print("VELOCITY: ");
  // Serial.print(mappedDataForMotors[0]);
  Serial.print(potentiometerDataForMotors[0]);

  Serial.print(", DIRECTION: ");
  // Serial.println(mappedDataForMotors[1]);
  Serial.print(potentiometerDataForMotors[1]);

  // The LED light is flashed on and off to indicate data transmission
  digitalWrite(LED_BUILTIN, HIGH);

  // TODO: https://forum.arduino.cc/t/virtualwire-integer-sending/76650/9 Might be helpful
  vw_send((uint8_t *) potentiometerDataForMotors, sizeof(potentiometerDataForMotors));

  Serial.println();
  vw_wait_tx();

  digitalWrite(LED_BUILTIN, LOW);
}