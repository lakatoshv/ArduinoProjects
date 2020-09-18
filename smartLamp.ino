//за допомогою фоторезистора + резистора + світлодіода зробити розумну лампу. 
// Тобто коли темно в аудиторії включається лампа автоматично
void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  if (analogRead(0) > 0)
  {
    digitalWrite(9, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(9, LOW);
    delay(1000);
  }
}

