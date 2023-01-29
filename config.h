//---------gyro-----------
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//-----screen-----
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_1(0x27,20,3);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/*
z:179-180--179
y:1-0--1
Led:13
Button&motor
Button:2:3:4:5
Switch:6
Motor:9:10
Screen:sda:scl 0x27
Motor:20度为0 - 190
*/
#include <Servo.h>
//---舵机&led---
int pre_deg_c,current_c=0;
int current_d,pre_deg_d=0;
int a,b = 20;//定义旋转角度后c,d
int green=13;
int blue=12;
int red=11;
Servo servo_1;//声明舵机
Servo servo_2;//声明舵机2
int led_delay =100;
//---按钮---
int switch_value=0; //声明变量，用来存储按钮返回值HIGH或者LOW；
const int SWITCH=6;  //声明变量，开关接在第6针脚；
int BUTTON_VALUE_1, BUTTON_VALUE_2, BUTTON_VALUE_3, BUTTON_VALUE_4;//声明按键状态
//motor1
int BUTTON1_M1=5;//blue
int BUTTON2_M1=4;//white
//motor2
int BUTTON1_M2=3;//green
int BUTTON2_M2=2;//red
//校准舵机角度
int c =a+20;//舵机20为0度
int d =b+20;
int i;
//测试
int ydeg,zdeg;
int y_balence,z_balence;
//-------------给陈彦博的----------------
int connect=1;//发送信号1代表连接成功
int e,f;//发送旋转角度