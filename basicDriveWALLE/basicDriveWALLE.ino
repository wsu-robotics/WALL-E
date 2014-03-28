#define TRIG_PIN 12
#define ECHO_PIN 13
#define LED1 11
#define LED2 10  

#include <Drive.h>

Drive drive (5, 6);

byte input;

void setup ()
{
  Serial.begin (9600);
  pinMode (ECHO_PIN, INPUT);
  pinMode (TRIG_PIN, OUTPUT);
}

void loop ()
{
  /*long duration, distance;
  digitalWrite (TRIG_PIN, LOW);
  delayMicroseconds (2);
  digitalWrite (TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite (TRIG_PIN, LOW);
  duration = pulseIn (ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance < 4)
  {
      digitalWrite (LED1, HIGH);
      digitalWrite (LED2, LOW);
  }
  else
  {
      digitalWrite (LED1, LOW);
      digitalWrite (LED2, HIGH);
  }
  if (distance >= 200 || distance <= 0)
  {
     Serial.println ("Out of range"); 
  }
  else
  {
      Serial.print (distance);
      Serial.println (" cm");
  }
  delay (500);*/
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
     if (input == 'w')
     {
        drive.forward (); 
     }
  }
}
