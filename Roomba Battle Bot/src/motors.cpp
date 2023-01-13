#include "Arduino.h"
#include "motors.h"

// Reference: https://wiki.dfrobot.com/Quad_Motor_Driver_Shield_for_Arduino_SKU_DRI0039#target_2 

// Foward movement
void M1_advance(int speed) ///<Motor1 Advance
{
  digitalWrite(M1,LOW);
  analogWrite(E1,speed);
}


void M2_advance(int speed) ///<Motor2 Advance
{
  digitalWrite(M2,HIGH);
  analogWrite(E2,speed);
}

// Backward movement
void M1_reverse(int speed) ///<Motor1 Back off
{
  digitalWrite(M1,HIGH);
  analogWrite(E1,speed);
}


void M2_reverse(int speed) ///<Motor2 Back off
{
  digitalWrite(M2,LOW);
  analogWrite(E2,speed);
}

// General movement (forward + backward)

/* int mappedData: An integer value within [-255, 255] used for determining
                   a direction and speed of a motor.
*/        
void M1_move(int mappedData) {
    int speed = abs(mappedData);

    if (mappedData >= 0) 
    {
        M1_advance(speed);
    }
    else
    {
        M1_reverse(speed);
    }
}


void M2_move(int mappedData) {
    int speed = abs(mappedData);

    if (mappedData >= 0) 
    {
        M2_advance(speed);
    }
    else
    {
        M2_reverse(speed);
    }
}


void moveMotorsWithVelocityAndAngles(int velocity, int mappedAngle) {
  int velocityM1 = velocity;
  int velocityM2 = velocity;

  if (abs(mappedAngle) <= ANGLE_DEAD_ZONE_WIDTH)
  {
    mappedAngle = 0;
  }

  if (mappedAngle <= 0) 
  {
    velocityM2 = velocityM2 + abs(mappedAngle);
  } else 
  {
    velocityM1 = velocityM1 + abs(mappedAngle);
  }

  M1_move(velocityM1);
  M2_move(velocityM2);
}
