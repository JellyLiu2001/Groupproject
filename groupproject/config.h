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
Motor:20 degrees = 0 - 190
*/
//EEPROM

//---------gyro-----------
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
Adafruit_BNO055 bno = Adafruit_BNO055(55);
float base_y = -0.375;  // Set the base angle for the gyroscope
float base_z = 175.937;

//-----screen-----
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_1(0x27, 20, 3);  // Set the LCD address to 0x27 for a 20-character and 4-line display
int lcd = 1;

//---servo---
#include <Servo.h>
int pre_deg_c, current_c = 0;  // Compare the current data with the previous data on the screen and refresh the screen if there is a change
int current_d, pre_deg_d = 0;
Servo servo_1;  // Declare servo 1
Servo servo_2;  // Declare servo 2
// Calibrate the servo angle
long num = 0;
int c = 90;  // Servo 20 degrees = 0 degrees
int d = 90;
int i;  //used for "for" function
//---led---
int green = 11;
int blue = 12;
int red = 13;
int led_delay = 100;
//---button---
int switch_value = 0;                                                        // Declare a variable to store the button return value HIGH or LOW;
const int SWITCH = 4;                                                        // Declare variable, switch connected to pin 6;
int BUTTON_VALUE_1_B, BUTTON_VALUE_2_W, BUTTON_VALUE_3_G, BUTTON_VALUE_4_R;  // Declare button status
// motor1
int BUTTON1_M1_BLUE = 5;   // Blue
int BUTTON2_M1_WHITE = 6;  // White
// motor2
int BUTTON1_M2_GREEN = 2;  // Green
int BUTTON2_M2_RED = 3;    // Red

// Balancing angle
int ydeg, zdeg;            // Store gyroscope input data
int y_balence, z_balence;  // Used to display the angle that needs to be balanced on the screen
//-------------Auto-balancing----------------
int connect = 1;   // Signal 1 means connection successful
int l[2];          // List of received angles
int stat = -1;     // Switch between 0 and 1 in the list
int trans = 0;     // Transmission monitoring
int deg_1, deg_2;  // Save the completed balancing data
int T_1, T_2 = 0;  // Compare the transmitted data with the balancing data
//-------------Pack-------
void transfer();             // Digital conversion
void selfcheck();            // Self-check
void gyro_setup();           // Gyroscope initialization
void gyro_display();         // Display gyroscope data on the screen
void gyro_trim();            // Gyroscope code when using auto-balancing
void init_setup();           // Initialize arduino code
void switch_value_manual();  // Manual mode
void switch_value_mode();    // Auto mode