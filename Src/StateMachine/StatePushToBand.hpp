/*
 * StatePushToBand.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_STATEPUSHTOBAND_HPP_
#define HEADER_STATEMACHINE_STATEPUSHTOBAND_HPP_

#include "IFactoryState.hpp"

class FactoryContext;

/**
 * StatePushToBand is responsible for pushing a Werkstueck onto the conveyor belt.
 * If the push is successful, it transitions to the StateDetectColor state.
 */
class StatePushToBand : public IFactoryState {
private:
	FactoryContext* context;
public:
	StatePushToBand(FactoryContext* ctx);
	const char* getStateName(void);
	IFactoryState* executeState(void);
};

#endif /* HEADER_STATEMACHINE_STATEPUSHTOBAND_HPP_ */
