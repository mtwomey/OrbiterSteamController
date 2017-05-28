#define STRICT
#define ORBITER_MODULE

//#define DEBUG

#include <Orbitersdk.h>
#include "XinputController.h"

XinputController controller;

DLLCLBK void InitModule(HINSTANCE hModule) {
	controller = XinputController();
}

DLLCLBK void opcPreStep(double simt, double simdt, double mjd) {
    #ifdef DEBUG
	sprintf(oapiDebugString(), "LX: %f LY: %f LT+RT: %f RX: %f RY: %f", controller.getNormLX(), controller.getNormLY(), controller.getNormRT() + (controller.getNormLT() * -1), controller.getNormRX(), controller.getNormRY());
    #endif

	VESSEL* vessel = oapiGetFocusInterface();
	vessel->SetControlSurfaceLevel(AIRCTRL_ELEVATOR, controller.getNormLY() * -1, false);
	vessel->SetControlSurfaceLevel(AIRCTRL_AILERON, controller.getNormLX(), false);
	vessel->SetControlSurfaceLevel(AIRCTRL_RUDDER, controller.getNormRT() + (controller.getNormLT() * -1), false);

	// An experiment with controlling the view with the RS directly. Not really needed as you can bind either pad to a mouse with the right button held down
	//oapiCameraSetCockpitDir((roundf(controller.getNormRX() * 1000) / 1000) * -1, roundf(controller.getNormRY() * 1000) / 1000, false);
}
