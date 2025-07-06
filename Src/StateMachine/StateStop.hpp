/*
 * StateStop.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATESTOP_HPP_
#define HEADER_STATEMACHINE_STATESTOP_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/** 
 * StateStop is responsible for stopping the factory machine.
 * If the Start/Stop button is pressed, it transitions to the last state.
*/
class StateStop : public IFactoryState {
private:
	FactoryContext* context;
	IFactoryState* lastState;

public:
	StateStop(FactoryContext* ctx, IFactoryState* previous);

	const char* getStateName(void);
	const char* stateStatus(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATESTOP_HPP_ */
