#include "Step.h"
#include "Arduino.h"

/*———————————————— Constructer ————————————————*/
Step::Step() {}

/*———————————————— Setup Function ————————————————*/
void Step::setup() {
  // set Pins
  pinMode(SwitchPIN, INPUT);
  
  pinMode(EnaPIN, OUTPUT);
  pinMode(StepPIN, OUTPUT);
  pinMode(DirPIN, OUTPUT);

  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS3_PIN, OUTPUT);

  // set microstepping
  SetMS(stepRes);

  // set enable to move
  digitalWrite(EnaPIN, LOW); // Set Enable low　→　Enable with Low

  // Calibration
  Calibrate();
}



/*———————————————— Update (Breath) ————————————————*/
void Step::update() {
  if (isStarted && digitalRead(SwitchPIN) == HIGH) {
    if (count < breathInStep) {        // breath in
      Rotate(true, breathInSpeed); 
    }
    else if (count < delayTimeIn) {}
    else if (count < breathOutStep) {  // breath out
      Rotate(false, breathOutSpeed);
    }
    else if (count < delayTimeOut) {}
    else {                             // initialize count
      count = 0;
    }
    count++;
  }
}


/*———————————————— Set pins to control microstepping with L/H ————————————————*/
void Step::SetMS(int _stepRes) {
  switch (_stepRes) {
    case 0:
      digitalWrite(MS1_PIN, LOW);
      digitalWrite(MS2_PIN, LOW);
      digitalWrite(MS3_PIN, LOW);
      break;
    case 1:
      digitalWrite(MS1_PIN, HIGH);
      digitalWrite(MS2_PIN, LOW);
      digitalWrite(MS3_PIN, LOW);
      break;
    case 2:
      digitalWrite(MS1_PIN, LOW);
      digitalWrite(MS2_PIN, HIGH);
      digitalWrite(MS3_PIN, LOW);
      break;
    case 3:
      digitalWrite(MS1_PIN, HIGH);
      digitalWrite(MS2_PIN, HIGH);
      digitalWrite(MS3_PIN, LOW);
      break;
    case 4:
      digitalWrite(MS1_PIN, HIGH);
      digitalWrite(MS2_PIN, HIGH);
      digitalWrite(MS3_PIN, HIGH);
      break;
    default:
      digitalWrite(MS1_PIN, LOW);
      digitalWrite(MS2_PIN, LOW);
      digitalWrite(MS3_PIN, LOW);
      break;
  }
}


/*———————————————— Rotation Function ————————————————*/
void Step::Rotate(bool dir, int rotSpeed)
{
  /*———————— Set direction ————————*/
  if (dir) {
    digitalWrite(DirPIN, HIGH); // Set direction as rihgt
  } else {
    digitalWrite(DirPIN, LOW); // Set direction as left
  }

  /*———————— Make pulse waves ————————*/
  digitalWrite(StepPIN, HIGH);
  delayMicroseconds(rotSpeed);
  digitalWrite(StepPIN, LOW);
  delayMicroseconds(rotSpeed); 
}


/*———————————————— Calibrate to starting position ————————————————*/
void Step::Calibrate() {
  
  //Spint motor to 0 position (switch enaged)
  while (digitalRead(SwitchPIN) == HIGH){
    Rotate(true, 500);
    delay(2);
  }
  
  //Goto starting position
  for (int i; i<MAX_STEP; i++) {
      Rotate(false, 500);
      delay(2);
  }
  
  isStarted = true;

}

