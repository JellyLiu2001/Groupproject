#include <Servo.h>

int a = 0;//定义旋转角度
int b = 0;//定义舵机2旋转角度
Servo servo_1;//声明舵机
Servo servo_2;//声明舵机2

const int LED=13;    //声明变量 LED灯接在13针脚-------------------------；
const int SWITCH=7;  //声明变量，开关接在第7针脚；

int switch_value=0; //声明变量，用来存储按钮返回值HIGH或者LOW；
int val_old=0;//声明变量，存储上一次按钮返回值；比对val和val_old的值，来判断按钮是按下还是抬起 //switch_value==LOW && val_old==HIGHT 抬起状态；val==HIGH && val_old==LOW 按下状态；
int state=0;//0 off,1 on 声明变量，起到中转的作用，小技巧；

int BUTTON_VALUE;//声明按键状态
int BUTTON_1=1;//声明按键针脚
void setup() //初始化；
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT); //定义LED灯输入模式----------------；
  pinMode(SWITCH,INPUT);//定义SWTICH为输出模式；
  pinMode(BUTTON_1,INPUT);
  servo_1.attach(1);//设定舵机接口
  servo_2.attach(2);//设定舵机接口
}

void loop()
 {
  switch_value=digitalRead(SWITCH);//读取数字针脚的值；
	  if((switch_value==HIGH) && (val_old==LOW))//比较前一次和现在的按钮返回的值，
	
  {
    state=1-state;//只有现在按下按钮这个状态下，才改变state的值
  }
  if((switch_value==LOW && val_old==HIGH)) //去抖的作用，一般10-15ms；
    {
      delay(10);
    }
  val_old=switch_value;//把现在按钮返回的值赋予val_old；
  if(state==1)//开关是1------------------
    {
          BUTTON_VALUE=digitalRead(BUTTON_1);//读取按钮1
          Serial.println(BUTTON_VALUE);//显示按钮数据
          delay(100);
          if(BUTTON_VALUE==0)//如果按钮断开---------------------
          {

          }
          else//按钮打开--------------------
          {
            digitalWrite(LED,LOW);
            }
    }
  else//开关是0-------------------
   {
     digitalWrite(LED,LOW);
   }
  servo_1.write(a);//设置舵机旋转角度
  servo_2.write(b);//设置舵机2旋转角度
  Serial.println(servo_1.read());//打印舵机角度
  Serial.println(servo_2.read());//打印舵机2角度
  delay(10); // Delay a little bit to improve simulation performance
}
