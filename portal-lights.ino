//For Neopixel strips
#include <Adafruit_NeoPixel.h>

// IMPORTANT: Set pixel COUNT and PIN
#define PIN 9
#define NUMPIXELS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint8_t orange = 0;       //Set to 1 for orange, or 0 for blue portal
float rColor = 0;   //Red color, 0-255
float gColor = 0;   //Green color, 0-255
float bColor = 0;   //Blue color, 0-255
float rLoop = 0;   //Red color inside loop, 0-255
float gLoop = 0;   //Green color inside loop, 0-255
float bLoop = 0;   //Blue color inside loop, 0-255
uint8_t pos = 0;      // Position tracking of pixels

void setup()
{
  strip.begin();
  strip.show();       // Initialize all pixels to 'off'
  if ( orange == 0 ) {  //Light Blue
      rColor = 0;
      gColor = 170;
      bColor = 255; 
  } else {            //Orange
      rColor = 255;
      gColor = 90;
      bColor = 0; 
  }
}

void loop() {
  for ( int j = 0; j <= 255; j+=10 ) {
    rLoop = ( rColor / 255 ) * j;
    gLoop = ( gColor / 255 ) * j;
    bLoop = ( bColor / 255 ) * j;
    for ( int i = 0; i < strip.numPixels() + 2; i+=10 ) {
      strip.setPixelColor( pos + i, rLoop, gLoop, bLoop ); //Fading in.  Each color is color / 255 to get per-step increase, times the step number
      strip.setPixelColor( pos + i - 3, rColor - rLoop, gColor - gLoop, bColor - bLoop ); //Fading out.  Each color is color / 255 to get per-step increase, times the step number
      strip.show();
    }
  }
  pos++;
  pos %= 10; // Reset to 0 each time it gets to 10
}
