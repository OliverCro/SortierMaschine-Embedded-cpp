/*
 * StateAuswurf.cpp
 *
 *  Created on: Jun 16, 2025
 *      Author: olive
 */
#include "StateAuswurf.hpp"
#include "StateCheckWerkstueck.hpp"
#include "Context/HardwareContext.hpp"
#include "Context/FactoryContext.hpp"


using namespace EmbSysLib::Dev;

StateAuswurf::StateAuswurf(FactoryContext* ctx) : context(ctx) {}

const char* StateAuswurf::getStateName() {
	return "AUSWURF";
}

IFactoryState* StateAuswurf::executeState() {
	HardwareContext* hardware = context->hardware;

	hardware->clock.start(200);
	hardware->ventil_Auswurf->set(true);
	while (!hardware->clock.timeout()) {}
	hardware->ventil_Auswurf->set(false);

	context->verarbeiteteWerkstuecke++;
	return new StateCheckWerkstueck(context);
}