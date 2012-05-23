volatile long counta=0;
volatile long countb=0;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0,count0,CHANGE);
  attachInterrupt(1,count1,CHANGE);
}
void count0()
{
  counta++;
  Serial.print("A is ");
  Serial.println(counta);
}
void count1()
{
  countb++;
  Serial.print("B is ");
  Serial.println(countb);
}
void loop()
{
  interrupts();
}
  
