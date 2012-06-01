

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

int control_loop(int looptime , float speed_req, int PWM_val)
{
  long lastMilli;
  long count_fomer;
  float speed_act;
  lastMilli=millis();
  count_fomer=count;
  interrupts();
  while ((millis()-lastMilli) <= looptime)   
  {  ;  }       // enter tmed loop                                                          
 noInterrupts();
  speed_act=float(count- count_fomer)*1000/float(looptime*NUM_C);
   PWM_val= PID_updata(PWM_val, speed_req, speed_act);   // compute PWM 
return constrain(PWM_val, 0, 255);
}

