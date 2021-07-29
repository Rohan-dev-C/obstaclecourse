#pragma once
#include <Arduino.h>
#include <Adafruit_NeoMatrix.h>
class pixel
{
    private:

    public:
    uint8_t currentIndex;
    uint8_t r; 
    uint8_t g; 
    uint8_t b; 
    int x; 
    int y; 
    bool isHorizontal; 
    
    //start rgb variables and end rgb variables

    pixel()
    {
        
    }
    
    pixel(int x, int y, uint8_t r =  0, uint8_t g = 0, uint8_t b = 0) : x{x}, y{y}, r{r}, g{g}, b{b}, isHorizontal{isHorizontal}
    {
    }

    void generate(int size, bool horizontal, Adafruit_NeoMatrix& matrix); 
 
};;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


