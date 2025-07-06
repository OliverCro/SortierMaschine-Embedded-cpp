/*
 * StateMoveToEnd.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateMoveToEnd.hpp"
#include "Context/FactoryContext.hpp"
#include "StateProcessing.hpp"

StateMoveToEnd::StateMoveToEnd(FactoryContext* ctx) : context(ctx) {}

const char* StateMoveToEnd::getStateName() {
	return "MOVE TO END";
}

IFactoryState* StateMoveToEnd::executeState() {
	// Start motor
	context->motor->set(true);

	// Wait for detection
	if (context->schranke_verarbeitung->isDetected()) {
		context->motor->set(false);
		return new StateProcessing(context);
	}

	return nullptr; // stay in this state until detected
}