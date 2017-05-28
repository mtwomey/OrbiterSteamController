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

int XinputController::getLX() {
	updateState();
	return state.Gamepad.sThumbLX;
}

int XinputController::getLY() {
	updateState();
	return state.Gamepad.sThumbLY;
}

int XinputController::getRT() {
	updateState();
	return state.Gamepad.bRightTrigger;
}

int XinputController::getLT() {
	updateState();
	return state.Gamepad.bLeftTrigger;
}

double XinputController::getNormLX() {
	updateState();
	return max(-1, (double)state.Gamepad.sThumbLX / 32767);
}

double XinputController::getNormLY() {
	updateState();
	return max(-1, (double)state.Gamepad.sThumbLY / 32767);
}

double XinputController::getNormRT() {
	updateState();
	//return max(-1, (double)((state.Gamepad.bRightTrigger - 128) / 127));
	return (double)state.Gamepad.bRightTrigger / 255;
}

double XinputController::getNormLT() {
	updateState();
	//return max(-1, (double)((state.Gamepad.bLeftTrigger - 128) / 127));
	return (double)state.Gamepad.bLeftTrigger / 255;
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
