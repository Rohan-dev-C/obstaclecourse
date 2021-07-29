#pragma once
#include <Arduino.h>
#include <Adafruit_NeoMatrix.h> 
#include <Adafruit_NeoPixel.h> 
#include "pixel.h"

class obstacle : public pixel
{
    private:
    unsigned long timeSinceLastMove; 

    public:
    
    int xSpeed; 
    int ySpeed; 
    obstacle()
    {

    }
    obstacle(int x, int y, uint8_t r, uint8_t g, uint8_t b) : pixel(x, y, r, g, b) , timeSinceLastMove{0}
    {

    }

    void move(); 
};


