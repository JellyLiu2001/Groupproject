#include "config.h"//定义所有针脚

void setup()  //初始化；
{
  Serial.begin(9600);
  lcd_1.init();                      // initialize the lcd 
  lcd_1.backlight();
  pinMode(SWITCH, INPUT);  //定义SWTICH为输出模式；
  pinMode(BUTTON1_M1, INPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  servo_1.attach(9);  //设定舵机接口
  servo_2.attach(10);  //设定舵机接口
  //-----------陀螺仪
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    lcd_1.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);

  //------------------自检-------------------------
  lcd_1.begin(20, 3);//设定lcd行数
  lcd_1.setCursor(0, 0);  //将屏幕选中x,y
  lcd_1.print("Welcome");    //打印
  lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("selftesting");    //打印
  delay(1000);
  for (i=0; i<=2;i++)
  {
  digitalWrite(red, 1);
  digitalWrite(green, 1);
  digitalWrite(blue, 1);
  delay(led_delay);
  digitalWrite(red, 0);
  digitalWrite(green, 0);
  digitalWrite(blue, 0);
  delay(led_delay);
  }
  servo_1.write(10);  //设置舵机旋转角度
  servo_2.write(10);  //设置舵机2旋转角度
  delay(500);
  servo_1.write(190);  //设置舵机旋转角度
  servo_2.write(190);  //设置舵机2旋转角度
  delay(500);
  lcd_1.setCursor(0, 1);  //将屏幕选中x,y
  lcd_1.print("Testing success");    //打印
  delay(200);
  //-----------------自检完成-------------------------------
}

void loop() {
  switch_value = digitalRead(SWITCH);  //读取数字针脚的值；
  //------定义舵机范围------
  if (c >= 190) 
  {
    c = 190;
  }
  if (d >= 190) 
  {
    d = 190;
  }
  if (c <= 10) 
  {
    c = 10;
  }
  if (d <= 10) 
  {
    d = 10;
  }
  if (switch_value == LOW)  //去抖的作用，一般10-15ms；
  {
    delay(10);
  }

  if (switch_value == LOW)  //开关是1------------------
  {
    digitalWrite(red, 0);
    BUTTON_VALUE_1 = digitalRead(BUTTON1_M1);  //读取按钮blue
    BUTTON_VALUE_2 = digitalRead(BUTTON2_M1);  //读取按钮white
    BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
    BUTTON_VALUE_4 = digitalRead(BUTTON2_M2);  //读取按钮red
    delay(100);
    pre_deg_c=current_c;//如果数据不改变, 屏幕不进行刷新
    current_c=c;
    pre_deg_d=current_d;
    current_d=d;
    if (pre_deg_c!=current_c||pre_deg_d!=current_d)//如果数据改变, 屏幕刷新
{
    lcd_1.clear();
    lcd_1.setCursor(0, 0);           //将屏幕选中x,y
    lcd_1.print("Motor1: ");         //打印
    lcd_1.print(c);                  //打印
    lcd_1.setCursor(0, 1);           //将屏幕选中x,y
    lcd_1.print("Motor2: ");         //打印
    lcd_1.print(d);                  //打印
}

//---------------------------------------------------------按钮---------------------------------------

    //blue
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
    //white
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

    //green
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
    //red
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
  } 
  else  //开关是0-------------------
  {
    digitalWrite(red,1);
    BUTTON_VALUE_1 = digitalRead(BUTTON1_M1);  //读取按钮blue
    BUTTON_VALUE_2 = digitalRead(BUTTON2_M1);  //读取按钮white
    BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
    BUTTON_VALUE_4 = digitalRead(BUTTON2_M2);  //读取按钮red
    lcd_1.setCursor(0, 0);
    lcd_1.print("white-Autotrim");//打印
    lcd_1.setCursor(0, 1);
    lcd_1.print("Blue-Automode");//打印
    lcd_1.setCursor(0, 2);
    lcd_1.print("Red-trim");//打印

    if (BUTTON_VALUE_2 == 1)//white-----------------配平---------------------
    {
      sensors_event_t event; 
      bno.getEvent(&event);
      ydeg=(event.orientation.y);
      zdeg=(event.orientation.z);
      delay(100);
      lcd_1.clear();
      lcd_1.print("Runing trim......");
      digitalWrite(red,0);
//----------------------z配平-------------------
      if (zdeg>=0)
      {z_balence=180-zdeg;}
      else if(zdeg<0)
      {
        z_balence=180+zdeg;
      }
//-------------------y配平-----------------------
        y_balence=0-ydeg;

      for (i=0;i<3;i++)
      {
        digitalWrite(blue,1);
        delay(led_delay);
        digitalWrite(blue,0);
        delay(led_delay);
      }
      lcd_1.setCursor(0, 2);
      lcd_1.print("Need to pitch ");
      lcd_1.print(z_balence);
      lcd_1.setCursor(0, 3);
      lcd_1.print("Need to roll ");
      lcd_1.print(y_balence);
      d=d+z_balence;
      c=c+y_balence;
      delay(1000);
      lcd_1.clear();
      lcd_1.print("Success");
      delay(1000);
    }
    if (BUTTON_VALUE_1 == 1)//blue-----------------自动模式---------------------
    {
      lcd_1.clear();
      lcd_1.setCursor(0,0);
      lcd_1.print("Running auto");
      lcd_1.setCursor(0,1);
      lcd_1.print("Checking connection");
      delay(1000);
      lcd_1.clear();
      while(connect==1)
      {
        BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
        lcd_1.setCursor(0, 0);
        lcd_1.print("Auto mode connected");
        servo_1.write(c);  //设置舵机旋转角度
        servo_2.write(d);  //设置舵机2旋转角度
        if (BUTTON_VALUE_3 == 1)
        {
          lcd_1.clear();
          lcd_1.print("Canceling");
          delay(1000);
          break;
        }
      }
    }

    if (BUTTON_VALUE_4 == 1)//red ------------------实时显示角度----------------
    
    {
      lcd_1.clear();
      while(1)
      {
        BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
        sensors_event_t event; 
        bno.getEvent(&event);
        lcd_1.setCursor(0,0);
        lcd_1.print("x: ");
        lcd_1.print(event.orientation.x, 4);
        lcd_1.setCursor(0,1);
        lcd_1.print("y: ");
        lcd_1.print(event.orientation.y, 4);
        lcd_1.setCursor(0,2);
        lcd_1.print("z: ");
        lcd_1.print(event.orientation.z, 4);
        //-----缩略显示----
        lcd_1.setCursor(12,0);
        lcd_1.print(event.orientation.x, 0);//航向 
        lcd_1.setCursor(12,1);
        lcd_1.print(event.orientation.y, 0);//左右
        lcd_1.setCursor(12,2);
        lcd_1.print(event.orientation.z, 0);//前后 

        delay(500);
        lcd_1.clear();
        BUTTON_VALUE_3 = digitalRead(BUTTON1_M2);  //读取按钮green
        if (BUTTON_VALUE_3 == 1)
        {
          break;
        }
      }
    }
  }
  servo_1.write(c);  //设置舵机旋转角度
  servo_2.write(d);  //设置舵机2旋转角度
  delay(10);// Delay a little bit to improve simulation performance
  
}