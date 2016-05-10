// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D6
#define PIXEL_COUNT 163
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int pos = 0; // Position, direction of "eye"
int orange = 0; //Set to 1 for orange, or 0 for blue portal
int portalColor;

void setup()
{
  strip.begin();
  //strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'
  if (orange == 1) {
    portalColor = strip.Color(50, 15, 0);
  } else {
    portalColor = strip.Color(10, 10, 50);
  }
}


void loop() {

  // Draw 5 pixels centered on pos.  setPixelColor() will clip any
  // pixels off the ends of the strip, we don't need to watch for that.

    for (int i=0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, 5 * portalColor);
          //strip.setColorDimmed(i, 255, 50, 0, 8*i);
    }
      
    for (int i=-5; i < strip.numPixels(); i+=5) {
        for (int j = 0; j <= 1; j++) {
            //strip.setPixelColor(pos + i + j, abs(50 * j), abs(15 * j), 0);
            strip.setPixelColor(pos + i + j, abs(j) * portalColor);
        }
    }
    

  strip.show();
  delay(100);

  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  //for(j=-2; j<= 2; j++) strip.setPixelColor(pos+j, 0, 255, 0);

  if(pos >= 11) {
    pos = 0;
  }
  /*if(colorSwitch >= 50) {
    colorSwitch = 0;
    orange += 1;
    if (orange % 2) {
        portalColor = strip.Color(50, 15, 0);
    } else {
        portalColor = strip.Color(10, 10, 50);
    }
  }*/
  pos++;
  //colorSwitch++;
}
