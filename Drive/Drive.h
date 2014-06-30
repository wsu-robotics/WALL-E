/*
 *	This is the Main Drive class for the WALL-E Robot
 *
 * */


#ifndef DRIVE_H
#define DRIVE_H

#include "Arduino.h"

class Drive
{
 public:
   Drive (int right_motor_pin1, int right_motor_pin2, int right_motor_control_pin,
		  int left_motor_pin1, int left_motor_pin2, int left_motor_control_pin);
   void forward (int speed);
   void backward (int speed);
   void motorStop (void);
   void right (int speed);
   void left (int speed);
   void rotate_ccw (void);
   void rotate_cw (void);
   void enable (void);
 private:
   int _left_pin1;
   int _left_pin2;
   int _left_control_pin;
   int _right_pin1;
   int _right_pin2;
   int _right_control_pin;
};

#endif
