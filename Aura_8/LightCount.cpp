#include "Arduino.h"
#include "LightCount.h"
#include "FastLED.h"


/*———————————————— Constructer ————————————————*/
LightCount::LightCount() {}


/*———————————————— Initialize ————————————————*/
void LightCount::setup(int _index) {
  index = _index;
  //randomSeed(analogRead(0));
  setTime();
}



/*———————————————— Update ————————————————*/
bool LightCount::update() {

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



