/*
 * StateProcessing.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateProcessing.hpp"
#include "Context/FactoryContext.hpp"
#include "StateFinishProcessing.hpp"

StateProcessing::StateProcessing(FactoryContext* ctx) : context(ctx) {}

const char* StateProcessing::getStateName() {
	return "PROCESSING";
}

IFactoryState* StateProcessing::executeState() {
	HardwareContext* hwContext = context->hardware;

	hwContext->clock.start(200);
	// Entprellen des Tasters (debounce delay)
	hwContext->ventil_Verarbeitung->set(true);
	while (!hwContext->clock.timeout()) {

	}

	hwContext->ventil_Verarbeitung->set(false);

	return new StateFinishProcessing(context);
}