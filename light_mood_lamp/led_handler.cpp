#include "led_handler.h"

LedHandler::LedHandler(int period) {
  // If period > 0.5sec  
  if(period > 500) 
      _omega = 2*PI/period;
   else 
      _omega = 2*PI/1000;      
 }


/* 
Purpose: Generate fading LED effect with cos function
sinWaveFade(offset, amplitude, displace, time)
offset: 128 is the min value. With this value a led reaches 0 light intensity
amplitude: 127 means that cos function oscillates in range [-0.5;0.5] around the offset
displace: out of phase
time: time used in cos function
*/
int LedHandler::sinWaveFade(int offset, int amplitude, int displace, unsigned long *timeid) {
 
  int outputValue = offset+amplitude*(cos(_omega*(*timeid - displace))); 
  
  return outputValue;
}



