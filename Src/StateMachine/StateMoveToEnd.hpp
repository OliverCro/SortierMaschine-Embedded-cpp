/*
 * StateMoveToEnd.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEMOVETOEND_HPP_
#define HEADER_STATEMACHINE_STATEMOVETOEND_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateMoveToEnd is responsible for moving a Werkstueck to the end position.
 * If the end position is reached, it transitions to the StateProcessing state.
 */
class StateMoveToEnd : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateMoveToEnd(FactoryContext* ctx);
	const char* getStateName(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEMOVETOEND_HPP_ */
