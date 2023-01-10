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

// Constants for potentiometer pins
#define POTENTIOMETER_PIN_FOR_M1 A0
#define POTENTIOMETER_PIN_FOR_M2 A1

// Declarations; Tells the compiler that the functions exist somewhere 
void M1_advance(char speed);
void M2_advance(char speed);

void M1_reverse(char speed);
void M2_reverse(char speed);

void M1_move();
void M2_move();

#endif /* MOTORS_H */