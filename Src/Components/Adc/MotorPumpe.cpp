/*
 * MotorPumpe.cpp
 *
 *  Created on: Jun 22, 2025
 *      Author: victor
 */

#include "MotorPumpe.hpp"

MotorPumpe::MotorPumpe(AnalogInAdc &adc,
                       Digital     &pin_kompressor,
                       TaskManager &taskmanager)
  : adc(&adc)
  , pin_kompressor(&pin_kompressor)
{
    adc.enable();
    taskmanager.add(this);
}

/**
 * Update the motor pump state based on pressure readings.
 * If the pressure is below the defined PRESSURE_LEVEL, the compressor is turned on.
 */
void MotorPumpe::update() {
    float p = correctedValue();
    if (p < PRESSURE_LEVEL) {
        pin_kompressor->set(true);
    }
    if (p > PRESSURE_LEVEL + PRESSURE_DELTA) {
        pin_kompressor->set(false);
    }
}

void MotorPumpe::set(bool value) {
    pin_kompressor->set(value);
}

bool MotorPumpe::get() {
    return pin_kompressor->get();
}

float MotorPumpe::getCorrectedPressure() {
    return correctedValue();
}

/**
 * Maps the raw ADC value to a value in the range [0.0, 1.0] via linear transformation.
 */
float MotorPumpe::correctedValue() {
    return (((adc->get() - RAW_LOW) * REFERENCE_RANGE) / RAW_RANGE) + REFERENCE_LOW;
}


