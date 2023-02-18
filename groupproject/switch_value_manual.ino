//Designed by Jelly Jinzhe Liu ab20328
void switch_value_manual()
{
    
    digitalWrite(red, 0);
    BUTTON_VALUE_1_B = digitalRead(BUTTON1_M1_BLUE);  //读取按钮blue
    BUTTON_VALUE_2_W = digitalRead(BUTTON2_M1_WHITE);  //读取按钮white
    BUTTON_VALUE_3_G = digitalRead(BUTTON1_M2_GREEN);  //读取按钮green
    BUTTON_VALUE_4_R = digitalRead(BUTTON2_M2_RED);  //读取按钮red
    delay(100);
    //---------------------------------------------------------屏幕---------------------------------------
    pre_deg_c=current_c;//如果数据不改变, 屏幕不进行刷新
    current_c=c;
    pre_deg_d=current_d;
    current_d=d;
    if (pre_deg_c!=current_c||pre_deg_d!=current_d)//如果数据改变, 屏幕刷新
    {
      lcd_1.clear();
      lcd_1.setCursor(0, 0);           //将屏幕选中x,y
      lcd_1.print("Motor1: ");         //打印
      lcd_1.print(c);                  //打印
      lcd_1.setCursor(0, 1);           //将屏幕选中x,y
      lcd_1.print("Motor2: ");         //打印
      lcd_1.print(d);                  //打印
    }

//---------------------------------------------------------按钮---------------------------------------

    //blue
    if (BUTTON_VALUE_1_B == 1) 
    {
      c = c + 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }
    //white
    if (BUTTON_VALUE_2_W == 1) 
    {
      c = c - 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }

    //green
    if (BUTTON_VALUE_3_G == 1)
    {
      d = d + 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }
    //red
    if (BUTTON_VALUE_4_R == 1)
    {
      d = d - 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }
}