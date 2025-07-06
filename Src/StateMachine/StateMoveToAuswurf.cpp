/*
 * StateMoveToAuswurf.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateMoveToAuswurf.hpp"
#include "Context/FactoryContext.hpp"
#include "StateAuswurf.hpp"

StateMoveToAuswurf::StateMoveToAuswurf(FactoryContext* ctx) : context(ctx) {}

const char* StateMoveToAuswurf::getStateName() {
	return "MOVE TO AUSWURF";
}

const char* StateMoveToAuswurf::stateStatus(void) {
	static char buffer[12];
	snprintf(buffer, sizeof(buffer), "%d", context->motor->getCounter());
	return buffer;
}

IFactoryState* StateMoveToAuswurf::executeState() {
	TaskManager::Clock clock = context->hardware->clock;
	// Entprellen des Tasters (debounce delay)
	clock.start(10);
	while (!clock.timeout()) {
		
	}

	// Try to move the motor to limit; wait if not reached yet
	if (context->motor->runUntilLimitReached(15)) {
		return new StateAuswurf(context);
	}
	return nullptr; // stay in current state until done
}
