/*
 * StateProcessing.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEPROCESSING_HPP_
#define HEADER_STATEMACHINE_STATEPROCESSING_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateProcessing is responsible for processing a Werkstueck.
 * If the processing is successful, it transitions to the StateFinishProcessing state.
 */
class StateProcessing : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateProcessing(FactoryContext* ctx);
	const char* getStateName(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEPROCESSING_HPP_ */
