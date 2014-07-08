#include "Drive.h"

//TODO: Ensure Motor pins are correct and are set in the correct direction


Drive::Drive (int right_motor_pin1, int right_motor_pin2, int right_motor_control_pin,
			  int left_motor_pin1, int left_motor_pin2, int left_motor_control_pin)
{
	_right = Motor (right_motor_pin1, right_motor_pin2, right_motor_control_pin);
	_left = Motor (left_motor_pin1, left_motor_pin2, left_motor_control_pin);
}

void Drive::forward (int speed)
{
	_left.forward (speed);
	_right.forward (speed);
	delay (500);
	stop ();
}

void Drive::backward (int speed)
{
	_left.backward (speed);
	_right.backward (speed);
	delay (500);
	stop ();
}

void Drive::stop (void)
{
	_left.stop();
	_right.stop();
}

void Drive::rotate_ccw (void)
{
	_left.backward (255 / 2);
	_right.forward (255 / 2);
	delay (500);
	stop ();
}

void Drive::rotate_cw (void)
{
	_left.forward (255 / 2);
	_right.backward (255 / 2);
	delay (500);
	stop ();
}

void Drive::left (int speed)
{
	_left.forward (speed / 2);
	_right.forward (speed);
	delay (500);
	stop ();
}

void Drive::right (int speed)
{
	_left.forward (speed);
	_right.forward (speed / 2);
	delay (500);
	stop ();
}