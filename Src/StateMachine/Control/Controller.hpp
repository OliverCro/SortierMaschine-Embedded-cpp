/*
 * Controller.hpp
 *
 *  Created on: Jun 2, 2025
 *      Author: victor
 */

#ifndef SRC_CONTROLLER_HPP_
#define SRC_CONTROLLER_HPP_

#include "StateMachine/IFactoryState.hpp"
#include "StateMachine/Context/FactoryContext.hpp"

/**
 * Controller for managing the state of the factory.
 */
class Controller : public TaskManager::Task {
private:
	FactoryContext* context;
	IFactoryState* currentState;

public:
	Controller(FactoryContext &context, TaskManager &taskManager);

	void update() override;
	void updateFactoryState();

	IFactoryState* getCurrentState();
	FactoryContext* getFactoryContext();
};

#endif /* SRC_CONTROLLER_HPP_ */
