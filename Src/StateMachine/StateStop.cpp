/*
 * StateStop.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateStop.hpp"
#include "Context/FactoryContext.hpp"
#include "Context/HardwareContext.hpp"

StateStop::StateStop(FactoryContext* ctx, IFactoryState* previous) : context(ctx), lastState(previous) {}

const char* StateStop::getStateName() {
	return "STOP";
}

const char* StateStop::stateStatus(void) {
	static char buffer[21];
	snprintf(buffer, sizeof(buffer), "P: %-17s", lastState->getStateName());
	return buffer;
}

IFactoryState* StateStop::executeState() {
	if (context->motor->get()) {
		context->motor->set(false);
	}

	if (context->hardware->tasterStart->getEvent() == Digital::Event::ACTIVATED) {
		return lastState;
	}

	return nullptr;
}
