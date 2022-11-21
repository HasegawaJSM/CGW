#pragma once
#include	"Mof.h"
#include	"Block.h"
#include	"IBaseAction.h"
#include	"string"


class Card
{
	CTexture* _cardTexture;
	Vector2 _pos;
	float _sizeX, _sizeY;
	CRectangle _hitBox;
	float _upScale;
	bool _scaleUp;
	float _spaceX, _spaceY;

	IBaseAction* _action = nullptr;

	std::string _cardName;

public:
	Card(IBaseAction* action, CTexture* tx,std::string name);

	Card* GetClone() { return new Card(_action, _cardTexture, _cardName); }

	void Initialize();
	void SetTexture(CTexture* tx) { _cardTexture = tx; }

	void Update();
	void Orderliness(int value, int number);

	bool CheckOnMouse(Vector2 mousePos);
	void SetOnMouseFlg(bool flg);

	void Render();
	void Release();

	void Action(Block* block);
	void ShineUpBlock(Block* block);

	ACTION_TYPE GetActionType() { return _action->GetType(); }
	std::string GetCardName() { return _cardName; }
	CTexture* GetTexture() { return _cardTexture; }

	Vector2 GetPos() { return _pos; }
	Vector2 GetSize() { return Vector2(_sizeX, _sizeY); }
};

