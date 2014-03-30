#define MOTOR1PIN1 5
#define MOTOR1PIN2 6
#define MOTOR1CONTROLPIN 12
#define MOTOR2PIN1 10
#define MOTOR2PIN2 11
#define MOTOR2CONTROLPIN 2

#include <Drive.h>

//Right motor pins then left
Drive drive (MOTOR1PIN1, MOTOR1PIN2, MOTOR1CONTROLPIN,
             MOTOR2PIN1, MOTOR2PIN2, MOTOR2CONTROLPIN);

byte input;

void setup ()
{
  Serial.begin (9600);
}

void loop ()
{
  //Drive Code
  if (Serial.available ())
  {
     input = Serial.read ();
     if (input == 'w')
     {
       drive.forward (); 
     }
     else if (input == 's')
     {
        drive.backward (); 
     }
     else if (input == 'a')
     {
        drive.left (); 
     }
     else if (input == 'd')
     {
         drive.right ();
     }
  }
}
