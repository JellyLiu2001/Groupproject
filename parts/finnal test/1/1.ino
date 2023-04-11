// n is an array of 10 integers
int n[320] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37 };

void setup () {

    Serial.begin(9600); //串口初始化 
    for(int i=0;i <320;++i)
    {
      Serial.print (n[i]);
      Serial.print ('\r') ;
    }
} 


void loop () 
{

}
