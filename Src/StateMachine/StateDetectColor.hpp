/*
 * StateDetectColor.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEDETECTCOLOR_HPP_
#define HEADER_STATEMACHINE_STATEDETECTCOLOR_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StateDetectColor is responsible for detecting the color of a Werkstueck.
 * If the Werkstueck is colored white, it transitions to the StateMoveToEnd state.
 * If the Werkstueck is colored black, it transitions to the StateMoveToAuswurf state.
 */
class StateDetectColor : public IFactoryState {
private:
	FactoryContext* context;

public:
	StateDetectColor(FactoryContext* ctx);

	const char* getStateName(void);
	const char* stateStatus(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEDETECTCOLOR_HPP_ */
