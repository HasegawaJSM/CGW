#pragma once
#include	"Mof.h"
#include	"Card.h"
class HandInCard
{
	CTexture _cardTexture;
	const int _maxCardValue = 10;
	int _maxHeldCardValue = 4;
	int _cardValue;
	Card** _cardArray;

	bool _onSelectCard = false;

public:
	void Initialize();
	void ReSet();

	void Update();
	void SetCard(Card* card);
	Card* GetMouseOnCard(Vector2 mousePos);
	void ScaleUpCard(int number);
	void ScaleDownCard(Card* card);
	void UseCard(Card* card);
	bool IsMaxHeldCard() { return _cardValue >= _maxHeldCardValue;}
	void SetSelectFlg(bool flg) { _onSelectCard = flg; }

	void Render();
	void Release();

	CRectangle GetRenderCardsRect();
	int GetHeldCardValue() { return _cardValue; }

private:
	void DeleteCard();
};