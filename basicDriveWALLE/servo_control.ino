#include <Servo.h>

#define MOTOR_MAX_SPEED 180
#define MOTOR_START_SPEED 100

int motor_current_speed = 0;
int motor_increment = 1;
int max_reached = 0;
int input;

Servo left_motor_r;
Servo left_motor_b;
Servo right_motor_r;
Servo right_motor_b;

void left_motor_forward(int speed)
{
	if (speed > MOTOR_MAX_SPEED)
		speed = MOTOR_MAX_SPEED;
	else if (speed < MOTOR_START_SPEED)
		speed = MOTOR_START_SPEED;

	left_motor_b.writeMicroseconds(speed);
	motor_current_speed = speed;

	Serial.print("current motor speed = ");
	Serial.println(motor_current_speed);  
}

void left_motor_backward(int speed)
{
	if (speed > MOTOR_MAX_SPEED)
		speed = MOTOR_MAX_SPEED;
	else if (speed < MOTOR_START_SPEED)
		speed = MOTOR_START_SPEED;

	left_motor_r.writeMicroseconds(speed);
	motor_current_speed = speed;

	Serial.print("current motor speed = ");
	Serial.println(motor_current_speed);  
}

void right_motor_forward(int speed)
{
	if (speed > MOTOR_MAX_SPEED)
		speed = MOTOR_MAX_SPEED;
	else if (speed < MOTOR_START_SPEED)
		speed = MOTOR_START_SPEED;

	right_motor_b.writeMicroseconds(speed);
	motor_current_speed = speed;

	Serial.print("current motor speed = ");
	Serial.println(motor_current_speed);  
}

void right_motor_backward(int speed)
{
	if (speed > MOTOR_MAX_SPEED)
		speed = MOTOR_MAX_SPEED;
	else if (speed < MOTOR_START_SPEED)
		speed = MOTOR_START_SPEED;

	right_motor_r.writeMicroseconds(speed);
	motor_current_speed = speed;

	Serial.print("current motor speed = ");
	Serial.println(motor_current_speed);  
}

void robot_left (int speed)
{
	right_motor_forward (speed);
	left_motor_backward (speed);
}

void robot_right (int speed)
{
	right_motor_backward (speed);
	left_motor_forward (speed);
}

void robot_forward (int speed)
{
	right_motor_forward (speed);
	left_motor_forward (speed);
}

void robot_backward (int speed)
{
	right_motor_backward (speed);
	left_motor_backward (speed);
}

// Wrapper function for Servo's ".write(*speed*)" function
void motorSetSpeed(int speed)
{
// Don't let the motor go above or below pre-determined max and min
	if (speed > MOTOR_MAX_SPEED)
		speed = MOTOR_MAX_SPEED;
	else if (speed < MOTOR_START_SPEED)
		speed = MOTOR_START_SPEED;

	left_motor_b.writeMicroseconds(speed);
	right_motor_b.writeMicroseconds(speed);
	motor_current_speed = speed;

	Serial.print("current motor speed = ");
	Serial.println(motor_current_speed);
}

void motorStop()
{
	left_motor_r.writeMicroseconds(0);
	left_motor_b.writeMicroseconds(0);
	right_motor_r.writeMicroseconds(0);
	right_motor_b.writeMicroseconds(0);
}

/*
!!! Very important! Motor has to start at 0 and reach desired speed gradually.
It will NOT work if you go directly to speed 60 or 100, etc.
If this isn't working for you, try increasing the delay.
*/


void setup()
{

	// Setup deb
	Serial.begin(9600);

	// Motor
	delay(1000);
	left_motor_r.attach(10);
	left_motor_b.attach(9);
	right_motor_r.attach(5);
	right_motor_b.attach(6);
	motorSetSpeed(MOTOR_START_SPEED);
	delay(1500);
}

/*
Speeds the motor up until it hits 170,
then slows it down to the start speed again.
Repeats.
*/
void loop()
{
	if(Serial.available())
	{
		input = Serial.read();
	}
	if (input > 0 && input < 255) 
	{
		robot_forward (input);
	} 
	if (input < 0 && input > -255)
	{
		robot_backward (-input);
	}
	if (input > 254 && input < 510)
	{
		robot_right (input - 255);
	}
	if (input < -254 && input > -510)
	{
		robot_right ((-input) - 255);
	}
	if (input == 0)
	{
		motorStop ();
	}
	if (motor_current_speed < MOTOR_START_SPEED) 
	{
		max_reached = 0;
	} else if (motor_current_speed > MOTOR_MAX_SPEED) 
	{
		max_reached = 1;
	}
	delay(500);
}
