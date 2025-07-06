/*
 * StatePushToBand.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StatePushToBand.hpp"
#include "Context/FactoryContext.hpp"
#include "StateDetectColor.hpp"

StatePushToBand::StatePushToBand(FactoryContext* ctx) : context(ctx) {}

const char* StatePushToBand::getStateName() {
	return "PUSH TO BAND";
}

IFactoryState* StatePushToBand::executeState() {
	HardwareContext* hwContext = context->hardware;

	// Activate valve and wait
	hwContext->clock.start(200);
	hwContext->ventil_Stapel->set(true);

	while (!hwContext->clock.timeout()) {

	}

	hwContext->ventil_Stapel->set(false);

	return new StateDetectColor(context);
}
