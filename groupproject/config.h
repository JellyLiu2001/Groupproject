//-----screen-----
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x27,20,4);
/*
Led:13
Button&motor
Button:2:3:4:5
Switch:6
Motor:10:11
Screen:sda:scl 0*27
Motor:20度为0 
*/
#include <Servo.h>
//---舵机&led---
int a = 20;//定义旋转角度后c
int b = 20;//定义舵机2旋转角度后d
int green=13;
int red=11;
int blue=12;
Servo servo_1;//声明舵机
Servo servo_2;//声明舵机2
int led_delay =100;
//---按钮---
int switch_value=0; //声明变量，用来存储按钮返回值HIGH或者LOW；
const int SWITCH=6;  //声明变量，开关接在第6针脚；
int BUTTON_VALUE_1, BUTTON_VALUE_2, BUTTON_VALUE_3, BUTTON_VALUE_4;//声明按键状态
//motor1
int BUTTON1_M1=5;//声明按键针脚
int BUTTON2_M1=4;
//motor2
int BUTTON1_M2=3;
int BUTTON2_M2=2;
//校准舵机角度
int c =a+20;//舵机20为0度
int d =b+20;
