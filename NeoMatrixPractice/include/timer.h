#pragma once
#include <Arduino.h>

class timer
{
    private:
   
    public:
    unsigned long startTime; 
    unsigned long endTime; 
    unsigned long currentTime;
    bool isActive; 

   
    timer() : startTime{0}, endTime{0}
    {

    }

    void start(unsigned long length); 

    float percentDone(); 

    

};



