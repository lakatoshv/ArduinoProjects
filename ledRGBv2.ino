void setup()
{
  //all pins are outputs and we are using 2 to 13
  for (int x =2;x<13;x++)
  {
    pinMode(x,OUTPUT);
    digitalWrite(x,HIGH);
  }
}
 
void loop()
{
   blue();
   cycle(); 
   green();
   cycle();
   red();
   cycle();
}
 
void blue()
{
  digitalWrite(2,LOW);
}
 
void green()
{
  digitalWrite(3,LOW);
}
 
void red()
{
  digitalWrite(4,LOW);
}
 
 
void cycle()
{
  for(int x=5;x<13;x++)
  {
    digitalWrite(x,LOW);
    delay(500);
    digitalWrite(x,HIGH);
  }
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
}