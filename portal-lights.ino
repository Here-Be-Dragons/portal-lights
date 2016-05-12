//For Neopixel strips
#include <Adafruit_NeoPixel.h>

// IMPORTANT: Set pixel COUNT and PIN
#define PIN 6
#define NUMPIXELS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int orange = 0; //Set to 1 for orange, or 0 for blue portal
uint32_t portalColor = 0;
uint8_t pos = 0; // Position tracking of pixels

void setup()
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    if (orange == 0) {
        portalColor = strip.Color(0, 170, 255); //Light Blue
    } else {
        portalColor = strip.Color(255, 125, 0); //Orange
    }
}


void loop() {

    for (uint8_t i=0; i < strip.numPixels(); i++) { // Blank everything
          strip.setPixelColor(i, 0);
    }

    for (int i=0; i < strip.numPixels() + 1; i+=5) {
        for (int j = -2; j < 0; j++) {
            strip.setPixelColor( pos + i + j, portalColor );
        }
    }
    strip.show();
    delay(100);

    if(pos >= 5) {
        pos = 0;
    }
    pos++;

/*    //##########
    //The below if statement will switch between colors automatically for testing
    static int colorSwitch = 0;
    if(colorSwitch >= 50) {
        colorSwitch = 0;
        orange += 1;
        if (orange % 2) {
            portalColor = strip.Color(0, 170, 255);
        } else {
            portalColor = strip.Color(255, 125, 0);
        }
    }
    colorSwitch++;
    //##########
*/
}
