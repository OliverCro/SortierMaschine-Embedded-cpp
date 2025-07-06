/*
 * StateIdle.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateIdle.hpp"
#include "Context/FactoryContext.hpp"
#include "StateCheckWerkstueck.hpp"
#include "StateCleanMode.hpp"


StateIdle::StateIdle(FactoryContext* ctx) : context(ctx) {}

const char* StateIdle::getStateName() {
	return "IDLE";
}

const char* StateIdle::stateStatus(void) {
	return "Press User or S1 BTN";
}

IFactoryState* StateIdle::executeState() {
	if(context->hardware->tasterStart->getEvent() == Digital::Event::ACTIVATED) {
		return new StateCheckWerkstueck(context);
	}

	if(context->hardware->tasterClean->getEvent() == Digital::Event::ACTIVATED) {
		return new StateCleanMode(context);
	}

	return nullptr;
}
