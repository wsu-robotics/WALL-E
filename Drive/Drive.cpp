#include "Drive.h"
#include "Arduino.h"

Drive::Drive (int pin1, int pin2)
{
	pinMode (pin1, OUTPUT);
	pinMode (pin2, OUTPUT);
	_pin1 = pin1;
	_pin2 = pin2;
}

void Drive::forward ()
{
	analogWrite (_pin1, 150);
	analogWrite (_pin2, 150);
	delay (500);
	analogWrite (_pin1, 0);
	analogWrite (_pin2, 0);
}

void Drive::backward ()
{
	//Somehow need to get a negative voltage to go backward
	analogWrite (_pin1, 150);
	analogWrite (_pin2, 150);
	delay (500);
	analogWrite (_pin1, 0);
	analogWrite (_pin2, 0);
}

void Drive::left ()
{
	analogWrite (_pin1, 150);
	delay (500);
	analogWrite (_pin1, 0);
}

void Drive::right ()
{
	analogWrite (_pin2, 150);
	delay (500);
	analogWrite (_pin2, 0);
}
