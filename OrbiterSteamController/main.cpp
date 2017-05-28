#define STRICT
#define ORBITER_MODULE

#include <Orbitersdk.h>
#include "XinputController.h"

XinputController controller;

DLLCLBK void InitModule(HINSTANCE hModule) {
	controller = XinputController();
}

DLLCLBK void opcPreStep(double simt, double simdt, double mjd) {
	sprintf(oapiDebugString(), "X: %d", controller.getLX());
}
