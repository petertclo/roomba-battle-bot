#include "Arduino.h"
#include "motors.h"
#include "receiver.h"
#include <VirtualWire.h>

#define MAX_SPEED 255
#define MIN_POTENTIOMETER_VAL 0
#define MAX_POTENTIOMETER_VAL 255
#define DEAD_ZONE_WIDTH 10

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

  vw_set_tx_pin(TRANSMIT_PIN);

  vw_setup(BITS_PER_SECOND);
  vw_rx_start();

}


void loop() {
  // Reference: https://www.pjrc.com/teensy/td_libs_VirtualWire.html 
  // https://www.electronics-lab.com/project/using-433mhz-rf-transmitter-receiver-arduino/ 

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  digitalWrite(LED_BUILTIN, HIGH);

  // Serial.print("Received a message: ");

  // vw_wait_rx_max(1000);

  // if (vw_get_message(buf, &buflen)) { // Non-blocking

  //   // Serial.print("Got: ");
  //   // Serial.print(buf[M1_INDEX]);
  //   // Serial.print(' ');
  //   // Serial.print(buf[M2_INDEX]);
  //   // Serial.print(' ');

  //   int velocityM1 = map(buf[M1_INDEX], MIN_POTENTIOMETER_VAL, MAX_POTENTIOMETER_VAL, -MAX_SPEED, MAX_SPEED);
  //   int velocityM2 = map(buf[M2_INDEX], MIN_POTENTIOMETER_VAL, MAX_POTENTIOMETER_VAL, -MAX_SPEED, MAX_SPEED);

  //   Serial.println();
  //   Serial.print("Velocities: ");
  //   Serial.print(velocityM1);
  //   Serial.print(' ');
  //   Serial.print(velocityM2);
  //   Serial.println();

  //   if (abs(velocityM1) <= DEAD_ZONE_WIDTH) {
  //     velocityM1 = 0;
  //   } else if (abs(velocityM2) <= DEAD_ZONE_WIDTH) {
  //     velocityM2 = 0;
  //   }

  //   M1_move(velocityM1);
  //   M2_move(velocityM2);

  //   Serial.println();

  //   digitalWrite(LED_BUILTIN, LOW);
  // }


  moveMotorsWithVelocityAndAngles(100, -30);
  delay(1000);
  moveMotorsWithVelocityAndAngles(50, -20);
  delay(1000);
  moveMotorsWithVelocityAndAngles(0, 0);
  delay(1000);
  moveMotorsWithVelocityAndAngles(50, 20);
  delay(1000);
  moveMotorsWithVelocityAndAngles(100, 30);
  delay(1000);

  // M1_move(100);
  // M2_move(-100);
  // M2_reverse(100);
  // Serial.println("hello");
  // delay(500);
}