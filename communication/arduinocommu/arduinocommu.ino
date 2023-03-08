#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd_1(0x27, 20, 3);  // set the LCD address to 0x27
Servo servo_9;
Servo servo_10;
int l[2];
int c, d=100;  //舵机角度
int stat = -1;
int trans = 0;  //传输监测
void setup() {
  Serial.begin(9600);
  lcd_1.init();
  lcd_1.backlight();
  lcd_1.begin(0X27, 20, 3);
  lcd_1.print("SB");
  servo_9.attach(9, 1000, 2500);
  servo_10.attach(10, 1000, 2500);
  pinMode(13, OUTPUT);  //设置13号端口作为输出端口
  pinMode(12, OUTPUT);  //设置13号端口作为输出端口
  //digitalWrite(13,HIGH);//让灯开始时亮
}
void loop() {
  while (Serial.available() > 0)  //当有信号的时候
  {
    trans = 1;
    stat = stat + 1;
    l[stat] = Serial.parseInt();
    c = l[0];
    d = l[1];
    servo_9.write(c);
    servo_10.write(d);
    lcd_1.print(trans);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("motor1:");
    lcd_1.print(l[0]);
    lcd_1.print("|");
    lcd_1.setCursor(0, 1);
    lcd_1.print("motor2:");
    lcd_1.print(l[1]);
    lcd_1.print("|");
    lcd_1.setCursor(0, 2);
    lcd_1.print("current status:");
    lcd_1.print(stat + 1);
    if (stat == 1) { stat = -1; }
  }
  trans = 0;
  lcd_1.setCursor(0, 3);
  lcd_1.print(trans);
}