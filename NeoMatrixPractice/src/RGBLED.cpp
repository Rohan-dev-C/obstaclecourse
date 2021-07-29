#include "RGBLED.h"


void RGBLED::init()
{
  for(int i = 0; i < 3; i++)
  {
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], ISCATHODE ? 0:255);
  }
}



void RGBLED::Off()
{
  for(int i =0 ;i < 3; i++)
  {
    analogWrite(pins[i], ISCATHODE ? 0:255);
  }
}


void RGBLED::color(int red, int green, int blue)
{
  analogWrite(pins[0], !ISCATHODE ? 255-red:red); 
  analogWrite(pins[1], !ISCATHODE ? 255-green:green); 
  analogWrite(pins[2], !ISCATHODE ? 255-blue:blue); 
}


void RGBLED::startBlink(unsigned long blinkDuration)
{
  targetTime = blinkDuration + millis();
}

void RGBLED::blinkLED( int red, int green, int blue)
{
  wasActive = isActive;
  if(millis() < targetTime)
  {
    isActive = true;
    analogWrite(pins[1], red); 
    analogWrite(pins[2], green); 
    analogWrite(pins[0], blue); 
  }
  else  
  {
    isActive = false; 
    analogWrite(pins[0], 0); 
    analogWrite(pins[1], 0);  
    analogWrite(pins[2], 0); 
  }
}