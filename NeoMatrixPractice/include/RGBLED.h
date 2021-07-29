#pragma once
#include <Arduino.h>


class RGBLED
{
  private: 

  int* pins; 

  int RValue; 
  int GValue;
  int BValue; 
  


  
  public: 
    bool ISCATHODE; 
  bool isActive; 
  bool wasActive; 
  unsigned long targetTime; 

  RGBLED()
  {
    
  }

  RGBLED(int* pins, int RValue, int GValue, int BValue, unsigned long targetTime) : pins{pins}, RValue{RValue}, GValue{GValue}, BValue{BValue}, targetTime{targetTime}, isActive{false}, wasActive{false}
  {
    
  }

  void Off();

  void init(); 

  void color(int red, int green, int blue); 

  void startBlink(unsigned long blinkDuration);

  void blinkLED(int red, int green, int blue);

  
};