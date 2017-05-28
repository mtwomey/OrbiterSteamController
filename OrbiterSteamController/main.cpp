#define STRICT
#define ORBITER_MODULE

#include <Orbitersdk.h>
#include <xinput.h>

int getFirstConnectedController();
int getLX(int controller);

int firstConnectedController = -1;
XINPUT_STATE state;

DLLCLBK void InitModule(HINSTANCE hModule) {
	firstConnectedController = getFirstConnectedController();
}

DLLCLBK void opcPreStep(double simt, double simdt, double mjd)
{
	/*sprintf(oapiDebugString(), "%.2f", oapiGetSimTime());*/
	//firstConnectedController = getFirstConnectedController();
	sprintf(oapiDebugString(), "First Controller: %d", getLX(firstConnectedController));

	VESSEL* vessel = oapiGetFocusInterface();
	//vessel->SetADCtrlMode(DWORD(0));

	vessel->SetControlSurfaceLevel(AIRCTRL_ELEVATOR, -1, false);
}

int getFirstConnectedController() {
	int controllerId = -1;

	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
	{
		
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS)
			controllerId = i;
	}
	return controllerId;
}

/*XINPUT_STATE updateControllerInputState() {
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	XInputGetState(firstConnectedController, &state);
}*/

int getLX(int controller) {
	if (controller > -1) {
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		XInputGetState(controller, &state);
		return state.Gamepad.sThumbLX;
	}
	else {
		return -1;
	}
}
int getLY(int controller) {
	if (controller > -1) {
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		XInputGetState(controller, &state);
		return state.Gamepad.sThumbLY;
	}
	else {
		return -1;
	}
}


/*
int getLX() {
	int controller = getFirstConnectedController();
	if (controller > -1) {
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		XInputGetState(controller, &state);
		return state.Gamepad.sThumbLX;
	} else {
		return -1;
	}
}
*/
