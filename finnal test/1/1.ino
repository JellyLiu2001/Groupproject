#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
int pos = 0;
Servo servo_9;
Servo servo_10;
Adafruit_BNO055 bno = Adafruit_BNO055(55);
void setup()
{
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  delay(1000);
  bno.setExtCrystalUse(true);
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);
  servo_10.attach(10, 500, 2500);
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 5)
  {

    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
    Serial.print(pos);
    Serial.print(",");
    //Serial.print("Y: ");
    Serial.print("event.orientation.y");
    Serial.print(",");
    //Serial.print("Z: ");
    Serial.println("event.orientation.z");
    delay(10);
  }
  for (pos = 180; pos >= 0; pos -= 5)
  {
    // tell servo to go to position in variable 'pos'
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
    Serial.print(pos);
    Serial.print(",");
    //Serial.print("Y: ");
    Serial.print("event.orientation.y");
    Serial.print(",");
    //Serial.print("Z: ");
    Serial.println("event.orientation.z");
    delay(10);
  }
Serial.print("finish");
}
void loop()
{}