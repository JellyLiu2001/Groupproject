//Designed by Jelly Jinzhe Liu ab20328
void init_setup()
{
  Serial.begin(9600);
  lcd_1.init();                      // initialize the lcd 
  lcd_1.backlight();
  lcd_1.begin(20, 3);//设定lcd行数
  pinMode(SWITCH, INPUT);  //定义SWTICH为输出模式；
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  servo_1.attach(9);  //设定舵机接口
  servo_2.attach(10);  //设定舵机接口
}