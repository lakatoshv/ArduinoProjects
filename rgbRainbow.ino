/// <summary>
/// Use rgb to make rainbow.
/// </summary>
// <copyright file="rgbRainbow.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int POTENTIOMETER_PIN = A0;

// RGB
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

int red;
int green;
int blue;

// pauses
const int MIN_PAUSE=10;
const int MAX_PAUSE=100;
const int VIEW_PAUSE=2000;

int pause;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    displayRainbowColors();
}

/// <summary>
/// Display rainbow colors.
/// </summary>
void displayRainbowColors()
{
    fromRedToYellowColor();
    fromYellowToGreen();
    fromGreenToLightBlue();
}

/// <summary>
/// From red to yellow colors.
/// </summary>
void fromRedToYellowColor()
{
    Serial.println("red - yellow");
    red = 255;
    green = 0;
    blue = 0;
    for(green = 0; green <= 255; green++) 
    {
        setRGB(red, green, blue); 
    }
    setpause();
}

/// <summary>
/// From yellow to green colors.
/// </summary>
void fromYellowToGreen()
{
    Serial.println("yellow - green"); 
    red = 255;
    green = 255;
    blue = 0; 
    for(red = 255; red >= 0; red--)
    {
        setRGB(red, green, blue);
    }
    setpause();
}

/// <summary>
/// From green to light blue colors.
/// </summary>
void fromGreenToLightBlue()
{
    Serial.println("green - light blue");
    red = 0;
    green = 255;
    blue = 0;
    for(blue = 0; blue <= 255; blue++)
    { 
        setRGB(red, green, blue);
    }
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
