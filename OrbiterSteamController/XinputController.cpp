#include "XinputController.h"


XinputController::XinputController() {
	init();
}


XinputController::~XinputController() {

}

void XinputController::init() {
	setControllerNumber();
	updateState();
}

void XinputController::updateState() {
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	XInputGetState(controllerNumber, &state);
}

int XinputController::getLX()
{
	updateState();
	XInputGetState(controllerNumber, &state);
	return state.Gamepad.sThumbLX;
}

void XinputController::setControllerNumber() // Sets the controller to the first connected controller
{
	int controllerId = -1;
	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
	{
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS)
			controllerId = i;
	}
	controllerNumber = controllerId;
}
