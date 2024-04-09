#include <Arduino.h>
#include "vh400.hpp"
#include "vh400_helper.hpp"

// Red wire to 5v
// Black to ground
// White wire to pin set below
#define VwcSensorPin A0

Vh400 vh400 = Vh400(VwcSensorPin);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(VwcSensorPin, INPUT);
}

void loop()
{

  // Calculation method from company
  // float temperatureInCelsius = voltage * 41.67 - 40;
  // float temperatureInFahrenheit = voltage * 75.006 - 40;
  uint16_t value = vh400.Measure();
  float vwc = Vh400Helper::CalculateVwc(value);
  Serial.print("VWC (%): ");
  Serial.println(value);
  delay(1000);
}
