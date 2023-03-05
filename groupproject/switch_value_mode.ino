//Designed by Jelly Jinzhe Liu ab20328
void switch_value_mode()
{
    digitalWrite(red,1);
//按钮
    BUTTON_VALUE_1_B = digitalRead(BUTTON1_M1_BLUE);  //读取按钮blue
    BUTTON_VALUE_2_W = digitalRead(BUTTON2_M1_WHITE);  //读取按钮white
    BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green
    BUTTON_VALUE_4_R = digitalRead(BUTTON2_M2_RED);  //读取按钮red
    while(lcd==1)
    {
      lcd_1.clear();
      lcd=2;
    }
    
    lcd_1.setCursor(0, 0);
    lcd_1.print("white-Autotrim");//自动配平
    lcd_1.setCursor(0, 1);
    lcd_1.print("Blue-Automode");//自动模式
    lcd_1.setCursor(0, 2);
    lcd_1.print("Red-trim");//实时显示角度
    lcd_1.setCursor(0, 3);
    lcd_1.print("Green-information");//实时显示角度


    if (BUTTON_VALUE_2_W == 1)//white-----------------自动配平---------------------
    {
      gyro_loop();
//led
      for (i=0;i<3;i++)//蓝色闪3下
      {
        digitalWrite(red,1);
        delay(led_delay);
        digitalWrite(red,0);
        delay(led_delay);
      }

      lcd_1.setCursor(0, 2);//显示调整多少角度
      lcd_1.print("Need to pitch ");//俯仰
      lcd_1.print(z_balence);
      lcd_1.setCursor(0, 3);
      lcd_1.print("Need to roll ");//水平
      lcd_1.print(y_balence); 
      d=d-z_balence;//更新配平后角度
      c=c-y_balence;//二倍后变成现实角度
      delay(1000);
      lcd_1.clear();
      lcd_1.print("Success");//显示成功
      delay(1000);
    }
    if (BUTTON_VALUE_1_B == 1)//blue-----------------自动模式---------------------
    {
      lcd_1.clear();
      lcd_1.setCursor(0,0);
      lcd_1.print("Running auto");
      lcd_1.setCursor(0,1);
      lcd_1.print("Checking connection");
      delay(1000);
      lcd_1.clear();
      while(connect==1)//与其他建立连接
      {
        digitalWrite(green,1);
        BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green-退出
        lcd_1.setCursor(0, 0);
        lcd_1.print("Auto mode connected");
        servo_1.write(c);  //设置舵机旋转角度
        servo_2.write(d);  //设置舵机2旋转角度
        if (BUTTON_VALUE_3_G == 1)//退出程序
        {
          digitalWrite(green,0);
          lcd_1.clear();
          lcd_1.print("Canceling");
          delay(1000);
          break;
        }
      }
    }

    if (BUTTON_VALUE_4_R == 1)//red ------------------实时显示角度----------------
    
    {
      lcd_1.clear();
      while(1)//持续显示
      {
        BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green--退出
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
        //-----缩略显示----
        lcd_1.setCursor(12,0);
        lcd_1.print(event.orientation.x, 0);//航向 
        lcd_1.setCursor(12,1);
        lcd_1.print(event.orientation.y, 0);//水平
        lcd_1.setCursor(12,2);
        lcd_1.print(event.orientation.z, 0);//俯仰
        delay(500);
        lcd_1.clear();
        BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green
        if (BUTTON_VALUE_3_G == 1)//退出
        {
          delay(100);
          break;
        }
      }
    }
}