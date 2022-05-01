#include <Arduino.h>

const int switchPin = 2;
const int motorPin = 9;
int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;
int switchState = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);

  while (millis() < 5000)
  {
    sensorVal = analogRead(A0);
    if (sensorVal > sensorHigh)
    {
      sensorHigh = sensorVal;
    }
    if (sensorVal < sensorLow)
    {
      sensorLow = sensorVal;
    }
  }
}

void loop()
{
  sensorVal = analogRead(A0);
  if (sensorVal < sensorHigh / 1.7)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }

  // switchState = digitalRead(switchPin);
  // if (switchState == HIGH)
  //{
  // digitalWrite(motorPin, HIGH);
  //}
  // else
  //{
  // digitalWrite(motorPin, LOW);
  //}
}
