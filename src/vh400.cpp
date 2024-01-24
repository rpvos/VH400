#include "vh400.hpp"

float Vh400::CalculateVWC(float voltage)
{
    // 0 to 1.1V	    VWC = 10*V-1
    if (voltage < 1.1f)
    {
        if (voltage >= 0.1f)
        {
            return 10 * voltage - 1;
        }
        return 0.0f;
    }
    // 1.1V to 1.3V	    VWC = 25*V- 17.5
    else if (1.1f <= voltage && voltage < 1.3f)
    {
        return 25 * voltage - 17.5f;
    }
    // 1.3V to 1.82V	VWC = 48.08*V- 47.5
    else if (1.3f <= voltage && voltage < 1.82f)
    {
        return 48.08f * voltage - 47.5f;
    }
    // 1.82V to 2.2V	VWC = 26.32*V- 7.89
    else if (1.82f <= voltage && voltage < 2.2f)
    {
        return 26.32f * voltage - 7.89f;
    }
    // 2.2V - 3.0V	    VWC = 62.5*V - 87.5
    else if (2.2f <= voltage && voltage <= 3.0f)
    {
        if (voltage > 3.0f)
        {
            return 100.0f;
        }

        return 62.5f * voltage - 87.5f;
    }

    // If no correct voltage return -1
    return -1;
}

Vh400::Vh400(uint8_t adc_pin, float operating_voltage, int adc_bits)
{
    this->adc_pin = adc_pin;

    int adcRange = (1 << adc_bits) - 1;          // Calculate max value
    voltsPerUnit = operating_voltage / adcRange; // Calculate the amount of volt 1 unit is
}

Vh400::~Vh400()
{
}

float Vh400::Measure()
{
    // Read the analog pin
    int value = analogRead(this->adc_pin);

    // Calculate the voltage of the pin
    float voltage = value * voltsPerUnit;

    return CalculateVWC(voltage);
}
