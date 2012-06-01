#define Green 3
#define Yellow 5
#define Red 6
#define Analog 0

int v=0;
void setup(){
  pinMode(Analog,INPUT);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
}
void loop(){
  v=analogRead(Analog);
  v=map(v,0,1023,0,255);
  analogWrite(Green,v);
  analogWrite(Yellow,v);
  analogWrite(Red,v);
}
