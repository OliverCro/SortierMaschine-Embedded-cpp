/*
 * Farbsensor.hpp
 *
 *  Created on: May 26, 2025
 *      Author: victor
 */

#ifndef SRC_COMPONENTS_ADC_FARBSENSOR_HPP_
#define SRC_COMPONENTS_ADC_FARBSENSOR_HPP_

#include "EmbSysLib.h"
#include "Util/Color.hpp"

#define COLOR_BLUE   56000
#define COLOR_WHITE   5400

using EmbSysLib::Hw::Adc_Mcu;

struct ColorThreshold {
    int   value;
    Color color;
};

/**
 * Adc Farbsensor for detecting colors based on ADC values.
 */
class Farbsensor {
public:
    // Constructor with default tolerance
    explicit Farbsensor(Adc_Mcu &adc);

    // Constructor with custom tolerance
    Farbsensor(int abweichung, Adc_Mcu &adc);

    Color getFarbe();

    // raw ADC value
    int getValue() const;

private:
    int      abweichung;
    Adc_Mcu *adc;

    static const ColorThreshold thresholds[2];
};

#endif /* SRC_COMPONENTS_ADC_FARBSENSOR_HPP_ */
