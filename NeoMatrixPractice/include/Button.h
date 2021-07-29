#pragma once
#include <Arduino.h>


class Button
{
  private:
 
  int pin; 
  bool isDown = false; 
  unsigned long targetTime = 0; 


  public: 

  Button(int pin) : pin{pin} {}
  
  bool isClicked();
  void init();
  bool isItDown(); 
}; 