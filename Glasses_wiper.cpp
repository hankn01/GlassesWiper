#include <DHT11.h>
#include <Servo.h>

int pin=2;            
DHT11 dht11(pin);
Servo leftservo;
Servo rightservo;

int stopPin = 8;
int wipePin = 9;
int autoPin = 10;

int mode = 0;
int pos = 0;
void setup()
{
   Serial.begin(9600); 
  pinMode(stopPin,INPUT_PULLUP);
  pinMode(wipePin,INPUT_PULLUP);
  pinMode(autoPin,INPUT_PULLUP);
  leftservo.attach(5);
  rightservo.attach(6);
}
 
void loop()
{
  int err;
  float temp, humi;

  
  if(digitalRead(stopPin)==LOW)
  {
    mode = 1;
  }
  if(digitalRead(wipePin)==LOW)
  {
    mode = 2;
    
  }
  if(digitalRead(autoPin)==LOW)
  {
    mode = 3;
    
  }
  if(mode==3)
{
  err=dht11.read(humi, temp);
  
  if((err)==0) 
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
    if(humi>=70)
    {
    for(pos=0;pos<=180;pos+=1) {
      leftservo.write(pos);
      rightservo.write(pos);
      delay(10);
      
    }
    for(pos=180;pos>=0;pos-=1) {
      leftservo.write(pos);
      rightservo.write(pos);
      delay(10);
    }
    }
    else {
      Serial.println("HUMIDITY LOW");
    }
  }
  else                                
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(2000);                      
}
else if(mode==2)
{
for(pos=0;pos<=180;pos+=1) {
      leftservo.write(pos);
      rightservo.write(pos);
      delay(10);
      
    }
    for(pos=180;pos>=0;pos-=1) {
      leftservo.write(pos);
      rightservo.write(pos);
      delay(10);
    }

  
}
  
}
 
