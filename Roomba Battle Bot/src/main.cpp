#include "Arduino.h"
#include "motors.h"
#include "receiver.h"
#include <VirtualWire.h>


void setup() {

  // For debugging purposes
  Serial.begin(9600);
  Serial.println("setup");

  // Set the pin modes for motors as OUTPUT
  int motorPins [8] = {E1, E2, E3, E4, M1, M2, M3, M4}; 

  for (int i = 0; i < (sizeof motorPins / sizeof *motorPins); i++) {
    pinMode(motorPins[i], OUTPUT);
  }

  // Sets up the receiver on the robot
  vw_set_rx_pin(RECEIVE_PIN);
  vw_setup(BITS_PER_SECOND);
  vw_rx_start();

}


void loop() {
  // Reference: https://www.pjrc.com/teensy/td_libs_VirtualWire.html 

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) { // Non-blocking

    digitalWrite(LED_BUILTIN, HIGH);

    Serial.print("Got: ");

    for (int i = 0; i < buflen; i++) {
      Serial.print(buf[i]);
      Serial.print(' ');

      if (i == M1_INDEX) {
        M1_move((int) buf[i]);
      } else {
        M2_move((int) buf[i]);
      }
    }

    Serial.println();
    
    delay(100);

    digitalWrite(LED_BUILTIN, LOW);
  }
}