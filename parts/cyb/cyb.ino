//Designed by Jelly Jinzhe Liu ab20328
/*
z:179-180--179
y:1-0--1
Led:13:12:11
Button&motor
Button:2:3:5:6
Switch:4
Motor:9:10
Screen:sda:scl 0x27
Motor:20度为0 - 190
*/
//---------gyro-----------
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
Adafruit_BNO055 bno = Adafruit_BNO055(55);
float base_y = 0.4375;  //设置基准角度
float base_z = 176.5;

//-----screen-----
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_1(0x27, 20, 3);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int lcd = 1;

//---舵机---
#include <Servo.h>
int pre_deg_c, current_c = 0;
int current_d, pre_deg_d = 0;
Servo servo_1;  //声明舵机
Servo servo_2;  //声明舵机2
//校准舵机角度
long num = 0;
int c = 90;  //舵机20为0度
int d = 90;
int i;
//---led---
int green = 11;
int blue = 12;
int red = 13;
int led_delay = 100;
//---按钮---
int switch_value = 0;                                                        //声明变量，用来存储按钮返回值HIGH或者LOW；
const int SWITCH = 4;                                                        //声明变量，开关接在第6针脚；
int BUTTON_VALUE_1_B, BUTTON_VALUE_2_W, BUTTON_VALUE_3_G, BUTTON_VALUE_4_R;  //声明按键状态
                                                                             //motor1
int BUTTON1_M1_BLUE = 5;                                                     //blue
int BUTTON2_M1_WHITE = 6;                                                    //white
                                                                             //motor2
int BUTTON1_M2_GREEN = 2;                                                    //green
int BUTTON2_M2_RED = 3;                                                      //red

//配平角度
int ydeg, zdeg;
int y_balence, z_balence;
//-------------自动配平----------------
int connect = 1;  //发送信号1代表连接成功
int l[2];         //接收角度的列表
int stat = -1;    //在列表中0,1的切换
int trans = 0;    //传输监测
int degree_1[70];//定义舵机1的角度
int degree_2[70];//定义舵机2的角度
int deg_a,deg_b;//设置舵机循环范围
void setup() {
  Serial.begin(9600);
  lcd_1.init();  // initialize the lcd
  lcd_1.backlight();
  lcd_1.begin(20, 3);      //设定lcd行数
  pinMode(SWITCH, INPUT);  //定义SWTICH为输出模式；
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  servo_1.attach(9);   //设定舵机接口
  servo_2.attach(10);  //设定舵机接口
}


//------------------------------------------------------------------------------------------------------------------------------------
void loop(){
while (connect == 1)  //与其他建立连接
{

  digitalWrite(green, 1);
  while (Serial.available() > 0)  //当有信号的时候
  {
    trans = 1;
    stat = stat + 1;
    // l[stat] = Serial.parseInt();
    // c = l[0];  //等于第一次传回数据
    // d = l[1];  //等于第二次传回的数据
    num = Serial.parseInt();
    Serial.flush();
    // Serial.println(num);
    if (num != 0) {
      c = num / 1000;
      // Serial.println(c);
      d = num % 1000;
      // Serial.println(d);
      lcd_1.print(trans);
      lcd_1.setCursor(0, 0);
      lcd_1.clear();
      lcd_1.print("motor1:");
      lcd_1.print(c);
      lcd_1.print("|");
      lcd_1.setCursor(0, 1);
      lcd_1.print("motor2:");
      lcd_1.print(d);
      lcd_1.print("|");
      lcd_1.setCursor(0, 2);
      lcd_1.print("current status:");
      lcd_1.print(stat + 1);
      servo_1.write(c);  //改变舵机位置
      servo_2.write(d);
      if (stat == 1) { stat = -1; }
    }
  }
  trans = 0;
  lcd_1.setCursor(0, 3);
  lcd_1.print("Trans:");
  lcd_1.print(trans);
}
}