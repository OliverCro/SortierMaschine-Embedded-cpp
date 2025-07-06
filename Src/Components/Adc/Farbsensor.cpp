/*
 * Farbsensor.cpp
 *
 *  Created on: Jun 22, 2025
 *      Author: victor
 */

#include "Farbsensor.hpp"
#include <cmath>

// Mapping of raw ADC values to colors
const ColorThreshold Farbsensor::thresholds[2] = {
    { COLOR_BLUE,  Color::BLUE  },
    { COLOR_WHITE, Color::WHITE }
};

Farbsensor::Farbsensor(Adc_Mcu &adc)
    : abweichung(2000),
      adc(&adc)
{
    adc.enable(3);
}

Farbsensor::Farbsensor(int abweichung, Adc_Mcu &adc)
    : abweichung(abweichung),
      adc(&adc)
{
    adc.enable(3);
}

Color Farbsensor::getFarbe() {
    // Read the ADC value and classify it based on thresholds
    int val = adc->get(3);
    for (const auto &t : thresholds) {
        if (std::abs(val - t.value) <= abweichung) {
            return t.color;
        }
    }
    return Color::UNKNOWN;
}

int Farbsensor::getValue() const {
    return adc->get(3);
}

