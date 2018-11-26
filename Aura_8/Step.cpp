#include "Arduino.h"
#include "Step.h"

/*———————————————— Constructer ————————————————*/
Step::Step() {}

/*———————————————— Setup Function ————————————————*/
void Step::setup() {
  pinMode(EnaPIN, OUTPUT);
  pinMode(StepPIN, OUTPUT);
  pinMode(DirPIN, OUTPUT);

  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS3_PIN, OUTPUT);

  switch (stepRes) {
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
  
  digitalWrite(EnaPIN, LOW); // Set Enable low　→　Enable with Low
  
}



/*———————————————— Update (Breath) ————————————————*/
void Step::update() {
  if (count < breathInStep) {           // breath in
    Rotate(true, breathInSpeed); 
  } else if (count < delayTimeIn) {
  } else if (count < breathOutStep) {  // breath out
    Rotate(false, breathOutSpeed);
  } else if (count < delayTimeOut) {
  } else {                            // initialize count
    count = 0;
  }
  count++;
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
