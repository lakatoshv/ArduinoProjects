/// <summary>
/// Use servo with potentiometer.
/// </summary>
// <copyright file="servoWithPotentiometer.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Servo.h>

Servo servo;

int potentiometerValue = 0;
int servoAngle = 0;
void setup() {
  servo.attach(2);

}

void loop() {
  potentiometerValue = analogRead(0);
  servoAngle = map(potentiometerValue, 0, 1023, 0, 180);
  servo.write(servoAngle);
}