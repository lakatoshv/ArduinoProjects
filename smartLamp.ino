/// <summary>
/// Smart lamp.
/// When it is dark in the room, the lamp turns on automatically
/// </summary>
// <copyright file="smartLamp.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int LED_PIN = 9;
const int PHOTORESISTOR_PIN = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  if (analogRead(PHOTORESISTOR_PIN) > 0)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    delay(1000);
  }
}

