    /*
  Character-LCD-I2C-1602
  modified on 31 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

  based on LiquidCrystal_I2C Library Arduino Examples
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
LiquidCrystal_I2C lcd_1(0x27,20,4);  // set the LCD address to 0x3F for a 16 chars and 2 line display
Adafruit_BNO055 bno = Adafruit_BNO055(55);
int a;
void setup()
{
  lcd_1.init();                      // initialize the lcd 
  lcd_1.backlight();
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    lcd_1.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}

void loop()
{
  sensors_event_t event; 
  bno.getEvent(&event);
  lcd_1.setCursor(0,0);
  lcd_1.print("x: ");
  lcd_1.print(event.orientation.x, 4);
  lcd_1.setCursor(0,1);
  lcd_1.print("y: ");
  lcd_1.print(event.orientation.y, 4);
  lcd_1.setCursor(0,2);
  lcd_1.print("z: ");
  lcd_1.print(event.orientation.z, 4);
  /* Get a new sensor event */ 
  a=(event.orientation.z);
  Serial.print(a);
  
  /* Display the floating point data 
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");
  */
  delay(1000);
}
