/*
 * StateMoveToAuswurf.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEMOVETOAUSWURF_HPP_
#define HEADER_STATEMACHINE_STATEMOVETOAUSWURF_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateMoveToAuswurf is responsible for moving a Werkstueck to the Auswurf position.
 * If the move is successful, it transitions to the StateAuswurf state.
 */
class StateMoveToAuswurf : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateMoveToAuswurf(FactoryContext* ctx);
	const char* getStateName(void);
	const char* stateStatus(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEMOVETOAUSWURF_HPP_ */
