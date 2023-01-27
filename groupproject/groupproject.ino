#include "config.h"


void setup()  //初始化；
{
  Serial.begin(9600);
  pinMode(SWITCH, INPUT);  //定义SWTICH为输出模式；
  pinMode(BUTTON1_M1, INPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  servo_1.attach(9);  //设定舵机接口
  servo_2.attach(10);  //设定舵机接口
  lcd_1.init();
  lcd_1.backlight();
  //lcd_1.begin(16, 2);//设定lcd行数
  //lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("Init");    //打印
}

void loop() {
  switch_value = digitalRead(SWITCH);  //读取数字针脚的值；

  //---定义舵机范围
  if (c == 190) 
  {
    c = 20;
  }
  if (d == 190) 
  {
    d = 20;
  }
  if (c == 10) 
  {
    c = 180;
  }
  if (d == 10) 
  {
    d = 180;
  }
  if (switch_value == LOW)  //去抖的作用，一般10-15ms；
  {
    delay(10);
  }

  if (switch_value == LOW)  //开关是1------------------
  {
    BUTTON_VALUE_1 = digitalRead(BUTTON1_M1);  //读取按钮red
    BUTTON_VALUE_2 = digitalRead(BUTTON2_M1);  //读取按钮green
    BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮blue
    BUTTON_VALUE_4 = digitalRead(BUTTON2_M2);  //读取按钮white
    Serial.print("Button red:");
    Serial.println(BUTTON_VALUE_1);  //显示按钮数据
    delay(100);
    lcd_1.setCursor(0, 0);               //将屏幕选中x,y
    lcd_1.print("motor1: ");             //打印
    lcd_1.print(c);                      //打印
    lcd_1.setCursor(0, 1);           //将屏幕选中x,y
    lcd_1.print("motor2: ");         //打印
    lcd_1.print(d);                  //打印
    //red
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
    //green
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

    //blue
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
    //white
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
    lcd_1.clear();                   //清除
  } 
  else  //开关是0-------------------
  {
    BUTTON_VALUE_1 = digitalRead(BUTTON1_M1);  //读取按钮red
    BUTTON_VALUE_2 = digitalRead(BUTTON2_M1);  //读取按钮green
    BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮blue
    BUTTON_VALUE_4 = digitalRead(BUTTON2_M2);  //读取按钮white
    lcd_1.clear();
    lcd_1.print("running trim?");//打印
    if (BUTTON_VALUE_4 == 1)
    {
      digitalWrite(blue,1);
    }
    else
    {

    }
  }
  servo_1.write(c);  //设置舵机旋转角度
  servo_2.write(d);  //设置舵机2旋转角度
  delay(10);                       // Delay a little bit to improve simulation performance

}
