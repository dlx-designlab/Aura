#ifndef Step_h
#define Step_h

class Step {
  private:
    int DirPIN = 4;
    int StepPIN = 5;
    int EnaPIN = 6;

    //Pins to control microstepping
    int MS1_PIN = 9;
    int MS2_PIN = 10;
    int MS3_PIN = 11;    
    
    //Steps Reolution: 0=full 1=half 2=quater 3=eighth 4=sixteenth
    int stepRes = 4; 
    
    int count = 0;
    int breathInSpeed = 100;   // the larger value is, the slower speed is.
    int breathOutSpeed = 10;   // the larger value is, the slower speed is.

    int breathInStep = 500;
    int delayTimeIn = breathInStep + 100;
    int breathOutStep = delayTimeIn + breathInStep;
    int delayTimeOut = breathOutStep + 800;
  
  public:
    /*———————— Constructer ————————*/
    Step();
    /*———————— Function ————————*/
    void setup();
    void update();
    void Rotate(bool dir, int rotSpeed);   // dir:direction, stepNum:degree/step, rotSpeed:speed    
};

#endif
