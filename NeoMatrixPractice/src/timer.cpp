#include "timer.h"

void timer::start(unsigned long length)
{
    startTime = millis(); 
    currentTime = millis(); 
    endTime = length;
}

float timer::percentDone()
{
    currentTime = millis();

    return (float)(currentTime - startTime)/(float)endTime < 1 ? (float)(currentTime - startTime)/(float)endTime:1; 
}