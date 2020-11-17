/// <summary>
/// Smart Turnstile.
/// </summary>
// <copyright file="smartTurnstile.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Servo.h>

const int SERVO_PIN = 2;

const int OBSTACLE_SENSOR_PIN = 0;
const int LED_PIN = 3;

const int CLOSED = 0;
const int OPEN = 90;

Servo servo;

int  avoid;

void setup() {
   Serial.begin(9600);

   pinMode(OBSTACLE_SENSOR_PIN, INPUT);
   pinMode(LED_PIN, OUTPUT);
   
   servo.attach(SERVO_PIN);
}

void loop() {
   avoid = digitalRead(OBSTACLE_SENSOR_PIN);

   Serial.print("Avoid Sensor - ");
   Serial.println(avoid);

   if (avoid == HIGH){
      digitalWrite(LED_PIN, LOW);
      servo.write(OPEN);
   }
   else {
      digitalWrite(LED_PIN, HIGH);
      servo.write(CLOSED);
   }
}