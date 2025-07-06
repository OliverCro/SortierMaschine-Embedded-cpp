/*
 * StateDetectColor.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateDetectColor.hpp"
#include "Context/FactoryContext.hpp"
#include "Util/Color.hpp"
#include "StateMoveToAuswurf.hpp"
#include "StateMoveToEnd.hpp"

StateDetectColor::StateDetectColor(FactoryContext* ctx) : context(ctx) {};

const char* StateDetectColor::getStateName() {
	return "DETECT COLOR";
}

const char* StateDetectColor::stateStatus(void) {
	static char buffer[12];
	snprintf(buffer, sizeof(buffer), "%d", context->farbsensor->getValue());
	return buffer;
}


IFactoryState* StateDetectColor::executeState() {
	Color color = context->farbsensor->getFarbe();

	switch (color) {
		case Color::BLUE:
			return new StateMoveToAuswurf(context);
		case Color::WHITE:
			return new StateMoveToEnd(context);
		default:
			// Stay in the same state if unknown
			return nullptr;
	}
}
