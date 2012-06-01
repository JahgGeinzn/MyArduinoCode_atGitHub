#define Green 3
#define Yellow 5
#define Red 6
#define Green_time 20
#define Yellow_time 5
#define Red_time 20
#define Green_delay 10
#define Red_delay 10

int state=HIGH;
int i;

void setup(){
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
}
void loop(){
  digitalWrite(Green,HIGH);
  delay((Green_time-Green_delay)*1000);
  for(i=0;i<Green_delay*2;i++){
    if(state==HIGH){
    digitalWrite(Green,LOW);
    }
    else{
    digitalWrite(Green,HIGH);
    }
    state=~state;
    delay(500);
  }
  digitalWrite(Green,LOW);
  for(i=0;i<Yellow*2;i++){
    if(state==HIGH){
    digitalWrite(Yellow,LOW);
    }
    else{
    digitalWrite(Yellow,HIGH);
    }
    state=~state;
    delay(500);
  }
  digitalWrite(Yellow,LOW);
  digitalWrite(Red,HIGH);
  delay((Red_time-Red_delay)*1000);
  state=HIGH;
  for(i=0;i<Red_delay*2;i++){
    if(state==HIGH){
    digitalWrite(Red,LOW);
    }
    else{
    digitalWrite(Red,HIGH);
    }
    state=~state;
    delay(500);
  }
  digitalWrite(Red,LOW);
  for(i=0;i<Yellow*2;i++){
    if(state==HIGH){
    digitalWrite(Yellow,LOW);
    }
    else{
    digitalWrite(Yellow,HIGH);
    }
    state=~state;
    delay(500);
  }
  digitalWrite(Yellow,LOW);
}
  
  
