/*
 * Lichtschranke.hpp
 *
 *  Created on: May 26, 2025
 *      Author: victor
 */

#ifndef SRC_COMPONENTS_DIGITAL_LICHTSCHRANKE_HPP_
#define SRC_COMPONENTS_DIGITAL_LICHTSCHRANKE_HPP_

#include "EmbSysLib.h"

using namespace EmbSysLib::Dev;

/**
 * Lichtschranke is a digital component that detects the presence of an object
 */
class Lichtschranke {
public:

    Lichtschranke(Digital &pin);

    bool isDetected() const;

private:
    Digital *pin_lichtschranke;
};

#endif /* SRC_COMPONENTS_DIGITAL_LICHTSCHRANKE_HPP_ */
