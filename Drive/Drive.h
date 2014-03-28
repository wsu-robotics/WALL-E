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
   Drive (int pin1, int pin2);
   void forward ();
   void backward ();
   void right ();
   void left ();
 private:
   int _pin1;
   int _pin2;
};

#endif
