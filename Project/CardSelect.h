#pragma once
#include	"Mof.h"
#include	"Card.h"
#include	"string"

struct ChoicesCard {
	std::string cardName;
	int cardValue;
	CTexture* cardTexture;
};

class CardSelect
{
	CTexture _backGround;
	CTexture _pickButton;
	CRectangle _butttonRectangle;
	float _buttonSizeX, _buttonSizeY;
	float _backGroundScale,_buttonScale;

	CRectangle* _choicesButtonArray;

	Vector2 _backGroundPosition;

	const int _choicesCardValue = 4;
	int _maxSelectCardValue = 2;
	int _currentSelectCardCount;

	int* _currentCardNumber;

	int  _choicesCardArrayValue;
	ChoicesCard* _choicesCardArray;
	ChoicesCard* _selectCardArray = new ChoicesCard[_choicesCardValue];

	CRandom _random;
	int _maxSeedTime,_seedCount;

public:
	void Initialzie();
	void SetChoicesCardValue(int choicesCardArrayValue) { _choicesCardArrayValue = choicesCardArrayValue; }
	void SetChoicesCardArray(ChoicesCard* choicesCardArray) { _choicesCardArray = choicesCardArray; }
	void SetSelectCard();
	void PickCard(Vector2 mousePos);
	bool CheckPickedCard(Vector2 mousePos);
	void Update();

	void Render();
	void Release();

	int GetSelectCardValue() { return _maxSelectCardValue; }
	std::string GetPickCardName(int number);
	int GetPickCardValue(int number) { return _selectCardArray[_currentCardNumber[number]].cardValue; }

private:
	void PickCardRender(int number);
};