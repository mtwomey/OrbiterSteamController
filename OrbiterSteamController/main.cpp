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
	sprintf(oapiDebugString(), "LX: %f LY: %f LT+RT: %f RX: %f RY: %f", controller.normState.LX, controller.normState.LY, controller.normState.RT + (controller.normState.LT * -1), controller.normState.RX, controller.normState.RY);
    #endif

	VESSEL* vessel = oapiGetFocusInterface();
	controller.update();
	vessel->SetControlSurfaceLevel(AIRCTRL_ELEVATOR, controller.normState.LY * -1, false);
	vessel->SetControlSurfaceLevel(AIRCTRL_AILERON, controller.normState.LX, false);
	vessel->SetControlSurfaceLevel(AIRCTRL_RUDDER, controller.normState.RT + (controller.normState.LT * -1), false);

	// An experiment with controlling the view with the RS directly. Not really needed as you can bind either pad to a mouse with the right button held down
	//oapiCameraSetCockpitDir((roundf(controller.normState.RX * 1000) / 1000) * -1, roundf(controller.normState.RY * 1000) / 1000, false);
}
