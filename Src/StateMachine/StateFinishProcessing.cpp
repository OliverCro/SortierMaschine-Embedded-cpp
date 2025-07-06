/*
 * StateFinishProcessing.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "Context/FactoryContext.hpp"
#include "StateFinishProcessing.hpp"
#include "StateCheckWerkstueck.hpp"

StateFinishProcessing::StateFinishProcessing(FactoryContext* ctx) : context(ctx) {}

const char* StateFinishProcessing::getStateName() {
	return "FINISH";
}

const char* StateFinishProcessing::stateStatus(void) {
	static char buffer[12];
	snprintf(buffer, sizeof(buffer), "%d", context->motor->getCounter());
	return buffer;
}

IFactoryState* StateFinishProcessing::executeState() {
	// Entprellen des Tasters (debounce delay)
	TaskManager::Clock clock = context->hardware->clock;
	clock.start(10);
	while (!clock.timeout()) {
		
	}

	if (context->motor->runUntilLimitReached(10)) {
		context->verarbeiteteWerkstuecke++;
		return new StateCheckWerkstueck(context);
	}

	return nullptr; // stay in this state until done
}
