#include "XinputController.h"

XinputController::XinputController() {
	init();
}

XinputController::~XinputController() {

}

// Creates "normalized" versions of analog state for use with Orbiter
void XinputController::update() {
	updateState();
	normState.LX = max(-1, (double)state.Gamepad.sThumbLX / 32767); // Returns from -1 to 1
	normState.LY = max(-1, (double)state.Gamepad.sThumbLY / 32767); // Returns from -1 to 1
	normState.RX = max(-1, (double)state.Gamepad.sThumbRX / 32767); // Returns from -1 to 1
	normState.RY = max(-1, (double)state.Gamepad.sThumbRY / 32767); // Returns from -1 to 1
	normState.RT = (double)state.Gamepad.bRightTrigger / 255; // Returns from 0 to 1
	normState.LT = (double)state.Gamepad.bLeftTrigger / 255; // Returns from 0 to 1
}

void XinputController::init() {
	setControllerNumber();
	updateState();
}

void XinputController::updateState() {
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	XInputGetState(controllerNumber, &state);
}


// Depreciated - use update() and XinputController.state instead (to avoid multiple Xinput calls)
int XinputController::getLX() {
	updateState();
	return state.Gamepad.sThumbLX;
}

// Depreciated - use update() and XinputController.state instead (to avoid multiple Xinput calls)
int XinputController::getLY() {
	updateState();
	return state.Gamepad.sThumbLY;
}

// Depreciated - use update() and XinputController.state instead (to avoid multiple Xinput calls)
int XinputController::getRX() {
	updateState();
	return state.Gamepad.sThumbRX;
}

// Depreciated - use update() and XinputController.state instead (to avoid multiple Xinput calls)
int XinputController::getRY() {
	updateState();
	return state.Gamepad.sThumbRY;
}

// Depreciated - use update() and XinputController.state instead (to avoid multiple Xinput calls)
int XinputController::getRT() {
	updateState();
	return state.Gamepad.bRightTrigger;
}

// Depreciated - use update() and XinputController.state instead (to avoid multiple Xinput calls)
int XinputController::getLT() {
	updateState();
	return state.Gamepad.bLeftTrigger;
}

// Depreciated - use update() and XinputController.normState instead (to avoid multiple Xinput calls)
double XinputController::getNormLX() {
	return max(-1, (double)getLX() / 32767); // Returns from -1 to 1
}

// Depreciated - use update() and XinputController.normState instead (to avoid multiple Xinput calls)
double XinputController::getNormLY() {
	return max(-1, (double)getLY() / 32767); // Returns from -1 to 1
}

// Depreciated - use update() and XinputController.normState instead (to avoid multiple Xinput calls)
double XinputController::getNormRX() {
	return max(-1, (double)getRX() / 32767); // Returns from -1 to 1
}

// Depreciated - use update() and XinputController.normState instead (to avoid multiple Xinput calls)
double XinputController::getNormRY() {
	return max(-1, (double)getRY() / 32767); // Returns from -1 to 1
}

// Depreciated - use update() and XinputController.normState instead (to avoid multiple Xinput calls)
double XinputController::getNormRT() {
	//return max(-1, (double)((getRT() - 128) / 127)); // Returns from -1 to 1
	return (double)getRT() / 255; // Returns from 0 to 1
}

// Depreciated - use update() and XinputController.normState instead (to avoid multiple Xinput calls)
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
