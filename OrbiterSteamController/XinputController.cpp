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

int XinputController::getRX() {
	updateState();
	return state.Gamepad.sThumbRX;
}

int XinputController::getRY() {
	updateState();
	return state.Gamepad.sThumbRY;
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
	return max(-1, (double)getLX() / 32767); // Returns from -1 to 1
}

double XinputController::getNormLY() {
	return max(-1, (double)getLY() / 32767); // Returns from -1 to 1
}

double XinputController::getNormRX() {
	return max(-1, (double)getRX() / 32767); // Returns from -1 to 1
}

double XinputController::getNormRY() {
	return max(-1, (double)getRY() / 32767); // Returns from -1 to 1
}

double XinputController::getNormRT() {
	//return max(-1, (double)((getRT() - 128) / 127)); // Returns from -1 to 1
	return (double)getRT() / 255; // Returns from 0 to 1
}

double XinputController::getNormLT() {
	//return max(-1, (double)((getLT() - 128) / 127)); // Returns from -1 to 1
	return (double)getLT() / 255; // Returns from 0 to 1
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
