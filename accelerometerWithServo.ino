/// <summary>
/// Use accelerometer with servo.
/// </summary>
// <copyright file="accelerometerWithServo.ino" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <MPU6050.h>
#include <Wire.h>
#include <Servo.h>

MPU6050 mpu6050(Wire);
Servo servo;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffset(true);
  servo.attach(2);
}

void loop() {
  mpu6050.update();

  int x = mpu6050.getAccAngleX();
  if(x > 0) {
    servo.write(x);
  }

  delay(200);
}