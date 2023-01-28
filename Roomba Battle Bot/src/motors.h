#ifndef MOTORS_H
#define MOTORS_H

// Constants for Motor Directions
#define M1 4
#define M2 12
#define M3 8 
#define M4 7

// Constants for Motor Speed (Pulse Width Modulation (PMW) pin codes) 
#define E1 3
#define E2 11
#define E3 5 
#define E4 6

#define VELOCITY_DEAD_ZONE_WIDTH 10
#define DIRECTION_DEAD_ZONE_WIDTH 5

#define MAX_SPEED 255
#define MAX_DIRECTION 255

// Constants for potentiometer pins
#define POTENTIOMETER_PIN_FOR_M1 A0
#define POTENTIOMETER_PIN_FOR_M2 A1

// Indecies for velocity and direction
#define VELOCITY_INDEX 4
#define DIRECTION_INDEX 5

void M1_advance(int speed);
void M2_advance(int speed);

void M1_reverse(int speed);
void M2_reverse(int speed);

void M1_move(int mappedData);
void M2_move(int mappedData);

void moveMotorsWithVelocityAndAngles(int velocity, int mappedAngle);

#endif /* MOTORS_H */