#include "Arduino.h"
#include "motors.h"
#include "receiver.h"
#include <VirtualWire.h>

#define MAX_SPEED 255
#define MAX_ANGLE 255
#define MIN_POTENTIOMETER_VAL 0
#define MAX_POTENTIOMETER_VAL 255
#define DEAD_ZONE_WIDTH 10

unsigned long previousTime = millis();
long timeInterval = 800;

void setup() {
  // For debugging purposes
  Serial.begin(9600);
  Serial.println("setup");

  pinMode(LED_BUILTIN, OUTPUT);

  // Set the pin modes for motors as OUTPUT
  int motorPins [8] = {E1, E2, E3, E4, M1, M2}; 

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
  unsigned long currentTime = millis();
  // Reference: https://www.pjrc.com/teensy/td_libs_VirtualWire.html 
  // https://www.electronics-lab.com/project/using-433mhz-rf-transmitter-receiver-arduino/ 

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  digitalWrite(LED_BUILTIN, HIGH);

  vw_wait_rx_max(1000);

  if (vw_get_message(buf, &buflen)) 
  { // Non-blocking
    if (buf[0] == PASS_0 && buf[1] == PASS_1 && buf[2] == PASS_2 && buf[3] == PASS_3) 
    {
      int velocity = map(buf[VELOCITY_INDEX], MIN_POTENTIOMETER_VAL, MAX_POTENTIOMETER_VAL, MAX_SPEED, -MAX_SPEED);
      int angle = map(buf[ANGLE_INDEX], MIN_POTENTIOMETER_VAL, MAX_POTENTIOMETER_VAL, MAX_ANGLE, -MAX_ANGLE);

      Serial.print("VELOCITY: ");
      Serial.print(velocity);
      Serial.print(", ANGLE: ");
      Serial.print(angle);
      Serial.println();

      moveMotorsWithVelocityAndAngles(velocity, angle);

      Serial.print("Time since last message: ");
      Serial.println(millis() - previousTime);

      previousTime = millis();
    }

  } 
  else if (millis() - currentTime > timeInterval)
  {
    
    moveMotorsWithVelocityAndAngles(0, 0);
  }

  
}