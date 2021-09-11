#include <Arduino.h>
#include <Servo.h>

Servo shoulder;
Servo elbow; 
Servo hand1;
Servo hand2; 

#define Xpin A0 
#define Ypin A1
#define Switch 12

void Shoulder()
{
  int valXraw= analogRead(Xpin);           
  int valX = map(valXraw, 0, 1023, 0, 180);

  shoulder.write(valX);        
  delay(50); 
}

void Elbow()
{
  int valYraw= analogRead(Ypin);           
  int valY = map(valYraw, 0, 1023, 0, 180);

  elbow.write(valY);        
  delay(50); 
}

void hand()
{
  bool handEnable = digitalRead (Switch);

  const int centerPos = 90;
  
  if (handEnable == true)
  {
    hand1.write (0);
    hand2.write (180);
  }

  else 
  {
    hand1.write (centerPos);
    hand2.write (centerPos);
  }
}

void setup() 
{
  shoulder.attach(11);
  elbow.attach(10);
  hand1.attach(6);
  hand2.attach(5);
  pinMode (Switch, INPUT);  
}

void loop() 
{
  Shoulder();
  Elbow();  
  hand();                        
}