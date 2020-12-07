/// <summary>
/// Use ultrasonic sonar.
/// </summary>
// <copyright file="sonar.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

// Ultrasonic distance sensor
const int ULTRASONIC_DISTANCE_SENSOR_OUTPUT_PIN = 12;
const int ULTRASONIC_DISTANCE_SENSOR_INPUT_PIN = 13;
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(ULTRASONIC_DISTANCE_SENSOR_OUTPUT_PIN, OUTPUT);
  pinMode(ULTRASONIC_DISTANCE_SENSOR_INPUT_PIN, INPUT);
}


void loop()
{
  Serial.print("Duration: ");
  Serial.print(	getDistanceToObstacle());
  Serial.println();
}

/// <summary>
/// Get distance to obstacle.
/// </summary>
long getDistanceToObstacle() {
  digitalWrite(ULTRASONIC_DISTANCE_SENSOR_OUTPUT_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(ULTRASONIC_DISTANCE_SENSOR_OUTPUT_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_DISTANCE_SENSOR_OUTPUT_PIN, LOW);
  duration = pulseIn(ULTRASONIC_DISTANCE_SENSOR_INPUT_PIN, HIGH);
  return (duration / 2) / 29.1;
}