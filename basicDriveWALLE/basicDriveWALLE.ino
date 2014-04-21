#define MOTOR1PIN1 4
#define MOTOR1PIN2 6
#define MOTOR1CONTROLPIN 5
#define MOTOR2PIN1 9
#define MOTOR2PIN2 11
#define MOTOR2CONTROLPIN 10

#include <Drive.h>

//Right motor pins then left
Drive drive (MOTOR1PIN1, MOTOR1PIN2, MOTOR1CONTROLPIN,
             MOTOR2PIN1, MOTOR2PIN2, MOTOR2CONTROLPIN);

int input, temp;

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
  if (Serial.available ())
  {
     input = Serial.read ();
     temp = input;
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
        temp = temp + 255;
        drive.left (abs(temp)); 
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
  }
  temp = 0;
}
