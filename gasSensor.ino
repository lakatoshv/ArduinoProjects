/// <summary>
/// Use gas sensor.
/// </summary>
// <copyright file="gasSensor.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int GAS_SENSOR_PIN = A0;
const int LED_PIN = 13;

int sensorValue = 0;
                    
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("MQ2 Test");
}
 
void loop() {
  sensorValue = analogRead(GAS_SENSOR_PIN);
  // if the gas threshold is exceeded
  if (sensorValue >= 350)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
  Serial.print("MQ2 value= ");
  Serial.println(sensorValue);
  delay(1000);
}
