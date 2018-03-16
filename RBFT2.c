/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "abdrive.h"
#include "simpletools.h"
#include "ping.h"

int lap= 0;
int senFrent = 8;

int main()
{
  while(1)
  {
    drive_speed(60,60);
    while(ping_cm(senFrent) > 21) { pause(5); }
    drive_speed(0,0);
    
    go_left();
    
    while(lap != 0)
    {
      go_right();
     
      if(ping_cm(senFrent) < 15)
      {
        go_left();
      }
      // derecha libre, ir a la derecha
      else
      {
        drive_goto(60,60);
        continue;
      }       
      
      // revisar frente
      // si hay algo, la unica opcion es cruzar a la izquierda
      if(ping_cm(senFrent) < 15)
      {
        go_left();
      }
      
      // si el frente esta libre avanzar una revolucion
      if(ping_cm(senFrent) > 26)
      { 
        drive_goto(64,64);
      }             
    }    
  }    
}