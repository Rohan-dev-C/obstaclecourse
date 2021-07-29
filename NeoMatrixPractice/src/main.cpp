#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include "Button.h"
#include "segment7.h"
#include "RGBLED.h"
#include "timer.h"
#include "pixel.h"
#include "obstacle.h"

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 22, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neo = Adafruit_NeoPixel(12, 4);

enum GameStates
{
  LoadingScreen,
  Level1,
  Level2,
  Level3,
  Level4,
  DeadScreen,
  WinScreen,
};

struct main
{
  GameStates currentState;
};


main Josiah;
Button butonn = Button{29};
pixel Obstacles[10]; //= {pixel(), pixel(), pixel(), pixel(), pixel(), pixel(), pixel(), pixel(), pixel(), pixel()};
pixel Obstacles2[15];
pixel Obstacles3[20];
pixel Player = pixel{4, 7, 255, 255, 255};
obstacle moving[5];  



unsigned long target = 100 + millis();
int i = 0;

int movingX = 0; 

unsigned long target2 = 100 + millis(); 

void LoadScreen(Adafruit_NeoMatrix &matrix)
{

  for (int j = 0; j < 8; j++)
  {
    matrix.drawPixel(i, j, matrix.Color(255, 0, 255));
  }
  for (int j = 0; j < 8; j++)
  {
    matrix.drawPixel(j, i, matrix.Color(0, 255, 0));
  }

  for (int j = 0; j < 8; j++)
  {
    matrix.drawPixel(8 - j, i, matrix.Color(255, 0, 255));
  }

  for (int j = 0; j < 8; j++)
  {
    matrix.drawPixel(j, 8 - i, matrix.Color(0, 255, 255));
  }

  for (int j = 0; j < 8; j++)
  {
    matrix.drawPixel(8 - j, 8 - i, matrix.Color(255, 255, 255));
  }
  if (millis() >= (unsigned long)target)
  {
    i++;
    target = 100 + millis();
    if (i > 7)
    {
      i = 0;
    }
  }
}
void readFromKeys(pixel &Player)
{
  char khar = (char)Serial.read();
  if (khar == 'r' && Player.y < 7)
  {
    Player.y++;
  }
  else if (khar == 'l' && Player.y > -1)
  {
    Player.y--;
  }
  else if (khar == 'u' && Player.x < 7)
  {
    Player.x++;
  }
  else if (khar == 'd' && Player.x > 0)
  {
    Player.x--;
  }
}
int count = 0;
void setup()
{
  matrix.begin();
  matrix.setBrightness(40);
  matrix.clear();

  butonn.init();
  Josiah.currentState = GameStates::LoadingScreen;

  //randomSeed(8723455);
  //randomSeed(3240932);
  //randomSeed(423768);
  randomSeed(5326323);
  //randomSeed(47652838); 


  Serial.begin(115200);

  neo.begin(); 
  neo.setBrightness(50); 

   count = 0;
   for (int i = 0; i < 10; i++)
   {
     Obstacles[i].x = 0;
     Obstacles[i].y = 1;
     Obstacles[i].r = 255;
     Obstacles[i].g = 0;
     Obstacles[i].b = 0;
   } 
  for(int i = 0; i < 10; i++)
  {
    Obstacles[i].generate(1, false, matrix); 
  }
  for (int i = 0; i < 10; i++)
  {
    Obstacles[i].generate(1, false, matrix);
  }
  for (int i = 0; i < 15; i++)
  {
    Obstacles2[i].generate(1, false, matrix); 
  }
  for (int  i = 0; i < 20; i++)
  {
    Obstacles3[i].generate(1, false, matrix); 
    /* code */
  }
  
    for(int i = 0; i < 5; i++)
    {
      moving[i].xSpeed = 1; 
      moving[i].y = i + 2; 
      moving[i].r = 255; 
      moving[i].g = 150; 
      moving[i].b = 0; 
      //FFA500
    }

}

void loop()
{
  switch (Josiah.currentState)
  {
    case LoadingScreen:
     LoadScreen(matrix);
     Serial.read();
     if (butonn.isClicked())
      {
        Player.x = 4; 
        Player.y = 7;
        Serial.print('a'); 
       matrix.clear();
       Josiah.currentState = Level1;
      }
    break;
  case Level1:
    matrix.drawPixel(Player.x, Player.y, matrix.Color(Player.r, Player.g, Player.b));
    readFromKeys(Player); 
    for(int i = 0; i < 10; i++)
    {
      matrix.drawPixel(Obstacles[i].x, Obstacles[i].y, matrix.Color(Obstacles[i].r, Obstacles[i].g, Obstacles[i].b));
    }
    for(int i = 0; i < 10;i++)
    {
      if((Player.x == Obstacles[i].x && Player.y == Obstacles[i].y))
      {
        
         Serial.print('j');
        Josiah.currentState = DeadScreen; 
      }
    }
    moving[0].move(); 
    matrix.drawPixel(moving[0].x, moving[0].y, matrix.Color(moving[0].r, moving[0].g, moving[0].b )); 
    if(Player.x == moving[0].x && Player.y == moving[0].y)
       {
         Serial.print('j');
        Josiah.currentState = DeadScreen; 
       }
    if(Player.y < 0)
    {
      Player.y = 7; 
      matrix.clear(); 
      Josiah.currentState = Level2; 
    }
    break;

    case Level2: 
      matrix.drawPixel(Player.x, Player.y, matrix.Color(Player.r, Player.g, Player.b));
      readFromKeys(Player); 
      for(int i = 0; i < 15; i++)
      {
        matrix.drawPixel(Obstacles2[i].x, Obstacles2[i].y, matrix.Color(Obstacles2[i].r, Obstacles2[i].g, Obstacles2[i].b));
      }   
      for(int i = 1; i < 3; i++)
      {
        moving[i].move(); 
        matrix.drawPixel(moving[i].x, moving[i].y,  matrix.Color(moving[0].r, moving[0].g, moving[0].b ));
      }      
      for(int i = 0; i < 15;i++)
      {
        if((Player.x == Obstacles2[i].x && Player.y == Obstacles2[i].y))
        {
          
          Serial.print('j');
          Josiah.currentState = DeadScreen; 
        }
      }
      for(int i = 1; i < 3;i++)   
      {
        if((Player.x == moving[i].x && Player.y == moving[i].y))
        {
          Serial.print('j');
          Josiah.currentState = DeadScreen; 
        }
      } 
      if(Player.y < 0)
      {
        Player.y = 7; 
        Josiah.currentState = Level3; 
      }
      break; 
    
    case Level3: 
      matrix.drawPixel(Player.x, Player.y, matrix.Color(Player.r, Player.g, Player.b));
      readFromKeys(Player); 
      for(int i = 0; i < 20; i++)
      {
        matrix.drawPixel(Obstacles3[i].x, Obstacles3[i].y, matrix.Color(Obstacles3[i].r, Obstacles3[i].g, Obstacles3[i].b));
      }   
      for(int i = 0; i < 5  ; i++)
      {
        moving[i].move(); 
        matrix.drawPixel(moving[i].x, moving[i].y,  matrix.Color(moving[0].r, moving[0].g, moving[0].b ));
      }    
      for(int i = 0; i < 20;i++)
      {
        if((Player.x == Obstacles3[i].x && Player.y == Obstacles3[i].y))
        {
          
         Serial.print('j');
          Josiah.currentState = DeadScreen; 
        }
      }
      if(Player.y < 0)
      {
        Serial.print('b'); 
        Player.y = 7; 
        Josiah.currentState = WinScreen; 
      }
      for(int i = 0; i < 5;i++)
      {
        if((Player.x == moving[i].x && Player.y == moving[i].y))
        {
          Serial.print('j'); 
          Josiah.currentState = DeadScreen; 
        }
      } 
      break; 

    case DeadScreen: 
      Serial.read(); 
      matrix.fillScreen(matrix.Color(255, 0, 0)); 
      if(butonn.isClicked())
      {
        matrix.clear(); 
        Player.x = 4; 
        Player.y = 7; 
        Josiah.currentState = LoadingScreen;
      }
      break; 
    case WinScreen:
      Serial.read();  
      matrix.fillScreen(matrix.Color(0, 255 ,0));
      // for(int i = 0; i < 8; i++)
      // { 
      //     matrix.drawPixel(i, 2, matrix.Color(0, 255, 0)); 
      // }
      for (int i = 0; i < 12; i++)
      {
        neo.setPixelColor(i, (i+1)*6*21, (i+1)*6*16, (i+1)*6*18); 
      }
      if(butonn.isClicked())
      {
        Player.x = 4; 
        Player.y = 7; 
        
        matrix.clear(); 
        Josiah.currentState = LoadingScreen;
      }
      break;
  }
  matrix.show();
  neo.show(); 
  matrix.clear();
}