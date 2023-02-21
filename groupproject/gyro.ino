//Designed by Jelly Jinzhe Liu ab20328
void gyro_setup()
{
    if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    lcd_1.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}
//----------------------------------自动配平-----------------------------------------------
void gyro_loop()
{
      digitalWrite(red,0);
      sensors_event_t event; 
      bno.getEvent(&event);
      ydeg=(event.orientation.y);
      zdeg=(event.orientation.z);
      delay(100);
      lcd_1.clear();
      lcd_1.print("Runing trim......");

//z配平-------------------
      if (zdeg>=0)
      {z_balence=173-zdeg;}
      else if(zdeg<0)
      {
        z_balence=173+zdeg;
      }
//y配平-----------------------
      y_balence=2-ydeg;

}