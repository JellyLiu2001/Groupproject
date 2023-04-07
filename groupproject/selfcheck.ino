//Designed by Jelly Jinzhe Liu ab20328
void selfcheck() {
  //------------------Self-checking-------------------------
  lcd_1.setCursor(0, 0);                //Select the location of the screen
  lcd_1.print("Welcome");               //Print
  lcd_1.setCursor(0, 1);                //Select the location of the screen
  lcd_1.print("Selftesting");           //Print
  lcd_1.setCursor(0, 2);                //Select the location of the screen
  lcd_1.print("Design by Jinzhe Liu");  //Print
  for (i = 0; i <= 2; i++)              //RGB flashes three times
  {
    digitalWrite(red, 1);
    digitalWrite(green, 1);
    digitalWrite(blue, 1);
    delay(led_delay);
    digitalWrite(red, 0);
    digitalWrite(green, 0);
    digitalWrite(blue, 0);
    delay(led_delay);
  }

  lcd_1.setCursor(0, 1);           //Select the location of the screen
  lcd_1.print("Testing success");  //Print

  //-----------------Self-checking completed-------------------------------
}