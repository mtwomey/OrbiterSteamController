#pragma once
#include <Windows.h>
#include <xinput.h>

class XinputController
{
	int controllerNumber;
	XINPUT_STATE state;
public:
	XinputController();
	~XinputController();

	void init();
	void updateState();
	int getLX();
private:
	void setControllerNumber();
};

