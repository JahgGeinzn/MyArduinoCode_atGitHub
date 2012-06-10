int mas=10;
int maa=12;
int mab=13;
int mbs=9;
int mba=8;
int mbb=11;
int powers=7;
int directions=4;

void setup()
{
  Serial.begin(9600);
  pinMode(mas,OUTPUT);
  pinMode(maa,OUTPUT);
  pinMode(mab,OUTPUT);
  pinMode(mbs,OUTPUT);
  pinMode(mba,OUTPUT);
  pinMode(mbb,OUTPUT);
}

void loop()
{
  int t_powers=pulseIn(powers,HIGH);
  int t_directions=pulseIn(directions,HIGH);
  int speeds;
  Serial.println(t_powers);
  Serial.println(t_directions);
  if(t_powers>1520)
  speeds=map(t_powers,1520,2010,50,255);
  else if(t_powers<1480)
  speeds=map(t_powers,1010,1480,-255,-50);
  else 
  speeds=0;
  Serial.println(speeds);
  if(t_directions>1490&&t_directions<1510)
  forward(speeds);
  else if(t_directions<=1480)
  turnright(map(t_directions,1480,1010,speeds,0),speeds);
  else if(t_directions>=1520)
  turnleft(map(t_directions,2000,1520,0,speeds),speeds);
}

void forward(int v_req)
{
  motor_r(v_req);
  motor_l(v_req);
}
void turnleft(int v_req,int speeds)
{
  motor_r(speeds);
  motor_l(v_req);
}
void turnright(int v_req,int speeds)
{
  motor_r(v_req);
  motor_l(speeds);
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
