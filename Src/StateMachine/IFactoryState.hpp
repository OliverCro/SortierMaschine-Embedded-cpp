/*
 * IFactoryState.hpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */

#ifndef HEADER_STATEMACHINE_IFACTORYSTATE_HPP_
#define HEADER_STATEMACHINE_IFACTORYSTATE_HPP_

/**
 * Interface for Factory State Machine States
 * It includes methods for getting the state name, executing the state logic, and providing a status.
 */
class IFactoryState {
public:

	virtual ~IFactoryState() {

	}

	virtual const char* getStateName(void) = 0;

	// Return new State if there is a state change else Return nullptr
	virtual IFactoryState* executeState(void) = 0;

	// String for StatusDisplay
	virtual const char* stateStatus(void) {
		return "";
	}
};

#endif /* HEADER_STATEMACHINE_IFACTORYSTATE_HPP_ */
