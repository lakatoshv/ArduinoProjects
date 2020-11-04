/// <summary>
/// Use fingerprint sensor.
/// </summary>
// <copyright file="fingerprint.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <RoboCodeFingerprint.h>

RoboCodeFingerprint finger = RoboCodeFingerprint(2, 3);

void setup() {
  Serial.begin(9600);
  finger.begin(57600);

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

void loop() {
  int fingerId = finger.getFingerID();
  if(fingerId == 0 && Serial.available() > 0) {
    saveFinger(fingerId);
  }
  if (fingerId >= 0) {
    Serial.print("I have found this fingerprint with id: "); Serial.println(fingerId); 
  }
  delay(50);
}

/// <summary>
/// Save finger to fingerprint sensor.
/// </summary>
void saveFinger(int fingerId){
  int id = Serial.parseInt();
  Serial.print("Writing ID #");
  Serial.println(id);
  finger.writeNewFinger(id);
}