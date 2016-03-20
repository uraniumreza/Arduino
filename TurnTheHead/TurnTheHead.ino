/*
Cancel a call and Rotate stepper by 360
[A+] RED
[A-] BLUE
[B+] BLACK
[B-] GREEN
*/

#include <String.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);   // GSM Tx->2, Rx->3
char response[100];

void setup() 
{
  mySerial.begin(9600);    // 9600/115200
  Serial.begin(9600);
  
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  Serial.println("INITIALIZED");
}

void loop()
{
  digitalWrite(7,LOW);
  int x = 0;
  int answer = 0;
  memset(response, '\0', 100);
  delay(100);   
  // comment out that
  //while(mySerial.available() > 0) mySerial.read();
  
  do{
    Serial.println("Yo Mammah...");
    if(mySerial.available() > 0){
      response[x] = mySerial.read();
      Serial.print(response[x]);
      x++;
      if(strstr(response, "RING") != NULL){
        mySerial.print("ATH\r\n");
        answer = 1;
      }
    }
  }while(answer == 0);
  if(answer == 1) digitalWrite(7,HIGH);
  delay(500);
}
