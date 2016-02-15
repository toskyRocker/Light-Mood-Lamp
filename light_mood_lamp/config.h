// Global define
#ifndef CONFIG_H_
#define CONFIG_H_

// BAUD SERIAL MONITOR 
#define SERIAL_BAUD 115200

// PHOTOCELL 
#define PHOTO_PIN A1

// LUX 
#define HIGH_BAND 600
#define MID_BAND  400
#define LOW_BAND  250

// IIR alpha coeff. filter for smooth transitions
#define ALPHA_IIR 0.90 


// Pins on Arduino UNO
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

// R, G, B components position in the array
#define R 0
#define G 1
#define B 2



#endif
