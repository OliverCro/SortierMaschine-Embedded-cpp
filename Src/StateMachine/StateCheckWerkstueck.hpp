/*
 * StateCheckWerkstueck.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATECHECKWERKSTUECK_HPP_
#define HEADER_STATEMACHINE_STATECHECKWERKSTUECK_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateCheckWerkstueck is responsible for checking if a Werkstueck is present in the stack.
 * If a Werkstueck is present, it transitions to the StatePushToBand state.
 * If no Werkstueck is present, it transitions to the StateIdle state.
 */
class StateCheckWerkstueck : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateCheckWerkstueck(FactoryContext* ctx);
	const char* getStateName(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATECHECKWERKSTUECK_HPP_ */
