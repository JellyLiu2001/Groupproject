//Designed by Jelly Jinzhe Liu ab20328

//Gyroscope setup
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

//Gyroscope loop
void gyro_display() {
  digitalWrite(red, 0);          //Turn off the red LED
  sensors_event_t event;         //Create a sensor event object that provides information about the sensor event, including the raw sensor data, the event type that triggered the sensor, the precise data, and the time the event occurred.
  bno.getEvent(&event);          //Get gyroscope parameters
  ydeg = (event.orientation.y);  //Get y-axis information
  zdeg = (event.orientation.z);  //Get z-axis information
  delay(100);
  lcd_1.clear();  //Clear the screen
  lcd_1.print("Running trim......");

  //Z-axis trim calculation to display on the screen
  if (zdeg >= 0) {
    z_balence = 173 - zdeg;
  } else if (zdeg < 0) {
    z_balence = 173 + zdeg;
  }
  //Y-axis trim calculation
  y_balence = 2 - ydeg;
}

//Gyroscope trim using numerical values
void gyro_trim() {  //use the number of the trim
  sensors_event_t event;
  bno.getEvent(&event);
  //----------z-axis angle trim-----------------
  while (event.orientation.z >= base_z) {  //when the gyro angle is greater than the set angle
    lcd_1.setCursor(0, 1);
    lcd_1.print(c);
    lcd_1.print("|");
    lcd_1.print(d);
    digitalWrite(red, 1);
    delay(led_delay);
    digitalWrite(red, 0);
    delay(led_delay);  //display the angle information and blink the red LED
    sensors_event_t event;
    bno.getEvent(&event);
    //Serial.println(event.orientation.z);
    d--;               //reduce the angle of d
    servo_2.write(d);  //set the rotation angle of servo 2
    if (event.orientation.z < base_z) {
      break;
    }
  }
  while (event.orientation.z <= base_z) {  //when the gyro angle is less than the set angle
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
    d++;               //increase the angle of d
    servo_2.write(d);  //set the rotation angle of servo 2
    if (event.orientation.z > base_z) {
      break;
    }
  }
  //-------------------y-axis angle trim---------------------------
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
    servo_1.write(c);  //set the rotation angle of servo 1
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
    servo_1.write(c);  //set the rotation angle of servo 1
    if (event.orientation.y > base_y) {
      break;
    }
  }
  delay(1000);
  lcd_1.clear();
  lcd_1.print("Auto Trim Success");  //display success
}
