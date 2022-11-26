#pragma once
#include	"mof.h"
class FadeIn
{
	float _darknessDegree, _decrementValue;
	const int _maxDarknessDegree = 255;
public:
	void SetFadeInTime(float time);
	void ReSet();
	void Update();
	void Render();

	bool IsEnd() { return _darknessDegree <= 0; }
};