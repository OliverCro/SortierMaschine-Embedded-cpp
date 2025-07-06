/*
 * StateFinishProcessing.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEFINISHPROCESSING_HPP_
#define HEADER_STATEMACHINE_STATEFINISHPROCESSING_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateProcessing is responsible for removing the processed Werkstueck from the conveyor belt.
 * If the Werkstueck is successfully removed, it transitions to the StateCheckWerkstueck state.
 */
class StateFinishProcessing : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateFinishProcessing(FactoryContext* ctx);
	const char* getStateName(void);
	const char* stateStatus(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEFINISHPROCESSING_HPP_ */
