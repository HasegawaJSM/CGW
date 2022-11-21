#pragma once
#include	"Mof.h"
class IBaseObject
{

public:
	virtual void Initialize() = 0;
	virtual void SetScale(float scale) = 0;
	virtual void SetPos(Vector2 pos) = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	virtual void Action() = 0;
};