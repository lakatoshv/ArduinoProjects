/// <summary>
/// Use laser.
/// </summary>
// <copyright file="car.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

int LASER_PIN = 10;

void setup ()
{
  pinMode(LASER_PIN, OUTPUT);
}

void loop () {
  digitalWrite(LASER_PIN, HIGH);
  delay(1000);
  digitalWrite(LASER_PIN, LOW);
  delay(1000);
}