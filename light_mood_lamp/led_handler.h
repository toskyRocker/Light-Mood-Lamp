#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#include "Arduino.h"

class LedHandler {
  
  public:
    LedHandler(int period);
    int sinWaveFade(int offset, int amplitude, int displace, unsigned long *timeid);


  private:
    float _omega; 
};




#endif
