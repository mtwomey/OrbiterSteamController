#define STRICT
#define ORBITER_MODULE

#include <Orbitersdk.h>
#include "XinputController.h"

XinputController controller;

DLLCLBK void InitModule(HINSTANCE hModule) {
	controller = XinputController();
}

DLLCLBK void opcPreStep(double simt, double simdt, double mjd) {
	sprintf(oapiDebugString(), "X: %f Y: %f R: %f", controller.getNormLX(), controller.getNormLY(), controller.getNormRT() + (controller.getNormLT() * -1));

	VESSEL* vessel = oapiGetFocusInterface();
	vessel->SetControlSurfaceLevel(AIRCTRL_ELEVATOR, controller.getNormLY() * -1, false);
	vessel->SetControlSurfaceLevel(AIRCTRL_AILERON, controller.getNormLX(), false);
	vessel->SetControlSurfaceLevel(AIRCTRL_RUDDER, controller.getNormRT() + (controller.getNormLT() * -1), false);
}
