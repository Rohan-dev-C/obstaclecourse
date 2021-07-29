#include "pixel.h"
#include <Adafruit_NeoMatrix.h> 



void pixel::generate(int size, bool horizontal, Adafruit_NeoMatrix& matrix)
{
    this->x = random(0, 8); 
    this->y = random(1,7); 
    this->r = 255; 
}