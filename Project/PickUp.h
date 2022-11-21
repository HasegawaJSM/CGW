#pragma once
#include	"Mof.h"
class PickUp{
	CRectangle _pickUpRect;
	const int _maxdarknessDegree = 255;
	int _darknessDegree = 200;
	Vector2 _windowSize;

public:
	PickUp();
	void SetPickUpRect(CRectangle rect) { _pickUpRect = rect; }
	void SetDarknessDegree(int);
	void Render();
};