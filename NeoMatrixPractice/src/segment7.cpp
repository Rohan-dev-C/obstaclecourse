#include "segment7.h"

void segment7::init()
{
  for(int i = 0; i < pinCount; i++)
  {
    pinMode(pins[i], OUTPUT); 
    digitalWrite(pins[i], isCathode ? LOW:HIGH); 
  }
  
}



void segment7::setNumber(int number)
{
  for(int i = 0;i < pinCount; i++)
  {
    if(isCathode == false)
    {
     // Serial.println(numbers[number][i] == 0 ? '0' : '1');
      digitalWrite(pins[i], numbers[number][i] == 0 ? HIGH:LOW); 
    }
    else
    {
      digitalWrite(pins[i], numbers[number][i] == 0 ? LOW:HIGH); 
    }

    //digitalWrite(pins[i], isCathode ? DisplayNumbers[number][i] == 0 ? HIGH : LOW : DisplayNumbers[number][i] == 0 ? LOW : HIGH); 
  }
}

void segment7::off()
{
  for(int i = 0; i < pinCount; i++)
  {
    if(isCathode)
    {
      digitalWrite(pins[i], LOW); 
    }
    else
    {
      digitalWrite(pins[i], HIGH); 
    }
  }

}

void segment7::segmentControl(int pin, bool On)
{
  digitalWrite(pin, isCathode ? On ? HIGH : LOW : On ? LOW : HIGH); 
}