int mas=10;
int maa=12;
int mab=13;
int mbs=9;
int mba=8;
int mbb=11;
int sfr=7;
int sfc=6;
int sfl=5;

volatile long count_r=0;
volatile long count_l=0;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0,count_r,CHANGE);
  attachInterrupt(1,count_l,CHANGE);
}
void count_r()
{
  count_r++;
  Serial.print("Right is ");
  Serial.println(count_r);
}
void count_l()
{
  count_l++;
  Serial.print("Left is ");
  Serial.println(count_l);
}

void motor_l(int s)
{
  if(s==0)
  {
    digitalWrite(maa,LOW);
    digitalWrite(mab,LOW);
    digitalWrite(mas,HIGH);
  }
  else if(s>0&&s<256)
  {
    digitalWrite(maa,HIGH);
    digitalWrite(mab,LOW);
    analogWrite(mas,s);
    delay(20);
  }
  else if(s<0&&s>-256)
  {
    digitalWrite(maa,LOW);
    digitalWrite(mab,HIGH);
    analogWrite(mas,-s);
    delay(20);
  }
  else digitalWrite(mas,LOW);
}
void motor_r(int s)
{
    if(s==0)
  {
    digitalWrite(mba,LOW);
    digitalWrite(mbb,LOW);
    digitalWrite(mbs,HIGH);
  }
  else if(s>0&&s<256)
  {
    digitalWrite(mba,HIGH);
    digitalWrite(mbb,LOW);
    analogWrite(mbs,s);
    delay(20);
  }
  else if(s<0&&s>-256)
  {
    digitalWrite(mba,LOW);
    digitalWrite(mbb,HIGH);
    analogWrite(mbs,-s);
    delay(20);
  }
  else digitalWrite(mbs,LOW);
}

void loop()
{
  int looptime=500;
  int NUM_C=8;
  long lastMilli;
  long count_fomer;
  float speed_act_r;

  lastMilli=millis();
  motor_r(255);
  motor_l(255);
  count_fomer=count_r;
  interrupts();
  while ((millis()-lastMilli) <= looptime)   
  {  ;  }       // enter tmed loop                                                          
  noInterrupts();
  speed_act_r=float(count_r- count_fomer)*1000/float(looptime*NUM_C);
  Serial.print("Right Speed is ");
  Serial.print
}
  