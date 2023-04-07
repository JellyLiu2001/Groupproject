// Designed by Jelly Jinzhe Liu ab20328
// The above line is a comment indicating the author and their identifier
#include "config.h" //include the configuration header file which defines all pins
#include <EEPROM.h> //include the EEPROM library for reading and writing data to non-volatile memory

void setup()
{               // initialize the system
  init_setup(); // initialize peripherals such as the LCD, LED, and servo
  gyro_setup(); // initialize the gyroscope
  selfcheck();  // perform self-inspection
}

void loop()
{
  switch_value = digitalRead(SWITCH); // read the value of a digital pin
  transfer();                         // define servo range
  if (switch_value == LOW)
  {                        // if switch is 1
    switch_value_manual(); // manually adjust servo
  }
  else
  {                      // if switch is 0
    switch_value_mode(); // select mode
  }
  servo_1.write(c); // set the angle of servo 1
  servo_2.write(d); // set the angle of servo 2
}