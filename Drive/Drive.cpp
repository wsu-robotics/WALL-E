#include "Drive.h"
#include "Arduino.h"

/*
*	TODO: Ensure Motor pins are correct and are set in the correct direction
*/

Drive::Drive (int right_motor_pin1, int right_motor_pin2, int right_motor_control_pin,
			  int left_motor_pin1, int left_motor_pin2, int left_motor_control_pin)
{
	pinMode (right_motor_pin1, OUTPUT);
	pinMode (right_motor_pin2, OUTPUT);
	pinMode (right_motor_control_pin, OUTPUT);
	pinMode (left_motor_pin1, OUTPUT);
	pinMode (left_motor_pin2, OUTPUT);
	pinMode (left_motor_control_pin, OUTPUT);
	_left_pin1 = left_motor_pin1;
	_left_pin2 = left_motor_pin2;
	_left_control_pin = left_motor_control_pin;
	_right_pin2 = right_motor_pin1;
	_right_pin1 = right_motor_pin2;
	_right_control_pin = right_motor_control_pin;
	
	//These lines ensure that the motors can move
	//To disable the motors set these to low
	digitalWrite(_left_control_pin, HIGH);
	digitalWrite(_right_control_pin, HIGH);
}

void Drive::forward ()
{
	digitalWrite (_left_pin1, HIGH);
	digitalWrite (_right_pin1, HIGH);
	delay (500);
	digitalWrite (_left_pin1, LOW);
	digitalWrite (_right_pin1, LOW);
}

void Drive::backward ()
{
	digitalWrite (_left_pin2, HIGH);
	digitalWrite (_right_pin2, HIGH);
	delay (500);
	digitalWrite (_left_pin2, LOW);
	digitalWrite (_right_pin2, LOW);
}

void Drive::left ()
{
	digitalWrite (_left_pin2, HIGH);
	digitalWrite (_right_pin1, HIGH);
	delay (500);
	digitalWrite (_left_pin2, LOW);
	digitalWrite (_right_pin1, LOW);
}

void Drive::right ()
{
	digitalWrite (_left_pin1, HIGH);
	digitalWrite (_right_pin2, HIGH);
	delay (500);
	digitalWrite (_left_pin1, LOW);
	digitalWrite (_right_pin2, LOW);
}
