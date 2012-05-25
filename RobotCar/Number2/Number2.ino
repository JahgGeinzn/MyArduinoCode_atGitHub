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
int PWM_val_r = 0;
int PWM_val_l = 0;
float v_req_r=0;
float v_req_l=0;
const int NUM_C=8;      //the number of counter of a roll.
                          //IF select CHANGE in attachInterrupt(0, rencoder, CHANGE) ,the  NUM_C should be multiple by 2
                           //Other selection in attachInterrupt(0, rencoder, FALLING), the  NUM_C is equal to the number of counter of a roll
const int LOOPTIME =100;   //the loop time(ms) of PID control
 float Kp=1;          // PID proportional control Gain
 float Ki=4;          // PID i control gain

void setup()
{
  pinMode(mas,OUTPUT);
  pinMode(maa,OUTPUT);
  pinMode(mab,OUTPUT);
  pinMode(mbs,OUTPUT);
  pinMode(mba,OUTPUT);
  pinMode(mbb,OUTPUT);
  
  attachInterrupt(1, rencoder_r, CHANGE);
  attachInterrupt(0, rencoder_l, CHANGE);
}

void loop()
{
  
  if(digitalRead(sfc))
  {
    v_req_r=2;
    v_req_l=2;
    PWM_val_r=control_loop_r(LOOPTIME,v_req_r,PWM_val_r);
    PWM_val_l=control_loop_l(LOOPTIME,v_req_l,PWM_val_l);
    motor_r(PWM_val_r);
    motor_l(PWM_val_l);
  }
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
//PI Control Begin//
void rencoder_r()     //Interrupt:record counter-Right 
{                     
  count_r++;               
}
void rencoder_l()     //Interrupt:record counter-Left
{                     
  count_l++;               
}

float PID_updata(float command, float targetValue, float currentValue)    // compute PWM value
{            
float pidTerm = 0;                             // PID correction
float error=0;                                  
static float last_I=0;  
  error = abs(targetValue) - abs(currentValue);
  pidTerm =  Kp * error  + Kp * Ki * (error + last_I);                            
  last_I = error + last_I;
  return pidTerm;
}

int control_loop_r(int looptime , float speed_req, int PWM_val)
{
  long lastMilli;
  long count_fomer;
  float speed_act;
  lastMilli=millis();
  count_fomer=count_r;
  interrupts();
  while ((millis()-lastMilli) <= looptime)   
  {  ;  }       // enter tmed loop                                                          
 noInterrupts();
  speed_act=float(count_r- count_fomer)*1000/float(looptime*NUM_C);
  PWM_val= PID_updata(PWM_val, speed_req, speed_act);   // compute PWM 
return constrain(PWM_val, 0, 255);
}

int control_loop_l(int looptime , float speed_req, int PWM_val)
{
  long lastMilli;
  long count_fomer;
  float speed_act;
  lastMilli=millis();
  count_fomer=count_l;
  interrupts();
  while ((millis()-lastMilli) <= looptime)   
  {  ;  }       // enter tmed loop                                                          
 noInterrupts();
  speed_act=float(count_l- count_fomer)*1000/float(looptime*NUM_C);
  PWM_val= PID_updata(PWM_val, speed_req, speed_act);   // compute PWM 
return constrain(PWM_val, 0, 255);
}
  
