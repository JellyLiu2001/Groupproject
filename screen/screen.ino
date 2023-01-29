    /*
  Character-LCD-I2C-1602
  modified on 31 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

  based on LiquidCrystal_I2C Library Arduino Examples
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x27,20,4);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup()
{
  lcd_1.init();                      // initialize the lcd 
  lcd_1.backlight();
  Serial.begin(9600);
 
}

void loop()
{
  lcd_1.print("Yang Li");
  while(1)
  {

  }
}
