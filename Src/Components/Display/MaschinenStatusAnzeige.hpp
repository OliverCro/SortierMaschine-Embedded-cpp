#ifndef SRC_MASCHINENSTATUSANZEIGE_HPP_
#define SRC_MASCHINENSTATUSANZEIGE_HPP_

#include "EmbSysLib.h"
#include "StateMachine/Control/Controller.hpp"
#include "Components/Adc/MotorPumpe.hpp"
#include <cstring>

class MaschinenStatusAnzeige : public TaskManager::Task {

private:
    Controller* controller;
    MotorPumpe* pumpe;

public:

    MaschinenStatusAnzeige
	(
			Controller& controller,
			MotorPumpe& pumpe,
			TaskManager& taskManager)
    : controller(&controller),
	  pumpe(&pumpe)
    {
    	taskManager.add(this);
    }

    virtual void update() override {
        disp.printf(0, 0, "State: %-16s", controller->getCurrentState()->getStateName());
        disp.printf(1, 0, "%-20s", controller->getCurrentState()->stateStatus());
        disp.printf(2, 0, "Druck: %.1f%%", pumpe->getCorrectedPressure() * 100);
        disp.printf(3, 0, "Zaehler: %d", controller->getFactoryContext()->verarbeiteteWerkstuecke);
        disp.refresh();
    }

    friend class Controller;
};

#endif /* SRC_MASCHINENSTATUSANZEIGE_HPP_ */
