
#include <Servo.h>
#define Green 3
#define Yellow 5
#define Red 6
#define Analog 0
Servo sg90;
int v=0;
int s=0;
void setup(){
  pinMode(Analog,INPUT);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  sg90.attach(11);
}
void loop(){
  v=analogRead(Analog);
  v=map(v,0,1023,0,255);
  s=map(v,0,255,0,180);
  sg90.write(s);
  analogWrite(Green,v);
  analogWrite(Yellow,v);
  analogWrite(Red,v);
  delay(10);
}
