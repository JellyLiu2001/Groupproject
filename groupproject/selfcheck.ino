//Designed by Jelly Jinzhe Liu ab20328
void selfcheck()
 {
 //------------------自检-------------------------
  lcd_1.setCursor(0, 0);  //将屏幕选中x,y
  lcd_1.print("Welcome");    //打印
  lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("Selftesting");    //打印
  lcd_1.setCursor(0, 2);  //将屏幕选中x,y
  lcd_1.print("Design by Jinzhe Liu");    //打印
  for (i=0; i<=2;i++)//RGB闪三下
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
  servo_1.write(10);  //设置舵机旋转角度
  servo_2.write(10);  //设置舵机2旋转角度
  delay(500);
  servo_1.write(190);  //设置舵机旋转角度
  servo_2.write(190);  //设置舵机2旋转角度
  delay(500);
  lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("Testing success");    //打印
  delay(1000);
  //-----------------自检完成-------------------------------
 }