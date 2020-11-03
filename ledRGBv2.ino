/// <summary>
/// Use Led RGB v2.
/// </summary>
// <copyright file="ledRGBv2.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int POTENTIOMETER_PIN = 2;

const int LEDS_COUNT = 8;
const int RED_LED_RGB_PIN = 2;
const int GREEN_LED_RGB_PIN = 3;
const int BLUE_LED_RGB_PIN = 4;
const int LED_RGB_PINS[LEDS_COUNT] = { 5, 6, 7, 8, 9, 10, 11, 12 };

const int LEFT_LED_RGB_CENTER = 8;
const int RIGHT_LED_RGB_CENTER = 9;

void setup()
{
  //all pins are outputs and we are using 2 to 13
  for (int ledPin = 0; ledPin < LEDS_COUNT; ledPin++)
  {
    pinMode(LED_RGB_PINS[ledPin], OUTPUT);
    digitalWrite(ledPin, HIGH);
  }

  pinMode(RED_LED_RGB_PIN, OUTPUT);
  digitalWrite(RED_LED_RGB_PIN, HIGH);
  pinMode(GREEN_LED_RGB_PIN, OUTPUT);
  digitalWrite(GREEN_LED_RGB_PIN, HIGH);
  pinMode(BLUE_LED_RGB_PIN, OUTPUT);
  digitalWrite(BLUE_LED_RGB_PIN, HIGH);
}
 
void loop()
{
  cycle();
}

/// <summary>
/// Use random color.
/// </summary>
void color()
{
  int random1 = (rand() % 4) + 1;
  int random2 = (rand() % 4) + 1;
  int random3 = (rand() % 4) + 1;

  digitalWrite(RED_LED_RGB_PIN, LOW);
  digitalWrite(GREEN_LED_RGB_PIN, LOW);
  digitalWrite(BLUE_LED_RGB_PIN, LOW);

  if(RED_LED_RGB_PIN == random1 || RED_LED_RGB_PIN == random2 || RED_LED_RGB_PIN == random3) {
    digitalWrite(RED_LED_RGB_PIN, HIGH);
  }
  if(GREEN_LED_RGB_PIN == random1 || GREEN_LED_RGB_PIN == random2 || GREEN_LED_RGB_PIN == random3) {
    digitalWrite(GREEN_LED_RGB_PIN, HIGH);
  }
  if(BLUE_LED_RGB_PIN == random1 || BLUE_LED_RGB_PIN == random2 || BLUE_LED_RGB_PIN == random3) {
    digitalWrite(BLUE_LED_RGB_PIN, HIGH);
  }
}
 
/// <summary>
/// Turn Led light on.
/// </summary>
void cycle()
{
  for (int ledPin = 0; ledPin < LEDS_COUNT; ledPin++)
  {
    color();
    digitalWrite(LED_RGB_PINS[ledPin], LOW);
    delay(100);
    digitalWrite(LED_RGB_PINS[ledPin], HIGH);
  }
}

/// <summary>
/// Turn Led light on from center to sides.
/// </summary>
void formCenterToSides()
{
  int potentiometerValue = analogRead(POTENTIOMETER_PIN) != 0 ? analogRead(POTENTIOMETER_PIN) : 250;
  int speed = potentiometerValue / 4;

  for(int leftLedPin = LED_RGB_PINS[0], rightLeftPin = LED_RGB_PINS[LEDS_COUNT]; leftLedPin <= LEFT_LED_RGB_CENTER, rightLeftPin >= RIGHT_LED_RGB_CENTER; leftLedPin++, rightLeftPin--)
    {
      color();
      delay(speed);
      digitalWrite(leftLedPin, potentiometerValue);
      digitalWrite(rightLeftPin, potentiometerValue);
    }
    delay(100);
    for(int leftLedPin = LEFT_LED_RGB_CENTER, rightLeftPin = RIGHT_LED_RGB_CENTER; leftLedPin >= LED_RGB_PINS[0], rightLeftPin <= LED_RGB_PINS[LEDS_COUNT]; leftLedPin--, rightLeftPin++)
    {
      delay(speed);
      digitalWrite(leftLedPin, LOW);
      digitalWrite(rightLeftPin, LOW);
    }
}

/// <summary>
/// Turn Led light on by potentiometer.
/// </summary>
void flashLedsFromPotentiometer()
{
  int diodes = map (analogRead(POTENTIOMETER_PIN), 0, 1023, LED_RGB_PINS[0], LED_RGB_PINS[LEDS_COUNT]) ;
  for (ledPin = LED_RGB_PINS[0]; ledPin <= diodes; ledPin++)
  {
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}