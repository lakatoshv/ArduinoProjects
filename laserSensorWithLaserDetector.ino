/// <summary>
/// Use laser Sensor With Laser Detector.
/// </summary>
// <copyright file="laserSensorWithLaserDetector.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int LASER_DETECTOR_PIN = 2;
const int LASER_SENSOR_PIN = 3;
void setup() {
  Serial.begin(9600);
  pinMode(LASER_DETECTOR_PIN, INPUT);
  pinMode(LASER_SENSOR_PIN, OUTPUT);
  
  digitalWrite(LASER_SENSOR_PIN, HIGH);
}

void loop() {
  int detected = digitalRead(LASER_DETECTOR_PIN);

  if(detected == HIGH){
    Serial.println("Detected");
  }
  else {
    Serial.println("No laser");
  }
}