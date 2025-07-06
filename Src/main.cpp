//*******************************************************************
#include "EmbSysLib.h"
#include "Module/Rtos/Rtos.h"
#include "ReportHandler.h"
#include "config.h"

#include "StateMachine/Control/Controller.hpp"
#include "Components/Adc/Farbsensor.hpp"
#include "Components/Digital/Lichtschranke.hpp"
#include "Components/Digital/Motor.hpp"
#include "Components/Adc/MotorPumpe.hpp"
#include "Components/Display/MaschinenStatusAnzeige.hpp"

#include "StateMachine/Context/HardwareContext.hpp"

int main(void)
{
	Adc_Mcu adc(timer);
	AnalogInAdc druck(adc, 2);
	MotorPumpe pumpe(druck, motor_Kompressor_P, taskManager);
	Motor motor(motor_Band_P, inkremental_Band_P);
	Lichtschranke schranke_stapel(lichtschranke_Stapel_P);
	Lichtschranke schranke_verarbeitung(lichtschranke_Verarb_P);
	Farbsensor farbsensor(adc);

	// Initialize HardwareContext
	HardwareContext hwContext(&tasterUSER,
			&tasterS1PC0,
			&ventil_Auswurf,
			&ventil_Verarbeitung_P,
			&ventil_Stapel_P,
			taskManager);

	FactoryContext context(&motor, &pumpe, &schranke_stapel, &schranke_verarbeitung, &farbsensor, &hwContext);

	// Controller mit initialem Zustand (IDLE)
	Controller controller(context, taskManager);

	MaschinenStatusAnzeige anzeige(controller, pumpe, taskManager);

	while(1) {
		controller.updateFactoryState();
	}
}
//EOF
