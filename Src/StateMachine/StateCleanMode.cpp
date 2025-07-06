/*
 * StateCleanMode.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateCleanMode.hpp"
#include "Context/FactoryContext.hpp"
#include "Context/HardwareContext.hpp"
#include "StateIdle.hpp"

StateCleanMode::StateCleanMode(FactoryContext* ctx) : context(ctx) {}

const char* StateCleanMode::getStateName() {
	return "CLEAN MODE";
}

IFactoryState* StateCleanMode::executeState() {
	// activate conveyor belt and ejection valve
	context->motor->set(true);
	context->hardware->ventil_Auswurf->set(true);

	if(context->hardware->tasterClean->getEvent() == Digital::Event::ACTIVATED) {
		context->motor->set(false);
		context->hardware->ventil_Auswurf->set(false);

		return new StateIdle(context);
	}

	return nullptr;
}