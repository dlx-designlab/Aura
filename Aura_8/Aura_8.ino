#include "Step.h"
#include "LightCount.h"
#include "FastLED.h"

const float Pi = 3.14;

const int LED_NUM = 8;  // Number of NeoPixels
const int LED_PIN = 3;  // NeoPixels PIN
const int loopDelay = 2;

//Neopixels LEDs Array
//Color Values are RGB or HSV(Hue, Saturation, Value)
//For more details see FastLED refrence: 
//https://github.com/FastLED/FastLED/wiki/Pixel-reference
CRGB leds[LED_NUM];
LightCount ledCount[LED_NUM]; // Ledes animation properties array
int mainHue = 224;
int subHue = 96;

Step myStep;    // Instantiate a rotation controller


/*———————————————— Setup ————————————————*/
void setup() { 
  /*———————— setup step motor ————————*/
  myStep.setup();

  /*———————— setup LEDs ————————*/
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LED_NUM);
  
  for (int i = 0; i<LED_NUM; i++) {
    ledCount[i].setup(i);
    ledCount[i].hue = mainHue;
  }

  //set bottom led to different hue
  ledCount[3].hue = subHue;

}


/*———————————————— Loop ————————————————*/
void loop() {
  
  /*———————— Update ————————*/
  
  //Animate LEDs
  for (int i = 0; i<LED_NUM; i++) {
    ledCount[i].update();
    leds[i] = CHSV(ledCount[i].hue , 255, sin8(ledCount[i].currOnStep));
  }

  FastLED.show(); 

  //Move Motor
  myStep.update();
  

  delay(loopDelay);
}



