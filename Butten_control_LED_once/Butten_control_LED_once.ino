int Butten=12;//连接开关到IO12
int LED=3;//连接LED到3
int onoff=0;//设定一个变量用于记录开关被按下了偶数还是奇数次，按一次，为奇数次，=1；两下就是偶数次，=0
void setup(){
  pinMode(Butten,INPUT);
  pinMode(LED,OUTPUT);
}
void loop(){
  if(digitalRead(Butten)==LOW){
    delay(10);
    if(digitalRead(Butten)==HIGH){
      if (onoff==0)
      onoff=1;
      else onoff=0;//记录开关被按下的次数部分
      }
    }  
  if(onoff==0)
  digitalWrite(LED,LOW);
  else digitalWrite(LED,HIGH);//根据到底按了多少下确定到底是点亮LED还是熄灭
}
