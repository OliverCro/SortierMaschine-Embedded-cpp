/*
 * Controller.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "Controller.hpp"
#include "StateMachine/StateCleanMode.hpp"
#include "StateMachine/StateIdle.hpp"
#include "StateMachine/StateStop.hpp"
#include "string"

Controller::Controller(FactoryContext &context, TaskManager &taskManager)
	: context(&context)
{
	currentState = new StateIdle(&context);
	taskManager.add(this);
}

void Controller::update() {
	if (context->hardware->tasterStart->getEvent() == Digital::Event::ACTIVATED &&
		currentState->getStateName() != std::string("CLEAN MODE")) {
		currentState = new StateStop(context, currentState);
	}
}

void Controller::updateFactoryState() {
	IFactoryState* next = currentState->executeState();
	if(next) {
		delete currentState;
		currentState = next;
	}
}

IFactoryState* Controller::getCurrentState() {
	return currentState;
}

FactoryContext* Controller::getFactoryContext() {
	return context;
}
