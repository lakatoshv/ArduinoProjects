/// <summary>
/// Use potentiometer and led with shim signal.
/// </summary>
// <copyright file="potentiometerWithLed.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int POTENTIOMETER_PIN = 0;
const int LED_PIN = 3;

void setup() {
}

void loop() {
  int value = analogRead(POTENTIOMETER_PIN)/4;
  analogWrite(LED_PIN, value);
  delay(100);
}