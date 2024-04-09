#include "vh400_helper.hpp"

constexpr float Vh400Helper::CalculateVwc(const uint16_t &value, const float &operating_voltage, const int &adc_bits)
{
    const int adcRange = (1 << adc_bits) - 1;                // Calculate max value
    const float voltsPerUnit = operating_voltage / adcRange; // Calculate the amount of volt 1 unit is
    const float voltage = value * voltsPerUnit;

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

        return 62.5f * voltage - 87.5f;
    }

    if (voltage > 3.0f)
    {
        return 100.0f;
    }

    // If no correct voltage return -1
    return -1;
}