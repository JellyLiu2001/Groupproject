//Designed by Jelly Jinzhe Liu ab20328

void switch_value_mode() {
  digitalWrite(red, 1);
  //Button
  BUTTON_VALUE_1_B = digitalRead(BUTTON1_M1_BLUE);   //Read button blue
  BUTTON_VALUE_2_W = digitalRead(BUTTON2_M1_WHITE);  //Read button white
  BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //Read button green
  BUTTON_VALUE_4_R = digitalRead(BUTTON2_M2_RED);    //Read button red
  while (lcd == 1) {
    lcd_1.clear();
    lcd = 2;
  }
  //Display modes on screen
  lcd_1.setCursor(0, 0);
  lcd_1.print("white-Autotrim");  //Autotrim
  lcd_1.setCursor(0, 1);
  lcd_1.print("Blue-Automode");  //Automode
  lcd_1.setCursor(0, 2);
  lcd_1.print("Red-trim");  //Real-time angle display
  lcd_1.setCursor(0, 3);
  lcd_1.print("Green-information");  //Real-time angle display

  if (BUTTON_VALUE_2_W == 1)  //white-----------------Autotrim---------------------
  {
    gyro_display();
    //led
    for (i = 0; i < 3; i++)  //Flash blue 3 times
    {
      digitalWrite(blue, 1);
      delay(led_delay);
      digitalWrite(blue, 0);
      delay(led_delay);
    }

    lcd_1.setCursor(0, 2);   //Display how many degrees to adjust
    lcd_1.print("motor1:");  //Pitch
    lcd_1.print(c);
    lcd_1.setCursor(0, 3);
    lcd_1.print("motor2: ");  //Roll
    lcd_1.print(d);

    gyro_trim();
    lcd_1.clear();
    lcd_1.print("Servo data saved!");  //Display success
    delay(1000);
    lcd_1.clear();
    deg_1 = c;
    deg_2 = d;
    EEPROM.write(0, deg_1);  //Store data into EEPROM
    EEPROM.write(1, deg_2);
  }
  if (BUTTON_VALUE_1_B == 1)  //blue-----------------Auto trim---------------------
  {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Running auto");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Checking connection");
    delay(1000);
    lcd_1.clear();

    trans = 0;
    lcd_1.setCursor(0, 3);
    lcd_1.print(trans);
    while (connect == 1)  //connect to other devices
    {

      digitalWrite(green, 1);
      while (Serial.available() > 0)  //when there is a signal
      {
        trans = 1;
        stat = stat + 1;          //increment the status by 1 every time data is transmitted
        num = Serial.parseInt();  //receive data sent by computer
        Serial.flush();
        if (num != 0) {
          c = num / 1000;  //decode the data by dividing by 1000
          d = num % 1000;  //the remainder
          lcd_1.print(trans);
          lcd_1.setCursor(0, 0);
          lcd_1.clear();
          lcd_1.print("motor1:");
          lcd_1.print(c);
          lcd_1.print("|");
          lcd_1.setCursor(0, 1);
          lcd_1.print("motor2:");
          lcd_1.print(d);
          lcd_1.print("|");
          lcd_1.setCursor(0, 2);
          lcd_1.print("current status:");
          lcd_1.print(stat + 1);
          T_1 = c - 90;  //compare the data with the gyroscope
          T_2 = d - 90;
          servo_1.write(deg_1 + T_1);  //use the leveled data for automatic mode
          servo_2.write(deg_2 + T_2);
          if (stat == 1) { stat = -1; }  //return when the value equals 2
        }
      }
      trans = 0;
      lcd_1.setCursor(0, 3);
      lcd_1.print("Trans:");
      lcd_1.print(trans);
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //read the green button - exit

      if (BUTTON_VALUE_3_G == 1)  //exit the program
      {
        digitalWrite(green, 0);
        lcd_1.clear();
        lcd_1.print("Canceling");
        delay(1000);
        break;
      }
    }
  }

  if (BUTTON_VALUE_4_R == 1)  //red ------------------Real-time Display Angle----------------

  {
    lcd_1.clear();
    while (BUTTON_VALUE_3_G == 0)  //Continuous display
    {
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //Read button green--exit
      sensors_event_t event;
      bno.getEvent(&event);
      lcd_1.setCursor(0, 0);
      lcd_1.print("x: ");
      lcd_1.print(event.orientation.x, 4);
      lcd_1.setCursor(0, 1);
      lcd_1.print("y: ");
      lcd_1.print(event.orientation.y, 4);
      lcd_1.setCursor(0, 2);
      lcd_1.print("z: ");
      lcd_1.print(event.orientation.z, 4);
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //Read button green
      //-----Short display----
      lcd_1.setCursor(12, 0);
      lcd_1.print(event.orientation.x, 0);  //Heading
      lcd_1.setCursor(12, 1);
      lcd_1.print(event.orientation.y, 0);  //Roll
      lcd_1.setCursor(12, 2);
      lcd_1.print(event.orientation.z, 0);  //Pitch
      delay(500);
      lcd_1.clear();
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //Read button green
    }
  }
}