#include <Servo.h>
#include "config.h"

void setup() //初始化；
{
  Serial.begin(9600);
  pinMode(SWITCH,INPUT);//定义SWTICH为输出模式；
  pinMode(BUTTON1_M1,INPUT);
  pinMode(led,OUTPUT);
  servo_1.attach(10);//设定舵机接口
  servo_2.attach(11);//设定舵机接口
}

void loop()
 {
  switch_value=digitalRead(SWITCH);//读取数字针脚的值；
  Serial.print("Switch:");
  Serial.println(switch_value);
    if (c==190)
    {
      c=20;
    }
    if(d==190)
    {
      d=20;
    }
    if(c==10)
    {
      c=180;
    } 
    if(d==10)
    {
      d=180;
    }
    if(switch_value==LOW) //去抖的作用，一般10-15ms；
    {
      delay(10);
    }
  if(switch_value==LOW)//开关是1------------------
    {
          BUTTON_VALUE_1=digitalRead(BUTTON1_M1);//读取按钮red
          BUTTON_VALUE_2=digitalRead(BUTTON2_M1);//读取按钮green
          BUTTON_VALUE_3=digitalRead(BUTTON1_M2);//读取按钮blue
          BUTTON_VALUE_4=digitalRead(BUTTON2_M2);//读取按钮white
          Serial.print("Button red:");
          Serial.println(BUTTON_VALUE_1);//显示按钮数据
          delay(100);
//red
          if(BUTTON_VALUE_1==0)//如果按钮断开---------------------
          {

          }
          else//按钮打开--------------------
          {
            c=c+5;
            digitalWrite(led,1);
            delay(led_delay);
            digitalWrite(led,0);
          }
//green
          if(BUTTON_VALUE_2==0)//如果按钮断开---------------------
          {

          }
          else//按钮打开--------------------
          {
            c=c-5;
            digitalWrite(led,1);
            delay(led_delay);
            digitalWrite(led,0);
          }

//blue
          if(BUTTON_VALUE_3==0)//如果按钮断开---------------------
          {

          }
          else//按钮打开--------------------
          {
            d=d+5;
            digitalWrite(led,1);
            delay(led_delay);
            digitalWrite(led,0);
          }
//white
          if(BUTTON_VALUE_4==0)//如果按钮断开---------------------
          {

          }
          else//按钮打开--------------------
          {
            d=d-5;
            digitalWrite(led,1);
            delay(led_delay);
            digitalWrite(led,0);        
          }
    }
  else//开关是0-------------------
   {
    digitalWrite(led,1);
   }
  servo_1.write(c);//设置舵机旋转角度
  servo_2.write(d);//设置舵机2旋转角度
  Serial.print("Servo1:");
  Serial.println(servo_1.read());//打印舵机角度
  Serial.print("Servo2:");
  Serial.println(servo_2.read());//打印舵机2角度
  delay(10); // Delay a little bit to improve simulation performance
}
