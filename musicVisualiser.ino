void setup() {
   pinMode(A0,INPUT); // к аналоговому входу A0 подключим датчик (англ. «intput»)
   Serial.begin(9600); // подключаем монитор порта
   //all pins are outputs and we are using 2 to 13
   for (int x =2;x<13;x++)
   {
      pinMode(x,OUTPUT);
      digitalWrite(x,HIGH);
   }
}

void loop() {
   Serial.println (analogRead(A0));
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
   int potentiometerValue = analogRead(2) != 0 ? analogRead(2) : 250;
   int speed = potentiometerValue / 4;

   for(int x=5, y = 12;x <= 8, y >= 9; x++, y--)
   {
      color();
      delay(speed);
      digitalWrite(x,potentiometerValue);
      digitalWrite(y,potentiometerValue);
   }
   delay(100);
   for(int x=8, y = 9;x >= 5, y <= 12; x--, y++)
   {
      delay(speed);
      digitalWrite(x,LOW);
      digitalWrite(y,LOW);
   }
}