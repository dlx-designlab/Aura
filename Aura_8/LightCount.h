#ifndef LightCount_h
#define LightCount_h

#include <Adafruit_NeoPixel.h>

class LightCount {
private:

  int index;    // index of led
  
  int counter = 0;

  const int LT_MIN = 10;   // Min of lighting time
  const int LT_MAX = 30;   // Max of lighting time

  const int WT_MIN = 100; // Min of waiting time
  const int WT_MAX = 250; // Max of waiting time

  int lightingTime;
  int waitingTime;

  void setTime();

public:
  /*———————— Constructer ————————*/
  LightCount();

  /*———————— Initialize ————————*/
  void setup(int _index);

  /*———————— Update ————————*/
  bool update();

};

#endif
