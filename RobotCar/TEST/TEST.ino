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
  int i=255;
  int onoff=0;
    digitalWrite(MoAA,HIGH);
    digitalWrite(MoAB,LOW);
    digitalWrite(MoBA,HIGH);
    digitalWrite(MoBB,LOW);
    if(digitalRead(SENSOR1)==LOW){
    delay(5);
    if(digitalRead(SENSOR1)==LOW){
  digitalWrite(MAS,LOW);
  digitalWrite(MBS,LOW);
  }
    }
  else{
    digitalWrite(MAS,HIGH);
    digitalWrite(MBS,HIGH);
  }
}
