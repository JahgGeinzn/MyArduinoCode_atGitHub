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
float v_req_r=1.25;
float v_req_l=1;
const int NUM_C_l=8;
const int NUM_C_r=16;      //the number of counter of a roll.
                          //IF select CHANGE in attachInterrupt(0, rencoder, CHANGE) ,the  NUM_C should be multiple by 2
                           //Other selection in attachInterrupt(0, rencoder, FALLING), the  NUM_C is equal to the number of counter of a roll
const int LOOPTIME =300;   //the loop time(ms) of PID control
 float Kp=3;          // PID proportional control Gain
 float Ki=4;          // PID i control gain

void setup()
{
  Serial.begin(9600);
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
  motor_r(PWM_val_r);
  motor_l(PWM_val_l);
  PWM_val_r=control_loop_r(LOOPTIME,v_req_r,PWM_val_r);
  PWM_val_l=control_loop_l(LOOPTIME,v_req_l,PWM_val_l);
}

void motor_r(int s)
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
void motor_l(int s)
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

int control_loop_r(int looptime , float speed_req_r, int PWM_val_r)
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
  speed_act_r=float(count_r- count_fomer_r)*1000/float(looptime*NUM_C_r);
  Serial.print("Right Speed is ");
  Serial.println(speed_act_r);
  PWM_val_r= PID_updata(PWM_val_r, speed_req_r, speed_act_r);   // compute PWM 
return constrain(PWM_val_r, 0, 255);
}

int control_loop_l(int looptime , float speed_req_l, int PWM_val_l)
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
  speed_act_l=float(count_l- count_fomer_l)*1000/float(looptime*NUM_C_l);
  Serial.print("Left Speed is ");
  Serial.println(speed_act_l);
  PWM_val_l= PID_updata(PWM_val_l, speed_req_l, speed_act_l);   // compute PWM 
return constrain(PWM_val_l, 0, 255);
}
  
