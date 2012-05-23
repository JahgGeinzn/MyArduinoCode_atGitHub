#define MAS 10
#define MAA 12
#define MAB 13
#define MBS 9
#define MBA 11
#define MBB 8
#define SENSOR1 7

void setup(){
  pinMode(MAS,OUTPUT);
  pinMode(MAA,OUTPUT);
  pinMode(MAB,OUTPUT);
  pinMode(MBS,OUTPUT);
  pinMode(MBA,OUTPUT);
  pinMode(MBB,OUTPUT);
}
void loop(){
  int i=255;
  int onoff=0;
    digitalWrite(MAA,HIGH);
    digitalWrite(MAB,LOW);
    digitalWrite(MBA,LOW);
    digitalWrite(MBB,HIGH);
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
