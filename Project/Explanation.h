#pragma once
#include	"Mof.h"
#include	"PickUp.h"
class Explanation
{
	PickUp _pickUp;
	CTexture* _texture;
	Vector2 _texturePos;
public:
	void Initialize();
	void SetPickUpRectangle(CRectangle rect) { _pickUp.SetPickUpRect(rect); }
	void SetDarknessDegree(int deg) { _pickUp.SetDarknessDegree(deg); }
	void SetTexture(CTexture* tx) { _texture = tx; }
	void SetTexturePos(Vector2 pos) { _texturePos = pos; }
	
	void Render();
	void Release();
};