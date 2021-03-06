/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"

int senFrent = 8;
int lap = 0;

int main()
{  
  while(1)
  {
    drive_ramp(60,60);
    while(ping_cm(senFrent) > 15) {
       pause(5); 
       }
    drive_ramp(0,0);
    
    drive_goto(-26,25);
   lap--;
        
    while(lap != 0)
    {
       drive_goto(25,-26);
  lap++;
     
      if(ping_cm(senFrent) < 15)
      {
        drive_goto(-26,25);

  lap--;
      }

      else
      {
        drive_goto(64,64);
        continue;
      }       
      
      if(ping_cm(senFrent) < 15)
      {
       drive_goto(-26,25);

  lap--; 
      }
      
      drive_goto(64,64);         
    }    
  }    
}
