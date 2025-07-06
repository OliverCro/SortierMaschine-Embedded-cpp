/*
 * StateCleanMode.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATECLEANMODE_HPP_
#define HEADER_STATEMACHINE_STATECLEANMODE_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateCleanMode is responsible for cleaning the machine.
 * It activates the cleaning mode, which involves running the conveyor belt and the ejection valve is activated.
 * If the clean button is pressed, it stops the cleaning mode and transitions to the StateIdle state.
 */
class StateCleanMode : public IFactoryState {
private:
	FactoryContext *context;

public:
	StateCleanMode(FactoryContext* ctx);
	const char* getStateName(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATECLEANMODE_HPP_ */
