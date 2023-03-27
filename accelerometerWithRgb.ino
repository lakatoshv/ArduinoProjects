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

// pauses
const int MIN_PAUSE=10;
const int MAX_PAUSE=100;
const int VIEW_PAUSE=2000;

int pause;

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

  setRGB(red, green, blue);

  setpause();
}

/// <summary>
/// Set color to RGB.
/// </summary>
/// <param name="r">red.</param>
/// <param name="g">green.</param>
/// <param name="b">blue.</param>
void setRGB(int r, int g, int b)
{
    analogWrite(RED_PIN, r);
    analogWrite(GREEN_PIN, g);
    analogWrite(BLUE_PIN, b);
    delay(pause);
}

/// <summary>
/// Set pause time from potentiometer.
/// </summary>
void setpause()
{
    pause = map(analogRead(POTENTIOMETER_PIN), 0, 1024, MIN_PAUSE, MAX_PAUSE);
    Serial.print("pause = ");
    Serial.println(pause);
    delay(VIEW_PAUSE); 
}