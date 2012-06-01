#define Green 3
#define Yellow 5
#define Red 6
#define Butten 12

int times=0;//设定一个变量用于记录开关被按下了几次
void setup(){
  pinMode(Butten,INPUT);
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
}
void loop(){
    if(digitalRead(Butten)==LOW){
      delay(10);
      if(digitalRead(Butten)==HIGH){
       times++;//记录开关被按下的次数
      }
    }  
    if(times%4==1){
    digitalWrite(Green,HIGH);
    digitalWrite(Yellow,LOW);
    digitalWrite(Red,LOW);
    }
    else if(times%4==2){
         digitalWrite(Green,LOW);
         digitalWrite(Yellow,HIGH);
         digitalWrite(Red,LOW);
         }
         else if(times%4==3){
              digitalWrite(Green,LOW);
              digitalWrite(Yellow,LOW);
              digitalWrite(Red,HIGH);
              }
              else{
                digitalWrite(Green,LOW);
                digitalWrite(Yellow,LOW);
                digitalWrite(Red,LOW);
              }//根据到底按了多少下确定到底是点亮哪个LED
}
