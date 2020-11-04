/// <summary>
/// Use fingerprint sensor.
/// </summary>
// <copyright file="fingerprint.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <RoboCodeFingerprint.h>

#include <Adafruit_Fingerprint.h>

RoboCodeFingerprint fingerRC = RoboCodeFingerprint(2, 3);

// Adafruit_Fingerprint sensor
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint fingerA = Adafruit_Fingerprint(&mySerial);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int fingerId = fingerRC.getFingerID();
  if(fingerId == 0 && Serial.available() > 0) {
    saveFinger(fingerId);
  }
  if (fingerId >= 0) {
    Serial.print("I have found this fingerprint with id: "); Serial.println(fingerId); 
  }
 
  delay(50);
}

/// <summary>
/// Setup fingerprint sensor with robocode library.
/// </summary>
void setupFingerprintSensorWithRobocodeLibrary() {
  fingerRC.begin(57600);
  fingerRC.getTemplateCount();
  Serial.print("Sensor contains "); 
  Serial.print(fingerRC.templateCount); 
  Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

/// <summary>
/// setup fingerprint sensor with adafruit fingerprint library.
/// </summary>
void setupFingerprintSensorWithAdafruitFingerprintLibrary() {
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  fingerA.begin(57600);
  
  if (fingerA.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  fingerA.getTemplateCount();
  Serial.print("Sensor contains ");
  Serial.print(fingerA.templateCount);
  Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

/// <summary>
/// Save finger to fingerprint sensor with robocode library.
/// </summary>
/// <param name="fingerId">fingerId.</param>
void saveFingerInRobocodeLibrary(int fingerId){
  int id = Serial.parseInt();
  Serial.print("Writing ID #");
  Serial.println(id);
  fingerRC.writeNewFinger(id);
}

/// <summary>
/// Get fingerprint id.
/// </summary>
uint8_t getFingerprintID() {
  uint8_t p = fingerA.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = fingerA.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = fingerA.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(fingerA.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(fingerA.confidence); 

  return fingerA.fingerID;
}

/// <summary>
/// Check finger with adafruit fingerprint library.
/// </summary>
// returns -1 if failed, otherwise returns ID #
int checkFingerWithAdafruitFingerprintLibrary() {
  uint8_t p = fingerA.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = fingerA.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = fingerA.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(fingerA.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(fingerA.confidence);
  return fingerA.fingerID; 
}