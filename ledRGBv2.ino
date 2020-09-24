/// <summary>
/// Use Led RGB v2.
/// </summary>
// <copyright file="ledRGBv2.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

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
   cycle();
}

/// <summary>
/// Use random color.
/// </summary>
void color()
{
  int random1 = (rand() % 4) + 1;
  int random2 = (rand() % 4) + 1;
  int random3 = (rand() % 4) + 1;

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  if(2 == random1 || 2 == random2 || 2 == random3) {
    digitalWrite(2,HIGH);
  }
  if(3 == random1 || 3 == random2 || 3 == random3) {
    digitalWrite(3,HIGH);
  }
  if(4 == random1 || 4 == random2 || 4 == random3) {
    digitalWrite(4,HIGH);
  }
}
 
/// <summary>
/// Turn Led light on.
/// </summary>
void cycle()
{
  for(int x=5;x<13;x++)
  {
    color();
    digitalWrite(x,LOW);
    delay(100);
    digitalWrite(x,HIGH);
  }
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
}