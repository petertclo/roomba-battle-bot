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

// Indecies for motors
#define M1_INDEX 0
#define M2_INDEX 1

#define ANGLE_DEAD_ZONE_WIDTH 10

#define MAX_MOTOR_SPEED 255

// Constants for potentiometer pins
#define POTENTIOMETER_PIN_FOR_M1 A0
#define POTENTIOMETER_PIN_FOR_M2 A1

// Indecies for velocity and angle
#define VELOCITY_INDEX 0
#define ANGLE_INDEX 1

// Declarations; Tells the compiler that the functions exist somewhere 
void M1_advance(int speed);
void M2_advance(int speed);

void M1_reverse(int speed);
void M2_reverse(int speed);

void M1_move(int mappedData);
void M2_move(int mappedData);

void moveMotorsWithVelocityAndAngles(int velocity, int mappedAngle);

#endif /* MOTORS_H */