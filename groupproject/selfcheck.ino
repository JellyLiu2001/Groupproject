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
  for (pos = 20; pos <= 160; pos += 1)//舵机从20-160 记录数据
  {
    servo_1.write(pos);
    //delay(200);
    sensors_event_t event; 
    bno.getEvent(&event);
    Serial.print(pos);
    Serial.print(",");
    Serial.print(event.orientation.y,4);
    Serial.print(",");
    Serial.println(event.orientation.z,4);
  }
  for (pos = 160; pos >= 20; pos -= 1)
  {
    servo_2.write(pos);
    //delay(200);
    sensors_event_t event; 
    bno.getEvent(&event);
    Serial.print(pos);
    Serial.print(",");
    Serial.print(event.orientation.y,4);
    Serial.print(",");
    Serial.println(event.orientation.z,4);
  }
  lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("Testing success");    //打印

  //-----------------自检完成-------------------------------
 }