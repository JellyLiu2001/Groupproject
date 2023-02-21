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
  servo_10.attach(10, 1000, 2500);
}

void loop()
{
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 20; pos <= 160; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 160; pos >= 20; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
}