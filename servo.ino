/// <summary>
/// Use servo.
/// </summary>
// <copyright file="servo.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(2);

}

void loop() {
  servo.write(0);
  delay(2000);
  servo.write(180);
  delay(2000);
}