/*
 * Lichtschranke.cpp
 *
 *  Created on: Jun 22, 2025
 *      Author: victor
 */

#include "Lichtschranke.hpp"

Lichtschranke::Lichtschranke(Digital &pin)
  : pin_lichtschranke(&pin)
{}

bool Lichtschranke::isDetected() const {
    return pin_lichtschranke->get();
}


