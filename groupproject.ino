#include <Servo.h>
//button:2-3-4-5
//switch:6
//motor:10-11
//motor 20度为0
int a = 20;//定义旋转角度
int b = 20;//定义舵机2旋转角度
int led=13;
Servo servo_1;//声明舵机
Servo servo_2;//声明舵机2
int switch_value=0; //声明变量，用来存储按钮返回值HIGH或者LOW；
int val_old=0;//声明变量，存储上一次按钮返回值；比对val和val_old的值，来判断按钮是按下还是抬起 //switch_value==LOW && val_old==HIGHT 抬起状态；val==HIGH && val_old==LOW 按下状态；
int state=0;//0 off,1 on 声明变量，起到中转的作用，小技巧；
int led_delay =100;
const int SWITCH=6;  //声明变量，开关接在第6针脚；
int BUTTON_VALUE_1, BUTTON_VALUE_2, BUTTON_VALUE_3, BUTTON_VALUE_4;//声明按键状态
//motor1
int BUTTON1_M1=5;//声明按键针脚
int BUTTON2_M1=4;
//motor2
int BUTTON1_M2=3;
int BUTTON2_M2=2;
int c =a+20;//舵机20为0度
int d =b+20;

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
