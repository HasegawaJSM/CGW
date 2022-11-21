#pragma once
#include	"Mof.h"
#include	"IBaseObject.h"
class Stairs :public IBaseObject
{
	CTexture* _stairsTexture;
	Vector2 _stairsPosition;
	float _scale;
public:
	Stairs(CTexture* texture) { _stairsTexture = texture; }
	void Initialize();
	void SetScale(float scale) { _scale=scale; }
	void SetPos(Vector2 pos);
	void Render();
	void Release();

	void Action();
};