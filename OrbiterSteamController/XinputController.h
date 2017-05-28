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

	double getNormLX();
	double getNormLY();
	double getNormRX();
	double getNormRY();
	double getNormRT();
	double getNormLT();

private:
	void setControllerNumber();
	void init();
	void updateState();
	int getLX();
	int getLY();
	int getRX();
	int getRY();
	int getRT();
	int getLT();
};

