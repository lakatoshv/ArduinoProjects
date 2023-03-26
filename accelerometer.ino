/// <summary>
/// Use accelerometer.
/// </summary>
// <copyright file="accelerometer.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <MPU6050.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffset(true);
}

void loop() {
  mpu6050.update();

  Serial.println("Gyro X: ");
  Serial.print(mpu6050.getGyroX());
  Serial.print(" Gyro Y: ");
  Serial.print(mpu6050.getGyroY());
  Serial.print(" Gyro Z: ");
  Serial.print(mpu6050.getGyroZ());
  Serial.print(" Angle X: ");
  Serial.print(mpu6050.getAccAngleX());
  Serial.print(" Angle Y: ");
  Serial.print(mpu6050.getAccAngleY());

  // paint chart
  Serial.println(mpu6050.getAccAngleX());
  Serial.print(" ");
  Serial.print(mpu6050.getAccAngleY());

  delay(50);
}