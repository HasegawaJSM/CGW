#pragma once
#include	"vector"
#include	"Mof.h"
#include	"Card.h"
#include	"StackCards.h"
#include	"HandInCard.h"
#include	"CardContainer.h"
#include	"CardSelect.h"
#include	"CardDataLoad.h"

class CardManager
{
	StackCards _stackCards;
	HandInCard _handInCard;
	CardContainer _cardContainer;
	CardSelect _cardSelect;
	CardDataLoad _cardDataLoad;

	int _choiceCardValue;
	ChoicesCard* _choicesCardArray;

	bool _onSelectCard;
	bool _lookStackCard;

	CTexture _bagTexture;
	Vector2 _bagPos;
	CRectangle _bagHitBox;
	float _bagScale;

	Vector2 _cardTextPos;
	bool _renderCardText;
	std::string _cardText="okok";

public:
	void Initialize();
	void ReSet();
	void SetChoiceCardArray();
	void GetInitialCard();
	void Update();
	void SelectCard();
	void PickSelectCard(Vector2 mousePos);
	void LookStackCards(Vector2 mousePos);
	void SetRenderText(std::string);

	void Render();
	void Release();

	StackCards* GetStackCards() { return &_stackCards; }
	HandInCard* GetHandInCard() { return &_handInCard; }

	bool IsSelectCard() { return _onSelectCard || _lookStackCard; }
};