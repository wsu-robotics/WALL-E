#include "Motor.h"

void Motor::initMotor ()
{
	pinMode (_pin1, OUTPUT);
	pinMode (_pin2, OUTPUT);
	pinMode (_control_pin, OUTPUT);
	analogWrite (_control_pin, 255);
}

void Motor::forward (int speed)
{
	analogWrite (_control_pin, speed);
	digitalWrite (_pin1, HIGH);
}

void Motor::backward (int speed)
{
	analogWrite (_control_pin, speed);
	digitalWrite (_pin2, HIGH);	
}

void Motor::stop ()
{
	analogWrite (_control_pin, 0);
	digitalWrite (_pin1, LOW);
	digitalWrite (_pin2, LOW);
}