//Designed by Jelly Jinzhe Liu ab20328
void gyro_setup() {
  if (!bno.begin()) {
    /* There was a problem detecting the BNO055 ... check your connections */
    lcd_1.print("Please check the connection of GYRO!");
    while (1)
      ;
  }

  delay(1000);

  bno.setExtCrystalUse(true);
}
//----------------------------------自动配平-----------------------------------------------
void gyro_loop() {
  digitalWrite(red, 0);
  sensors_event_t event;
  bno.getEvent(&event);
  ydeg = (event.orientation.y);
  zdeg = (event.orientation.z);
  delay(100);
  lcd_1.clear();
  lcd_1.print("Runing trim......");

  //z配平-------------------
  if (zdeg >= 0) {
    z_balence = 173 - zdeg;
  } else if (zdeg < 0) {
    z_balence = 173 + zdeg;
  }
  //y配平-----------------------
  y_balence = 2 - ydeg;
}
void gyro_trim() { 
  sensors_event_t event;
  bno.getEvent(&event);
  //----------z角度配平-----------------
  while (event.orientation.z >= base_z) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(c);
    lcd_1.print("|");
    lcd_1.print(d);
    digitalWrite(red, 1);
    delay(led_delay);
    digitalWrite(red, 0);
    delay(led_delay);
    sensors_event_t event;
    bno.getEvent(&event);
    //Serial.println(event.orientation.z);
    d--;
    servo_2.write(d);  //设置舵机2旋转角度
    if (event.orientation.z < base_z) {
      break;
    }
  }
  while (event.orientation.z <= base_z) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(c);
    lcd_1.print("|");
    lcd_1.print(d);
    digitalWrite(green, 1);
    delay(led_delay);
    digitalWrite(green, 0);
    delay(led_delay);
    sensors_event_t event;
    bno.getEvent(&event);
    //Serial.println(event.orientation.z);
    d++;
    servo_2.write(d);  //设置舵机2旋转角度
    if (event.orientation.z > base_z) {
      break;
    }
  }
  //-------------------y角度配平---------------------------
  while (event.orientation.y >= base_y) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(c);
    lcd_1.print("|");
    lcd_1.print(d);
    digitalWrite(blue, 1);
    delay(led_delay);
    digitalWrite(blue, 0);
    delay(led_delay);
    sensors_event_t event;
    bno.getEvent(&event);
    Serial.print(base_y);
    //Serial.println(event.orientation.y);
    c++;
    servo_1.write(c);  //设置舵机2旋转角度
    if (event.orientation.y < base_y) {
      break;
    }
  }
  while (event.orientation.y <= base_y) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(c);
    lcd_1.print("|");
    lcd_1.print(d);
    digitalWrite(blue, 1);
    delay(led_delay);
    digitalWrite(blue, 0);
    delay(led_delay);
    sensors_event_t event;
    bno.getEvent(&event);
    c--;
    servo_1.write(c);  //设置舵机2旋转角度
    if (event.orientation.y > base_y) {
      break;
    }
  }
  delay(1000);
  lcd_1.clear();
  lcd_1.print("Auto Trim Success");  //显示成功
                                     /*
    for (deg_a = -30; deg_a <= 30; deg_a++) {
      sensors_event_t event;
      bno.getEvent(&event);
      servo_1.write(c + deg_a);
      degree_1[deg_a + 30] = c + deg_a;
      gyro_1[deg_a + 30] = event.orientation.y;
      delay(100);
      
    }
    for (deg_b = -30; deg_b <= 30; deg_b++) {
      sensors_event_t event;
      bno.getEvent(&event);
      servo_2.write(d + deg_b);
      degree_2[deg_b + 30] = d + deg_b;
      gyro_2[deg_b + 30] = event.orientation.z;
      delay(100);
    }
    servo_1.write(c);
    servo_2.write(d);
    */
}