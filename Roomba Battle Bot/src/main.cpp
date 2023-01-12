#include "Arduino.h"
#include "motors.h"
#include "receiver.h"
#include <VirtualWire.h>


void setup() {
  // For debugging purposes
  Serial.begin(9600);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);

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
  // https://www.electronics-lab.com/project/using-433mhz-rf-transmitter-receiver-arduino/ 

  byte buf[VW_MAX_MESSAGE_LEN];
  byte buflen = VW_MAX_MESSAGE_LEN;

  digitalWrite(LED_BUILTIN, HIGH);

  Serial.print("Received a message: ");

  // vw_wait_rx();
  vw_wait_rx_max(1000);
  if (vw_get_message(buf, &buflen)) { // Non-blocking

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
    
    delay(1000);

    digitalWrite(LED_BUILTIN, LOW);
  }

  Serial.println(vw_have_message());

  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}