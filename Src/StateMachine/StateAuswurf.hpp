/*
 * StateAuswurf.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEAUSWURF_HPP_
#define HEADER_STATEMACHINE_STATEAUSWURF_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateAuswurf is responsible for ejecting a Werkstueck from the machine.
 * It activates the Auswurf valve for a specific duration and then transitions to the StateCheckWerkstueck state.
 */
class StateAuswurf : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateAuswurf(FactoryContext* ctx);
	const char* getStateName(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEAUSWURF_HPP_ */
