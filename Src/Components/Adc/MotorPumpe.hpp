/*
 * MotorPumpe.hpp
 *
 *  Created on: May 28, 2025
 *      Author: victor
 */

#ifndef SRC_COMPONENTS_ADC_MOTORPUMPE_HPP_
#define SRC_COMPONENTS_ADC_MOTORPUMPE_HPP_

#include "EmbSysLib.h"

using namespace EmbSysLib::Dev;

// pressure‐control constants
#define PRESSURE_DELTA   0.05f
#define RAW_LOW          0.06f
#define RAW_HIGH         0.77f
#define REFERENCE_LOW    0.0f
#define REFERENCE_HIGH   1.0f
#define RAW_RANGE        (RAW_HIGH - RAW_LOW)
#define REFERENCE_RANGE  (REFERENCE_HIGH - REFERENCE_LOW)

/**
 * MotorPumpe is responsible for controlling the motor pump based on pressure readings.
 */
class MotorPumpe : public TaskManager::Task {
public:

    MotorPumpe(AnalogInAdc &adc,
               Digital     &pin_kompressor,
               TaskManager &taskmanager);

    void update() override;

    void set(bool value);

    bool get();

    float getCorrectedPressure();

private:
    float correctedValue();

    float const PRESSURE_LEVEL = 0.4f;
    AnalogInAdc *adc;
    Digital     *pin_kompressor;
};

#endif /* SRC_COMPONENTS_ADC_MOTORPUMPE_HPP_ */
