//Designed by Jelly Jinzhe Liu ab20328
void switch_value_manual() {
  while (lcd == 2) {//需要修改
    lcd_1.clear();
    lcd = 1;
  }
  digitalWrite(red, 0);
  BUTTON_VALUE_1_B = digitalRead(BUTTON1_M1_BLUE);   //read button blue
  BUTTON_VALUE_2_W = digitalRead(BUTTON2_M1_WHITE);  //read button white
  BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //read button green
  BUTTON_VALUE_4_R = digitalRead(BUTTON2_M2_RED);    //read button red
  delay(100);
  //---------------------------------------------------------LCD screen---------------------------------------
  pre_deg_c = current_c;  //if data doesn't change, no screen refresh
  current_c = c;
  pre_deg_d = current_d;
  current_d = d;
  if (pre_deg_c != current_c || pre_deg_d != current_d)  //if data changes, refresh the screen
  {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);    //select position x, y
    lcd_1.print("Motor1: ");  //print
    lcd_1.print(c);           //print
    lcd_1.setCursor(0, 1);    //select position x, y
    lcd_1.print("Motor2: ");  //print
    lcd_1.print(d);           //print
    sensors_event_t event;
    bno.getEvent(&event);
    lcd_1.setCursor(12, 0);
    lcd_1.print(event.orientation.x, 4);  //yaw
    lcd_1.setCursor(12, 1);
    lcd_1.print(event.orientation.y, 4);  //pitch
    lcd_1.setCursor(12, 2);
    lcd_1.print(event.orientation.z, 4);  //roll
  }

  //---------------------------------------------------------Button---------------------------------------
  //When the button is pressed, the angle changes by 5 degrees
  //blue
  if (BUTTON_VALUE_1_B == 1) {
    c = c + 5;
    digitalWrite(green, 1);
    delay(led_delay);
    digitalWrite(green, 0);
  }
  //white
  if (BUTTON_VALUE_2_W == 1) {
    c = c - 5;
    digitalWrite(green, 1);
    delay(led_delay);
    digitalWrite(green, 0);
  }

  //green
  if (BUTTON_VALUE_3_G == 1) {
    d = d + 5;
    digitalWrite(green, 1);
    delay(led_delay);
    digitalWrite(green, 0);
  }
  //red
  if (BUTTON_VALUE_4_R == 1) {
    d = d - 5;
    digitalWrite(green, 1);
    delay(led_delay);
    digitalWrite(green, 0);
  }
}