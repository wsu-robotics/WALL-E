#ifndef MOTOR
#define MOTOR

#include "Arduino.h"

class Motor
{
private:
	int _pin1;
	int _pin2;
	int _control_pin;
	void initMotor ();
	
public:
	Motor (int pin1, int pin2, int control)
	{
		_pin1 = pin1;
		_pin2 = pin2;
		_control_pin = control;
		initMotor ();
	}
	void forward (int speed);
	void backward (int speed);
	void stop ();
};
#endif