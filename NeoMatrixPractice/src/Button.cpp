#include "Button.h"



void Button::init()
{
  pinMode(pin, INPUT_PULLUP); 
  isDown = false; 
}


bool Button::isClicked()
{
  if(digitalRead(pin) == LOW)
  {
    isDown = true;   
  }
  else if(isDown)
  {
    isDown = false;  
    return true;    
  }
  return false; 
}


bool Button::isItDown()
{
  if(digitalRead(pin) == LOW)
  {
    return true; 
  }
  else
  {
    return false;
  }
}