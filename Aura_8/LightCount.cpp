#include "Arduino.h"
#include "LightCount.h"
#include "FastLED.h"


/*———————————————— Constructer ————————————————*/
LightCount::LightCount() {}


/*———————————————— Initialize ————————————————*/
void LightCount::setup(int _index) {
  index = _index;
  randomSeed(analogRead(0));
  setTime();
}



/*———————————————— Update ————————————————*/
bool LightCount::update() {


  // for (int j = 1; j < 180; j++){
  //     int ledBrighness = sin8(j);
  //     for (int i = 0; i<LED_NUM; i++)
  //       leds[i] = CHSV(0, 255, ledBrighness);
  //     FastLED.show(); 
  //     delay(50);
  //   }
    //leds[i] = CRGB::Black; 
    //FastLED.show(); 

  if (currOnStep < 180) {
    currOnStep += lightingStep;
  } else if (currOffStep < 180) {
    currOffStep += waitingStep;
  } else
    setTime();

}


/*———————————————— set lighting time randomly ————————————————*/
void LightCount::setTime() {
  currOnStep = 0;
  currOffStep = 0;

  lightingStep = 180 / random(minSteps, maxSteps);
  waitingStep = 180 / random(minSteps, maxSteps);
}



