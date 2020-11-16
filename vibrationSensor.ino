/// <summary>
/// Use vibration sensor.
/// </summary>
// <copyright file="vibrationSensor.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int VIBRATION_PIN_A0 = A1;
const int VIBRATION_PIN_D0 = A0;

int motionDetected = 0;
int sensorVal = 0;
 
void setup() {
   Serial.begin(9600);
   pinMode (VIBRATION_PIN_A0, INPUT);
   pinMode (VIBRATION_PIN_D0, INPUT);
}
 
void loop() {
   motionDetected = digitalRead(VIBRATION_PIN_D0);
   sensorVal = analogRead(VIBRATION_PIN_A0);
   Serial.print("Anaologue: ");         
   Serial.print(sensorVal);
   Serial.print(" Digital :");
   Serial.println(motionDetected);
   delay(100);
}