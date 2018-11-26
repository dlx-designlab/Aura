#include "Step.h"
#include "LightCount.h"
#include "Adafruit_NeoPixel.h"


uint32_t MAX_VAL = 200;
uint32_t Off[3] = {0, 0, 0};         // R,G,B
uint32_t Blue[3] = {0, 0, MAX_VAL};  // R,G,B   

const int LED_NUM = 8;  // Number of NeoPixel
const int LED_PIN = 3;      // NeoPixels PIN

/*———————— Instantiate ————————*/
Step myStep;    // Instantiate a rotation controller
LightCount myCount[LED_NUM];
Adafruit_NeoPixel strip;                             

/*———————————————— Setup ————————————————*/
void setup() { 
  /*———————— setup step motor ————————*/
  myStep.setup();

  /*———————— setup NeoPixels ————————*/
  strip = Adafruit_NeoPixel(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);  // Instantiate a strip of NeoPixel
  strip.begin();
  strip.show();     // Initialize all pixels to 'off'
  for (int i = 0; i<LED_NUM; i++) {
    myCount[i].setup(i);
  }
}


/*———————————————— Loop ————————————————*/
void loop() {
  /*———————— Update ————————*/
  for (int i = 0; i<LED_NUM; i++) {
    if(myCount[i].update()) {
      LightUp(i, Blue);
    } else {
      LightUp(i, Off);
    }
  }
  myStep.update();
  delay(2);
}



/*———————————————— Light up one LED ————————————————*/
void LightUp(uint16_t num, uint32_t color[3]) {  // num:index of LED array, color: {R,G,B}
  /*———————— setup color ————————*/
  int _color[3];
  for (int i=0; i<3; i++) {
    if (color[i]<0) { _color[i] = 0; }                  // Set Min
    else if (color[i]>MAX_VAL) { _color[i] = MAX_VAL; } // Set Max
    else { _color[i] = color[i]; }
  }
  /*———————— light up one LED ————————*/
  strip.setPixelColor(num, strip.Color(_color[0], _color[1], _color[2]));
  strip.show();
}



