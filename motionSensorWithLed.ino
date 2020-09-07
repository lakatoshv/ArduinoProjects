/// <summary>
/// Use PIR Motion Sensor with Led light.
/// </summary>
// <copyright file="laser.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int LED_PIN = 7;
const int MOTION_SENSOR_PIN = 9;
int motionSensorValue = 0;
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
}

void loop()
{
  motionSensorValue = digitalRead(MOTION_SENSOR_PIN);
  digitalWrite(LED_PIN, motionSensorValue);

    if (val == 1) 
    {
        digitalWrite(LED_PIN, LOW);
    }
}