#ifndef LightCount_h
#define LightCount_h

#include <Adafruit_NeoPixel.h>

class LightCount {
private:

  int index;    // index of led

  float lightingStep;
  float waitingStep;

  const int minSteps = 10;   // Min fade Duration 
  const int maxSteps = 100;   // Max fade Duration



  void setTime();

public:
  /*———————— Constructer ————————*/
  LightCount();

  /*———————— Initialize ————————*/
  void setup(int _index);

  /*———————— Update ————————*/
  bool update();

  int hue = 70;
  float currOnStep = 0;
  float currOffStep = 0;

};

#endif
