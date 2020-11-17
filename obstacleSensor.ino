
/// <summary>
/// Use obstacle sensor.
/// </summary>
// <copyright file="obstacleSensor.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int OBSTACLE_SENSOR_PIN = 0;
const int LED_PIN = 3;

const int CLOSED = 0;
const int OPEN = 90;

int  avoid;

void setup() {
   Serial.begin(9600);

   pinMode(OBSTACLE_SENSOR_PIN, INPUT);
   pinMode(LED_PIN, OUTPUT);
}

void loop() {
   avoid = digitalRead(OBSTACLE_SENSOR_PIN);

   Serial.print("Avoid Sensor - ");
   Serial.println(avoid);

   if (avoid == HIGH){
      digitalWrite(LED_PIN, LOW);
   }
   else {
      digitalWrite(LED_PIN, HIGH);
   }
}