/*
 * FactoryContext.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#ifndef HEADER_STATEMACHINE_FACTORYCONTEXT_HPP_
#define HEADER_STATEMACHINE_FACTORYCONTEXT_HPP_

#include "Components/Digital/Motor.hpp"
#include "Components/Adc/MotorPumpe.hpp"
#include "Components/Digital/Lichtschranke.hpp"
#include "Components/Adc/Farbsensor.hpp"
#include "../IFactoryState.hpp"
#include "HardwareContext.hpp"

class FactoryContext {
public:
	Motor* motor;
	MotorPumpe* pumpe;
	Lichtschranke* schranke_stapel;
	Lichtschranke* schranke_verarbeitung;
	Farbsensor* farbsensor;
	HardwareContext* hardware;
	int verarbeiteteWerkstuecke;


	FactoryContext
	(
			Motor* m,
			MotorPumpe* p,
			Lichtschranke* ss,
			Lichtschranke* sv,
			Farbsensor* fs,
			HardwareContext* hw
	)
		: motor(m),
		  pumpe(p),
		  schranke_stapel(ss),
		  schranke_verarbeitung(sv),
		  farbsensor(fs),
		  hardware(hw),
		  verarbeiteteWerkstuecke(0)

	{}
};

#endif /* HEADER_STATEMACHINE_FACTORYCONTEXT_HPP_ */
