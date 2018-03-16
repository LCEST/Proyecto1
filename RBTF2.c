#include "abdrive.h"
#include "simpletools.h"
#include "ping.h"

int lap= 0;
int senFrent = 8;

int main()
{
  while(1)
  {
    drive_ramp(115,115);
    while(ping_cm(senFrent) > 21) { pause(5); }
    drive_ramp(0,0);
    
    go_left();