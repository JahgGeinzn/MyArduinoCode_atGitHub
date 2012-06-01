#define Green 3
#define Yellow 5
#define Red 6
#define Butten 12

void setup(){
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  pinMode(Butten,INPUT);
}

void loop(){
  if(digitalRead(Butten)==HIGH){
    delay(10);
    if(digitalRead(Butten)==HIGH){
      digitalWrite(Green,HIGH);
    }
  }
   if(digitalRead(Butten)==LOW){
    delay(10);
    if(digitalRead(Butten)==LOW){
      digitalWrite(Green,LOW);
    }
  }
}
