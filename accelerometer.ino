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
  Serial.println(mpu6050.getGyroX());
  Serial.println(" Gyro Y: ");
  Serial.println(mpu6050.getGyroY());
  Serial.println(" Gyro Z: ");
  Serial.println(mpu6050.getGyroZ());
  Serial.println(" Angle X: ");
  Serial.println(mpu6050.getAccAngleX());
  Serial.println(" Angle Y: ");
  Serial.println(mpu6050.getAccAngleY());

  // paint chart
  Serial.println(mpu6050.getAccAngleX());
  Serial.println(" ");
  Serial.println(mpu6050.getAccAngleY());

  delay(50);
}