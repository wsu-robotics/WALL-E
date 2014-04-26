#define MOTOR1PIN1 4
#define MOTOR1PIN2 6
#define MOTOR1CONTROLPIN 5
#define MOTOR2PIN1 9
#define MOTOR2PIN2 11
#define MOTOR2CONTROLPIN 10

#include <Drive.h>

//Right motor pins then left
Drive drive (MOTOR1PIN1, MOTOR1PIN2, MOTOR1CONTROLPIN, MOTOR2PIN1, MOTOR2PIN2, MOTOR2CONTROLPIN);

char incomingByte;
int input, temp, last;
boolean neg;

void setup ()
{
	Serial.begin (9600);
	Serial.write ("Enabling Motors\n");
	analogWrite(MOTOR1CONTROLPIN, 255);
	Serial.write ("Motor 1 Enabled\n");
	analogWrite(MOTOR2CONTROLPIN, 255);
	Serial.write ("Motor 2 Enabled\n");
	drive.motorStop ();
}

void loop ()
{
  //Drive Code
	if (Serial.available () > 0)
	{
		input = 0;
		while (true)
		{
			incomingByte = Serial.read ();
			if (incomingByte == '\n') break;
			if (incomingByte == 45)
			{
				neg = true;
				continue;
			}
			if (incomingByte == -1) continue;
			else 
			{
				input *= 10;
				input += incomingByte - 48; //48 is ASCII value of 0
			}
			// Maximum value for input is 32768
		}
		if (neg) {input = -input;}
		neg = false;
                Serial.println (input);
	}

	temp = input;
		if ((input < 0 && input >= -255) && (last >= 0 || last < -255))
		{
			drive.motorStop ();
		}
		else if ((input > 0 && input <= 255) && (last <= 0 || last > 255))
		{
			drive.motorStop ();
		}
		else if ((input > 255 && input <= 510) && (last <= 255 || last > 510))
		{
			drive.motorStop (); 
		}
		else if ((input < -255 && input >= -510) && (last < -510 || last >= -255))
		{
			drive.motorStop ();
		}
		else if ((input == 510) && (last !=510))
		{
			drive.motorStop ();
		}
		else if (input == -510 && last != -510)
		{
			drive.motorStop ();
		}

	if (input == 0)
	{
		drive.motorStop ();
	}
	else if (input > 0 && input <= 255)
	{
		drive.forward (temp);
	}
	else if (input < 0 && input >= -255)
	{
		drive.backward (abs (temp)); 
	}
	else if (input >=  -510 && input < -255)
	{
		temp = abs (temp + 255);
		drive.left (temp); 
	}
	else if (input > 255 && input <= 510)
	{
		temp = temp - 255;
		drive.right (temp);
	}
	else if (input == 511)
	{
		drive.rotate_cw (); 
	}
	else if (input == -511)
	{
		drive.rotate_ccw (); 
	}
	temp = 0;
	last = input;
}
