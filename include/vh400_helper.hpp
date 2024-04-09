#if !defined(VH400_HELPER_HPP_)
#define VH400_HELPER_HPP_

#include <stdint.h>

class Vh400Helper
{
public:
    static float CalculateVwc(const uint16_t &value, const float &operating_voltage = 5.0f, const int &adc_bits = 10);
};

#endif // VH400_HELPER_HPP_
