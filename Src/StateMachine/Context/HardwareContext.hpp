/*
 * HardwareContext.hpp
 *
 *  Created on: Jun 21, 2025
 *      Author: victor
 */

#ifndef SRC_STATEMACHINE_HARDWARECONTEXT_HPP_
#define SRC_STATEMACHINE_HARDWARECONTEXT_HPP_

#include "EmbSysLib.h"

using namespace EmbSysLib::Dev;


class HardwareContext {
public:

    Digital* tasterStart;
    Digital* tasterClean;
    Digital* ventil_Auswurf;
    Digital* ventil_Verarbeitung;
    Digital* ventil_Stapel;
    TaskManager::Clock clock;


    HardwareContext
	(
			Digital* user,
			Digital* s1,
			Digital* ventil_Auswurf,
			Digital* ventil_Verarbeitung,
			Digital* ventil_Stapel,
			TaskManager& tm
	)
      : tasterStart(user), 
        tasterClean(s1), 
        ventil_Auswurf(ventil_Auswurf), 
        ventil_Verarbeitung(ventil_Verarbeitung), 
        ventil_Stapel(ventil_Stapel),
        clock(tm)
    {}
};




#endif /* SRC_STATEMACHINE_HARDWARECONTEXT_HPP_ */
