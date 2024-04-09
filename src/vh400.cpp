#include "vh400.hpp"

Vh400::Vh400(uint8_t adc_pin)
{
    this->adc_pin = adc_pin;
}

Vh400::~Vh400()
{
}

uint16_t Vh400::Measure()
{
    // Read the analog pin
    return analogRead(this->adc_pin);
}
