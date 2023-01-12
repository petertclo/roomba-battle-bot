#include <Arduino.h>
#include <VirtualWire.h>
#include "transmitter.h"
#include "potentiometer.h"

void setup() {

  Serial.begin(9600);
  Serial.println("setup");

  // Sets up the transmitter 
  vw_set_tx_pin(TRANSMIT_PIN);
  vw_setup(BITS_PER_SECOND);
  // vw_set_ptt_pin(TRANSMIT_ENABLE_PIN);

  pinMode(LED_BUILTIN, OUTPUT);

}


void loop() {
  // Reference: https://www.pjrc.com/teensy/td_libs_VirtualWire.html 

  // Reads the potentiometers for Motors 1 and 2
  // int mappedDataForM1 = readPotentiometer(POTENTIOMETER_PIN_FOR_M1);
  // int mappedDataForM2 = readPotentiometer(POTENTIOMETER_PIN_FOR_M2);
  // int mappedDataForMotors[] = {mappedDataForM1, mappedDataForM2};

  byte mappedDataForMotors[] = {100, 200};

  Serial.print("Transmitter sent a message: ");


  // mappedDataForMotors[0] = (i + 1) * 100 * pow(-1, i);
  // mappedDataForMotors[1] = (i + 1) * 100 * pow(-1, i);

  // if (i == 1) {
  //   mappedDataForMotors[1] = mappedDataForMotors[1] * -1;
  // }

  // The LED light is flashed on and off to indicate data transmission
  digitalWrite(LED_BUILTIN, HIGH);

  // Sends the speed and direction info about Motors 1 and 2
  Serial.println(vw_send(mappedDataForMotors, 2));
  vw_wait_tx();

  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  

  // Serial.println("World");
  // delay(1000);

  
}