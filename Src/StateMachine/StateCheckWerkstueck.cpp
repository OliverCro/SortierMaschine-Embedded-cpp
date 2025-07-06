/*
 * StateCheckWerkstueck.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "Context/FactoryContext.hpp"
#include "StateCheckWerkstueck.hpp"
#include "StatePushToBand.hpp"
#include "StateIdle.hpp"

StateCheckWerkstueck::StateCheckWerkstueck(FactoryContext* ctx) : context(ctx) {}

const char* StateCheckWerkstueck::getStateName() {
	return "CHECK INPUT";
}

IFactoryState* StateCheckWerkstueck::executeState() {
	if (context->schranke_stapel->isDetected()) {
		return new StatePushToBand(context);
	}

	return new StateIdle(context);
}