#include "PickUp.h"

PickUp::PickUp() {
	_darknessDegree = _maxdarknessDegree / 2;
	_windowSize = Vector2(g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}

void PickUp::SetDarknessDegree(int darknessDegree) {
	_darknessDegree = darknessDegree;

	if (_darknessDegree < 0) _darknessDegree = 0;
	else if (_darknessDegree > _maxdarknessDegree) _darknessDegree = _maxdarknessDegree;
}

void PickUp::Render() {
	CGraphicsUtilities::RenderFillRect(0, 0, _windowSize.x, _pickUpRect.Top, MOF_ARGB(_darknessDegree, 0, 0, 0));
	CGraphicsUtilities::RenderFillRect(0, _pickUpRect.Top, _pickUpRect.Left, _pickUpRect.Bottom, MOF_ARGB(_darknessDegree, 0, 0, 0));
	CGraphicsUtilities::RenderFillRect(0, _pickUpRect.Bottom, _windowSize.x, _windowSize.y, MOF_ARGB(_darknessDegree, 0, 0, 0));
	CGraphicsUtilities::RenderFillRect(_pickUpRect.Right, _pickUpRect.Top, _windowSize.x, _pickUpRect.Bottom, MOF_ARGB(_darknessDegree, 0, 0, 0));
}