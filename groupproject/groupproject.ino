//Designed by Jelly Jinzhe Liu ab20328
#include "config.h"//定义所有针脚
void setup()  //初始化；
{
  init_setup();//模式声明(LCD, LED, 舵机)
  gyro_setup();//陀螺仪声明
  selfcheck();//自检声明
}

void loop() {
  switch_value = digitalRead(SWITCH);  //读取数字针脚的值；
  transfer();//定义舵机范围
  if (switch_value == LOW)  //开关是1
  {
    switch_value_manual();//手动调整舵机
  } 
  else  //开关是0
  {
    switch_value_mode();//模式选择
  }
  servo_1.write(c);  //设置舵机旋转角度
  servo_2.write(d);  //设置舵机2旋转角度
  
}