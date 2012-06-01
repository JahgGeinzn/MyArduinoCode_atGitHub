#define Pwm 6
#define Led 13
int buttonState = HIGH;

void setup(){
  pinMode(Led,OUTPUT);
  pinMode(Pwm,OUTPUT);
}

void loop(){
  int a=0;
  while(1)
  {
    for(a=5;a<255;a+=5)
  {
    analogWrite(Pwm,a);
    digitalWrite(Led,buttonState);
    delay(60);
    if(buttonState==HIGH)
    buttonState=LOW;
    else buttonState=HIGH;
  }
  for(a=255;a>5;a-=5)
  {
    analogWrite(Pwm,a);
    digitalWrite(Led,buttonState);
    delay(40);
    if(buttonState==HIGH)
    buttonState=LOW;
    else buttonState=HIGH;
  }
  }
}
    
  
  
