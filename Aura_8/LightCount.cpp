#include "Arduino.h"
#include "LightCount.h"

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
  bool result = false;
  if (counter < lightingTime) {
    result = true;    // turn on 
  } else  {
    result = false;   // turn off
  }

  counter++;
  if (counter > waitingTime) {  // finish waiting 
    counter = 0;
    setTime();
  }

  return result;
}



/*———————————————— set lighting time randomly ————————————————*/
void LightCount::setTime() {
  lightingTime = random(LT_MIN, LT_MAX);
  waitingTime = random(WT_MIN, WT_MAX);
}



