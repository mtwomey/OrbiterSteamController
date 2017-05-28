#pragma once
#include <Windows.h>
#include <xinput.h>

struct NormState {
	double LX;
	double LY;
	double RX;
	double RY;
	double RT;
	double LT;
};

class XinputController
{
	int controllerNumber;

	void setControllerNumber();
	void init();
	void updateState();
	int getLX();
	int getLY();
	int getRX();
	int getRY();
	int getRT();
	int getLT();

public:
	XINPUT_STATE state;
	struct NormState normState;

	XinputController();
	~XinputController();
	void update();
	double getNormLX();
	double getNormLY();
	double getNormRX();
	double getNormRY();
	double getNormRT();
	double getNormLT();
};

