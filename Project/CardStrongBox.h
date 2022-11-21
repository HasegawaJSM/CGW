#pragma once
#include	"Mof.h"
#include	"IBaseObject.h"
#include	"CardManager.h"

class CardStrongBox: public IBaseObject
{
	CardManager* _cardManager;

	CTexture* _strongBoxTexture;
	Vector2 _pos;
	float _scale;
public:
	CardStrongBox(CTexture* strongBoxTexture, CardManager* cardManager);
	void Initialize();
	void SetScale(float scale) { _scale = scale; }
	void SetPos(Vector2 pos);
	void SetCardManager(CardManager* cardManager) { _cardManager = cardManager; }
	void Render();
	void Release();

	void Action();
};