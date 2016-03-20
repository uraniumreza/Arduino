/*
Stepper Control Using Easy Driver(Sparkfun)
[A+] RED
[A-] BLUE
[B+] BLACK
[B-] GREEN
*/

#define step_pin 3
#define dir_pin 2
#define MS1 5
#define MS2 4

int steps = 200;

void setup() 
{
  Serial.begin(9600);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(dir_pin, LOW);
  delay(100);
}

void loop()
{
  Serial.println("....");
  
  while(steps>=0){
    digitalWrite(step_pin, LOW);
    delay(4);
    digitalWrite(step_pin, HIGH);
    delay(4);
    steps--;
  }
}
