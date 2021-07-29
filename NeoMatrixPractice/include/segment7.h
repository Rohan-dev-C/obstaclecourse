#pragma once
#include <Arduino.h>


class segment7
{
  private:

  int pinCount; 
  int* pins; 
  bool isCathode; 
bool numbers[10][8] = 
{
  {1, 1, 1, 1, 1, 1, 0, 0}, //0
  {0, 1, 1, 0, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1, 0}, //2
  {1, 1, 1, 1, 0, 0, 1, 0},//3
  {0, 1, 1, 0, 0, 1, 1, 0}, //4
  {1, 0, 1, 1, 0, 1, 1, 0},//5
  {1, 0, 1, 1, 1, 1, 1, 0}, //6
  {1, 1, 1, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 0}, //8
  {1, 1, 1, 1, 0, 1, 1, 0}, //9
};  
//int pins[8] = {3,4,6,12,13,2,7,5};
  public: 

segment7()
{
  
}

  segment7(int* pins, int pinCount, bool isCathode) : pins{pins}, pinCount{pinCount}, isCathode{isCathode}
  {
  }

  void setNumber(int number); 

  void init(); 
  
  void off(); 
  void segmentControl(int pin, bool On);
};