#define MoAS 10
#define MoAA 12
#define MoAB 13
#define MoBS 9
#define MoBA 8
#define MoBB 11
#define SeFR 7
#define SeFC 6
#define SeFL 5

void setup(){
  pinMode(MoAS,OUTPUT);
  pinMode(MoAA,OUTPUT);
  pinMode(MoAB,OUTPUT);
  pinMode(MoBS,OUTPUT);
  pinMode(MoBA,OUTPUT);
  pinMode(MoBB,OUTPUT);
}
void loop(){
  if(digitalRead(SeFC))
  {
    digitalWrite(MoAA,HIGH);
    digitalWrite(MoAB,LOW);
    digitalWrite(MoBA,HIGH);
    digitalWrite(MoBB,LOW);
    digitalWrite(MoAS,HIGH);
    digitalWrite(MoBS,HIGH);
  }
}
