//Designed by Jelly Jinzhe Liu ab20328
void switch_value_mode() {
  digitalWrite(red, 1);
  //按钮
  BUTTON_VALUE_1_B = digitalRead(BUTTON1_M1_BLUE);   //读取按钮blue
  BUTTON_VALUE_2_W = digitalRead(BUTTON2_M1_WHITE);  //读取按钮white
  BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green
  BUTTON_VALUE_4_R = digitalRead(BUTTON2_M2_RED);    //读取按钮red
  while (lcd == 1) {
    lcd_1.clear();
    lcd = 2;
  }

  lcd_1.setCursor(0, 0);
  lcd_1.print("white-Autotrim");  //自动配平
  lcd_1.setCursor(0, 1);
  lcd_1.print("Blue-Automode");  //自动模式
  lcd_1.setCursor(0, 2);
  lcd_1.print("Red-trim");  //实时显示角度
  lcd_1.setCursor(0, 3);
  lcd_1.print("Green-information");  //实时显示角度


  if (BUTTON_VALUE_2_W == 1)  //white-----------------自动配平---------------------
  {
    gyro_loop();
    //led
    for (i = 0; i < 3; i++)  //蓝色闪3下
    {
      digitalWrite(blue, 1);
      delay(led_delay);
      digitalWrite(blue, 0);
      delay(led_delay);
    }

    lcd_1.setCursor(0, 2);          //显示调整多少角度
    lcd_1.print("Need to pitch ");  //俯仰
    lcd_1.print(z_balence);
    lcd_1.setCursor(0, 3);
    lcd_1.print("Need to roll ");  //水平
    lcd_1.print(y_balence);
    sensors_event_t event;
    bno.getEvent(&event);

    while (event.orientation.z >= base_z) {
      digitalWrite(red, 1);
      delay(led_delay);
      digitalWrite(red, 0);
      delay(led_delay);
      sensors_event_t event;
      bno.getEvent(&event);
      //Serial.println(event.orientation.z);
      d++;
      servo_2.write(d);  //设置舵机2旋转角度
      if (event.orientation.z <= base_z) {
        break;
      }
    }
    while (event.orientation.z <= base_z) {
      digitalWrite(red, 1);
      delay(led_delay);
      digitalWrite(red, 0);
      delay(led_delay);
      sensors_event_t event;
      bno.getEvent(&event);
      //Serial.println(event.orientation.z);
      d--;
      servo_2.write(d);  //设置舵机2旋转角度
      if (event.orientation.z >= base_z) {
        break;
      }
    }
    while (event.orientation.y >= base_y) {
      digitalWrite(blue, 1);
      delay(led_delay);
      digitalWrite(blue, 0);
      delay(led_delay);
      sensors_event_t event;
      bno.getEvent(&event);
      //Serial.println(event.orientation.y);
      c++;
      servo_2.write(c);  //设置舵机2旋转角度
      if (event.orientation.y <= base_y) {
        break;
      }
    }
    while (event.orientation.y <= base_y) {
      digitalWrite(blue, 1);
      delay(led_delay);
      digitalWrite(blue, 0);
      delay(led_delay);
      sensors_event_t event;
      bno.getEvent(&event);
      //Serial.println(event.orientation.y);
      c--;
      servo_2.write(c);  //设置舵机2旋转角度
      if (event.orientation.y >= base_y) {
        break;
      }
    }

    delay(1000);
    lcd_1.clear();
    lcd_1.print("Success");  //显示成功
    delay(1000);
  }
  if (BUTTON_VALUE_1_B == 1)  //blue-----------------自动模式---------------------
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
    while (connect == 1)  //与其他建立连接
    {

      digitalWrite(green, 1);
      while (Serial.available() > 0)  //当有信号的时候
      {
        trans = 1;
        stat = stat + 1;
        l[stat] = Serial.parseInt();
        c = l[0];//等于第一次传回数据
        d = l[1];//等于第二次传回的数据
        servo_1.write(c);//改变舵机位置
        servo_2.write(d);
        lcd_1.print(trans);
        lcd_1.setCursor(0, 0);
        lcd_1.clear();
        lcd_1.print("motor1:");
        lcd_1.print(l[0]);
        lcd_1.print("|");
        lcd_1.setCursor(0, 1);
        lcd_1.print("motor2:");
        lcd_1.print(l[1]);
        lcd_1.print("|");
        lcd_1.setCursor(0, 2);
        lcd_1.print("current status:");
        lcd_1.print(stat + 1);
        if (stat == 1) { stat = -1; }
      }
      trans = 0;
      lcd_1.setCursor(0, 3);
      lcd_1.print("Trans:");
      lcd_1.print(trans);
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green-退出

      if (BUTTON_VALUE_3_G == 1)  //退出程序
      {
        digitalWrite(green, 0);
        lcd_1.clear();
        lcd_1.print("Canceling");
        delay(1000);
        break;
      }
    }
  }

  if (BUTTON_VALUE_4_R == 1)  //red ------------------实时显示角度----------------

  {
    lcd_1.clear();
    while (BUTTON_VALUE_3_G == 0)  //持续显示
    {
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green--退出
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
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green
                                                         //-----缩略显示----
      lcd_1.setCursor(12, 0);
      lcd_1.print(event.orientation.x, 0);  //航向
      lcd_1.setCursor(12, 1);
      lcd_1.print(event.orientation.y, 0);  //水平
      lcd_1.setCursor(12, 2);
      lcd_1.print(event.orientation.z, 0);  //俯仰
      delay(500);
      lcd_1.clear();
      BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green
    }
  }
}