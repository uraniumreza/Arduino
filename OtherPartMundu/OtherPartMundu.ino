#include <Stepper.h>

const int stepsPerRevolution = 200;  
Stepper myStepper(stepsPerRevolution, 8,9,10,11); 

void setup()
{
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
  
  myStepper.setSpeed(30);
  delay(100);
  int steps = 200;
  Serial.println("INITIALIZED");
}

void loop()
{
  if(digitalRead(7)==HIGH){
    myStepper.step(stepsPerRevolution);
  }
  delay(500);
}
