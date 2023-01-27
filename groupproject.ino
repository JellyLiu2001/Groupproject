#include "config.h"//定义所有针脚

void setup()  //初始化；
{
  Serial.begin(9600);
  lcd_1.init();                      // initialize the lcd 
  lcd_1.backlight();
  pinMode(SWITCH, INPUT);  //定义SWTICH为输出模式；
  pinMode(BUTTON1_M1, INPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  servo_1.attach(9);  //设定舵机接口
  servo_2.attach(10);  //设定舵机接口


  //------------------自检-------------------------
  lcd_1.begin(16, 2);//设定lcd行数
  lcd_1.setCursor(0, 0);  //将屏幕选中x,y
  lcd_1.print("Welcome");    //打印
  lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("selftesting");    //打印
  delay(1000);
  for (i=0; i<=2;i++)
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

  //-----------------自检完成-------------------------------
}

void loop() {
  switch_value = digitalRead(SWITCH);  //读取数字针脚的值；
  //------定义舵机范围------
  if (c >= 190) 
  {
    c = 190;
  }
  if (d >= 190) 
  {
    d = 190;
  }
  if (c <= 10) 
  {
    c = 10;
  }
  if (d <= 10) 
  {
    d = 10;
  }
  if (switch_value == LOW)  //去抖的作用，一般10-15ms；
  {
    delay(10);
  }

  if (switch_value == LOW)  //开关是1------------------
  {
    digitalWrite(red, 0);
    BUTTON_VALUE_1 = digitalRead(BUTTON1_M1);  //读取按钮blue
    BUTTON_VALUE_2 = digitalRead(BUTTON2_M1);  //读取按钮white
    BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
    BUTTON_VALUE_4 = digitalRead(BUTTON2_M2);  //读取按钮red
    Serial.print("Button red:");
    Serial.println(c);  //显示按钮数据
    delay(100);
    pre_deg_c=current_c;//如果数据不改变, 屏幕不进行刷新
    current_c=c;
    pre_deg_d=current_d;
    current_d=d;
    if (pre_deg_c!=current_c||pre_deg_d!=current_d)//如果数据改变, 屏幕刷新
{
    lcd_1.clear();
    lcd_1.setCursor(0, 0);           //将屏幕选中x,y
    lcd_1.print("motor1: ");         //打印
    lcd_1.print(c);                  //打印
    lcd_1.setCursor(0, 1);           //将屏幕选中x,y
    lcd_1.print("motor2: ");         //打印
    lcd_1.print(d);                  //打印
}

//---------------------------------------------------------按钮---------------------------------------

    //blue
    if (BUTTON_VALUE_1 == 0)  //如果按钮断开---------------------
    {

    } 
    else  //按钮打开--------------------
    {
      c = c + 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }
    //white
    if (BUTTON_VALUE_2 == 0)  //如果按钮断开---------------------
    {

    } 
    else  //按钮打开--------------------
    {
      c = c - 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }

    //green
    if (BUTTON_VALUE_3 == 0)  //如果按钮断开---------------------
    {

    } 
    else  //按钮打开--------------------
    {
      d = d + 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }
    //red
    if (BUTTON_VALUE_4 == 0)  //如果按钮断开---------------------
    {

    } 
    else  //按钮打开--------------------
    {
      d = d - 5;
      digitalWrite(green, 1);
      delay(led_delay);
      digitalWrite(green, 0);
    }
  } 
  else  //开关是0-------------------
  {
    digitalWrite(red,1);
    BUTTON_VALUE_1 = digitalRead(BUTTON1_M1);  //读取按钮red
    BUTTON_VALUE_2 = digitalRead(BUTTON2_M1);  //读取按钮green
    BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮blue
    BUTTON_VALUE_4 = digitalRead(BUTTON2_M2);  //读取按钮white
    lcd_1.setCursor(0, 0);
    lcd_1.print("white-Autotrim");//打印
    lcd_1.setCursor(0, 1);
    lcd_1.print("Blue-Automode");//打印
    lcd_1.setCursor(0, 2);
    lcd_1.print("for YES");//打印

    if (BUTTON_VALUE_2 == 1)//white-----------------配平---------------------
    {
      delay(100);
      lcd_1.clear();
      lcd_1.print("runing trim......");
      digitalWrite(red,0);
      balence=90-test_xdeg;
      for (i=0;i<3;i++)
      {
        digitalWrite(blue,1);
        delay(led_delay);
        digitalWrite(blue,0);
        delay(led_delay);
        lcd_1.setCursor(0, 2);
        lcd_1.print("need to turn ");
        lcd_1.print(balence);
        d=balence;
      }
      lcd_1.clear();
      lcd_1.print("success");
      delay(1000);
    }
    if (BUTTON_VALUE_1 == 1)//white-----------------配平---------------------
    {
      lcd_1.clear();
      lcd_1.setCursor(0,0);
      lcd_1.print("Running auto");
      lcd_1.setCursor(0,1);
      lcd_1.print("checking connection");
      delay(1000);
      lcd_1.clear();
      while(connect==1)
      {
        BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
        lcd_1.setCursor(0, 0);
        lcd_1.print("auto mode connected");
        servo_1.write(c);  //设置舵机旋转角度
        servo_2.write(d);  //设置舵机2旋转角度
        if (BUTTON_VALUE_3 == 1)
        {
          lcd_1.clear();
          lcd_1.print("canceling");
          delay(1000);
          break;
        }
      }

  }
  servo_1.write(c);  //设置舵机旋转角度
  servo_2.write(d);  //设置舵机2旋转角度
  delay(10);// Delay a little bit to improve simulation performance
  }
}