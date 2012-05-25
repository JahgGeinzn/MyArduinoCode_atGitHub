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
  int looptime=50;
  int NUM_C=8;
  long lastMilli;
  long count_fomer_r;
  long count_fomer_l;
  float speed_act_r;
  float speed_act_l;
  
  lastMilli=millis();
  count_fomer_r=count_r;
  count_fomer_l=count_l;
  
  interrupts();
  while ((millis()-lastMilli) <= looptime)   
  { ; }       // enter tmed loop                                                          
  noInterrupts();
  speed_act_r=float(count_r- count_fomer_r)*1000/float(looptime*NUM_C);
  speed_act_l=float(count_l- count_fomer_l)*1000/float(looptime*NUM_C);
  Serial.print("Right Speed is ");
  Serial.println(speed_act_r);
  Serial.print("Left Speed is ");
  Serial.println(speed_act_l);
}
  
