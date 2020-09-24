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
    digitalWrite(2,HIGH);
    for(int x=5;x<13;x++)
    {
        digitalWrite(x,LOW);
        delay(500);
        digitalWrite(x,HIGH);
    }
}