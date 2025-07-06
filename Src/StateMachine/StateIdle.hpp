/*
 * StateIdle.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEIDLE_HPP_
#define HEADER_STATEMACHINE_STATEIDLE_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * Represents the idle state of the sorting machine.
 * In this state, the machine is waiting for either the start button is pressed or the clean button is pressed.
 * If the start button is pressed, it transitions to the StateCheckWerkstueck state.
 * If the clean button is pressed, it transitions to the StateCleanMode state.
 */
class StateIdle : public IFactoryState {
private:
	FactoryContext* context;
public:
	StateIdle(FactoryContext* ctx);
	const char* getStateName(void);
	const char* stateStatus(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEIDLE_HPP_ */
