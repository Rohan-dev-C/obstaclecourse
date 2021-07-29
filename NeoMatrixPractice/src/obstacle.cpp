#include "obstacle.h"

void obstacle::move()
{
    if(millis() - timeSinceLastMove > 100)
    {
        x+= xSpeed;
        timeSinceLastMove = millis(); 
        if(x >= 7 )
        {
            xSpeed = -xSpeed; 
        } 
        else if(x <= 0)
        {
            xSpeed = -xSpeed; 
        }
    }
}
