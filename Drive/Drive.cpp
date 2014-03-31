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

void Drive::forward (int speed)
{
	analogWrite (_left_pin1, speed);
	analogWrite (_right_pin1, speed);
}

void Drive::backward (int speed)
{
	analogWrite (_left_pin2, speed);
	analogWrite (_right_pin2, speed);
}

void Drive::rotate_ccw ()
{
	analogWrite (_left_pin2, 123);
	analogWrite (_right_pin1, 123);
	delay (500);
	analogWrite (_left_pin2, 0);
	analogWrite (_right_pin1, 0);
}

void Drive::rotate_cw ()
{
	analogWrite (_left_pin1, 123);
	analogWrite (_right_pin2, 123);
	delay (500);
	analogWrite (_left_pin1, 0);
	analogWrite (_right_pin2, 0);
}

void Drive::left (int speed)
{
	analogWrite (_right_pin1, speed);
}

void Drive::right (int speed)
{
	analogWrite (_left_pin1, speed);
}