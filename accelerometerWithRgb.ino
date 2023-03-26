/// <summary>
/// Use accelerometer with RGB.
/// </summary>
// <copyright file="accelerometerWithRgb.ino" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <MPU6050.h>
#include <Wire.h>

// RGB
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

MPU6050 mpu6050(Wire);

int red;
int green;
int blue;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffset(true);
}

void loop() {
  mpu6050.update();
  red = 255 - mpu6050.getGyroX();
  green = 255 - mpu6050.getGyroY();
  blue = 255 - mpu6050.getGyroZ();

  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);

  delay(50);
}