/*
 * Motor.cpp
 *
 *  Created on: Jun 22, 2025
 *      Author: victor
 */
#include "Motor.hpp"

Motor::Motor(Digital &pin_motor, Digital &pin_geber)
    : pin_motor(&pin_motor),
      pin_geber(&pin_geber),
      counter(0),
      counterLimit(0),
      reached(false)
{}

void Motor::setCounterLimit(int limit)
{
    this->counterLimit = limit;
}

bool Motor::runUntilLimitReached(int limit)
{
    setCounterLimit(limit);
    set(true);
    if (!getReached()) {
        update();
        return false;
    } else {
        set(false);
        reset();
        return true;
    }
}

int Motor::getCounter()
{
    return this->counter;
}

void Motor::update()
{
    if(pin_geber->getEvent() != Digital::Event::NONE) {
        counter++;
        if(counter >= counterLimit) {
            reached = true;
        }
    }
}

bool Motor::getReached()
{
    return this->reached;
}

void Motor::toggle()
{
    this->pin_motor->toggle();
}

void Motor::set(bool value)
{
    this->pin_motor->set(value);
}

bool Motor::get()
{
    return this->pin_motor->get();
}

void Motor::reset()
{
    counter = 0;
    counterLimit = 0;
    reached = false;
}
