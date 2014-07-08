/*
 *	This is the Main Drive class for the WALL-E Robot
 *
 */

#ifndef DRIVE_H
#define DRIVE_H

#include "Motor.h"

class Drive
{
 public:
   Drive (int right_motor_pin1, int right_motor_pin2, int right_motor_control_pin,
		  int left_motor_pin1, int left_motor_pin2, int left_motor_control_pin);
   void forward (int speed);
   void backward (int speed);
   void stop (void);
   void right (int speed);
   void left (int speed);
   void rotate_ccw (void);
   void rotate_cw (void);
 private:
   Motor _right;
   Motor _left;
};

#endif
