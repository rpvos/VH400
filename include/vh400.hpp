#if !defined(VH400_HPP_)
#define VH400_HPP_

#include <Arduino.h>

class Vh400
{
private:
    uint8_t adc_pin;

public:
    Vh400(uint8_t adc_pin);
    ~Vh400();

    uint16_t Measure();
};

#endif // VH400_HPP_
