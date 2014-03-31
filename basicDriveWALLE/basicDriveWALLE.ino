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

int input;

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
     if (input >= 0 && input <= 255)
     {
       drive.forward (input); 
     }
     if (input <= 0 && input >= -255)
     {
        drive.backward (abs (input)); 
     }
     if (input >=  -510 && input < -255)
     {
        input += 255;
        drive.left (abs(input)); 
     }
     if (input > 255 && input <= 510)
     {
         input -= 255;
         drive.right (input);
     }
     if (input == 511)
     {
        drive.rotate_cw (); 
     }
     if (input == -511)
     {
        drive.rotate_ccw (); 
     }
  }
}
