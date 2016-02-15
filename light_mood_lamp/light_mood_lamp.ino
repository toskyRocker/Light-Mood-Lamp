/* 
Andrea Toscano 2016
Light Mood Lamp project
*/



#import "config.h"
#import "led_handler.h"

//init with fade period  [3 sec]
LedHandler myLedHandler(3000); 

// RGB components array
const byte ledPinArray[] = {RED_PIN, GREEN_PIN, BLUE_PIN};
// Output value to be written
int ledRGBOutput[] = {0,0,0};

// Raw and Filtered Lux data from photoCell
int photocellReading = 0, filteredPhotocellReading = 0;

// Time to be used in led fading.
unsigned long timer = 0;


void setup() { 
   // Uncomment to enable serial monitor
  //Serial.begin(115200); 
} 

void loop() {
 timer = millis();
 ledRoutine();
}


void ledRoutine() {
  // Reading from photocell
   photocellReading = analogRead(PHOTO_PIN);
  // Low pass filter for smooth transactions
  filteredPhotocellReading =(ALPHA_IIR*filteredPhotocellReading+(1.0-ALPHA_IIR)*photocellReading);

  // Green and Orange
  if(filteredPhotocellReading > HIGH_BAND) {

     ledRGBOutput[R] = myLedHandler.sinWaveFade(200, 127, 0, &timer);
     ledRGBOutput[G] = myLedHandler.sinWaveFade(120, 127, 0, &timer);
     ledRGBOutput[B] = myLedHandler.sinWaveFade(40, 40, 400, &timer);
   }
   
 // Red and Magenta
   else if (filteredPhotocellReading <= HIGH_BAND && filteredPhotocellReading > MID_BAND){
     ledRGBOutput[R] = 190;
     ledRGBOutput[G] = myLedHandler.sinWaveFade(140, 120, 200, &timer);
     ledRGBOutput[B] = 0;
    }
    
   // Basically Red and Blue
   else if (filteredPhotocellReading <= MID_BAND && filteredPhotocellReading > LOW_BAND){
     ledRGBOutput[R] = 255;
     ledRGBOutput[G] = 0;
     ledRGBOutput[B] = myLedHandler.sinWaveFade(150, 127, 100, &timer);
   }
   
   // Red !  Hot atmosphere
   else if(filteredPhotocellReading<= LOW_BAND){
     ledRGBOutput[R] = myLedHandler.sinWaveFade(180, 127, 0, &timer);
     ledRGBOutput[G] = 0;
     ledRGBOutput[B] = 0;
   }
   writeLeds();
}

void writeLeds() {
  
  for(byte counter = 0; counter < 3; counter++) {
    ledRGBOutput[counter] = clipValue(ledRGBOutput[counter]);
    analogWrite(ledPinArray[counter], ledRGBOutput[counter]);
  }
}

int clipValue(int val) {
  if (val > 255)
    val = 255;
  else if(val < 0)
    val = 0;
  return val;
}

