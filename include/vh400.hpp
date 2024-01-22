#if !defined(VH400_HPP_)
#define VH400_HPP_

#include <Arduino.h>

class Vh400
{
private:
    float voltsPerUnit;

    uint8_t adc_pin;

    float CalculateVWC(float voltage);

public:
    Vh400(uint8_t adc_pin, float operating_voltage = 5.0, int adc_bits = 10);
    ~Vh400();

    float Measure();
};

#endif // VH400_HPP_
