/// <summary>
/// Smart Turnstile with LED and buzz.
/// </summary>
// <copyright file="smartTurnstileWithLEDAndBuzz.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Servo.h>

const int SERVO_PIN = 2;

const int OBSTACLE_SENSOR_PIN = 0;

const int LED_PIN = 3;

// RGB
const int RED_PIN = 5;
const int GREEN_PIN = 4;
const int BLUE_PIN = 3;

const int BUZZ_PIN = 6;

const int CLOSED = 0;
const int OPEN = 90;

Servo servo;

int  avoid;

void setup() {
   Serial.begin(9600);

   pinMode(OBSTACLE_SENSOR_PIN, INPUT);
   
   pinMode(RED_PIN, OUTPUT);
   pinMode(GREEN_PIN, OUTPUT);
   pinMode(BLUE_PIN, OUTPUT);

   pinMode(BUZZ_PIN, OUTPUT);

   servo.attach(SERVO_PIN);
}

void loop() {
   avoid = digitalRead(OBSTACLE_SENSOR_PIN);

   Serial.print("Avoid Sensor - "); 
   Serial.println(avoid);

   if (avoid == HIGH){
      openTurnstile();
   }
   else {
      closeTurnslite();
   }
}

/// <summary>
/// Open turnstile.
/// </summary>
void openTurnstile() {
   turnOnRGBLed(BLUE_PIN);
   turnOnBuzz(5);
   turnOnRGBLed(GREEN_PIN);
   servo.write(OPEN);
}

/// <summary>
/// Close turnslite.
/// </summary>
void closeTurnslite() {
   digitalWrite(BUZZ_PIN, LOW);
   turnOnRGBLed(RED_PIN);
   servo.write(CLOSED);
}

/// <summary>
/// Turn on buzz.
/// </summary>
/// <param name="count">count.</param>
void turnOnBuzz(int count) {
   for (int i = 0; i < count; i++) {
      digitalWrite(BUZZ_PIN, HIGH);
      delay(25);
      digitalWrite(BUZZ_PIN, LOW);
      delay(25);
   }
}

/// <summary>
/// Turn on RGB led.
/// </summary>
/// <param name="led">led.</param>
turnOnRGBLed(int led){
   if (led == BLUE_PIN) {
      digitalWrite(BLUE_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(RED_PIN, LOW);
   }
   else if (led == GREEN_PIN) {
      digitalWrite(BLUE_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(RED_PIN, LOW);
   }
   else if (led == RED_PIN) {
      digitalWrite(BLUE_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(RED_PIN, HIGH);
   }
}