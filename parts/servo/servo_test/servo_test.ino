// C++ code
//
/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

int pos = 0;

Servo servo_9;
Servo servo_10;

void setup()
{
  servo_9.attach(9, 1000, 2500);
  servo_10.attach(13, 1000, 2500);
}

void loop()
{
    servo_9.write(pos);
    servo_10.write(pos);
}