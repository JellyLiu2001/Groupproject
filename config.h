//-----screen-----
#include <LiquidCrystal.h>

// 初始化针脚
const int rs = 3, en = 5, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//-----button&mnotor-----
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