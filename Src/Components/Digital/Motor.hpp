/*
 * Motor.hpp
 *
 *  Created on: May 26, 2025
 *      Author: victor
 */

#ifndef SRC_MOTOR_HPP_
#define SRC_MOTOR_HPP_

#include "EmbSysLib.h"
using namespace EmbSysLib::Dev;

/**
 * Motor for controlling the conveyor belt
 */
class Motor {
private:
    Digital *pin_motor;
    Digital *pin_geber;

    int counter;
    int counterLimit;
    bool reached;

public:
    Motor(Digital &pin_motor, Digital &pin_geber);

    void setCounterLimit(int limit);

    bool runUntilLimitReached(int limit);

    int getCounter();

    void update();

    bool getReached();

    void toggle();

    void set(bool value);

    bool get();

    void reset();
};

#endif /* SRC_MOTOR_HPP_ */
