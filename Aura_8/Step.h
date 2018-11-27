#ifndef Step_h
#define Step_h

class Step {
  private:
    // Whether calibration is done
    bool isStarted = false;
  
    // Pin number of switch
    int SwitchPIN = 12;   // ← change this number
    
    // Pin numbers of stepping motor
    const int DirPIN = 4;
    const int StepPIN = 5;
    const int EnaPIN = 6;

    // Pins to control microstepping
    const int MS1_PIN = 9;
    const int MS2_PIN = 10;
    const int MS3_PIN = 11;    
    
    // Steps Resolution: 0=full 1=half 2=quater 3=eighth 4=sixteenth
    const int stepRes = 4; 
    
    int count = 0;      // counter for rotate motor
    
    const int breathInSpeed = 100;   // the larger value is, the slower speed is.
    const int breathOutSpeed = 10;   // the larger value is, the slower speed is.

    const int MAX_STEP = 750;        // Sarting position to goto after hitting bottom limit switch

    int breathInStep = 500; //Breath size (Mus be smaller than MAX_STEP)
    int delayTimeIn = breathInStep + 100;
    int breathOutStep = delayTimeIn + breathInStep;
    int delayTimeOut = breathOutStep + 800;

    /*———————— Function ————————*/
    void SetMS(int _stepRes);
    void Rotate(bool dir, int rotSpeed);   // dir:direction, rotSpeed:speed
    
  
  public:
    /*———————— Constructer ————————*/
    Step();
    /*———————— Function ————————*/
    void setup();
    void update(); 
    void Calibrate();
};

#endif
