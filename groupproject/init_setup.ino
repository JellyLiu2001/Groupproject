//Designed by Jelly Jinzhe Liu ab20328
void init_setup() {
  Serial.begin(9600);
  lcd_1.init();  // initialize the lcd
  lcd_1.backlight();
  lcd_1.begin(20, 3);      // Set the number of rows of the LCD
  pinMode(SWITCH, INPUT);  // Define SWITCH as an input mode
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  servo_1.attach(9);       // Set the interface of servo 1
  servo_2.attach(10);      // Set the interface of servo 2
  deg_1 = EEPROM.read(0);  // Store the angle in the EEPROM
  deg_2 = EEPROM.read(1);
}