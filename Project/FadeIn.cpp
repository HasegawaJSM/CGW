#include "FadeIn.h"

void FadeIn::SetFadeInTime(float time) {
	_decrementValue = _maxDarknessDegree / time;
}

void FadeIn::ReSet() {
	_darknessDegree = _maxDarknessDegree;
}

void FadeIn::Update() {
	if (IsEnd()) return;
	_darknessDegree -= _decrementValue;

	if (_darknessDegree <= 0) _darknessDegree = 0;
}

void FadeIn::Render() {
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB((int)_darknessDegree, 255, 255, 255));
}