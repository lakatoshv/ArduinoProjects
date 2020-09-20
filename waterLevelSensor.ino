/// <summary>
/// Use Water level sensor.
/// </summary>
// <copyright file="waterLevelSensor.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int WATER_LEVEL_SENSOR_PIN = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(WATER_LEVEL_SENSOR_PIN));
  delay(100);
}