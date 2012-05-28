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
int looptime=50;
int NUM_C_l=8;
int NUM_C_r=16;  

void counter_r()
{
  count_r++;
}
void counter_l()
{
  count_l++;
}
void setup()
{
  Serial.begin(9600);
  digitalWrite(maa,HIGH);
  digitalWrite(mab,LOW);
  digitalWrite(mas,HIGH);
  digitalWrite(mba,HIGH);
  digitalWrite(mbb,LOW);
  digitalWrite(mbs,HIGH);
  attachInterrupt(1,counter_r,CHANGE);
  attachInterrupt(0,counter_l,CHANGE);
}

void loop()
{
  speed_act_r=speed_r(50);
  Serial.print("Right Speed is ");
  Serial.println(speed_act_r);
  speed_act_l=speed_l(50);
  Serial.print("Left Speed is ");
  Serial.println(speed_act_l);
}
  
int speed_r(int looptime_r)
{
  long lastMilli_r;
  long count_fomer_r;
  float speed_act_r;
  lastMilli_r=millis();
  count_fomer_r=count_r;
  interrupts();
  while ((millis()-lastMilli_r) <= looptime)   
  {  ;  }       // enter tmed loop                                                          
  noInterrupts();
  speed_act_r=float(count_r- count_fomer_r)*1000/float(looptime_r*NUM_C_r);
  return speed_act_r;;
}

int speed_l(int looptime_l)
{
  long lastMilli_l;
  long count_fomer_l;
  float speed_act_l;
  lastMilli_l=millis();
  count_fomer_l=count_l;
  interrupts();
  while ((millis()-lastMilli_l) <= looptime)   
  {  ;  }       // enter tmed loop                                                          
  noInterrupts();
  speed_act_l=float(count_l- count_fomer_l)*1000/float(looptime_l*NUM_C_l);
  return speed_act_l;
}
