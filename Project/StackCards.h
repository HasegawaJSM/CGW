#pragma once
#include	"vector"
#include	"map"
#include	"Card.h"
#include	"CardContainer.h"
#include	"HandInCard.h"

class StackCards
{
	CardContainer* _cardContainer;
	HandInCard* _handInCard;

	std::vector<Card*> _stackCards;

	CRandom _random;
	int _seedCount,_maxSeedTime;

	std::map<Card*, int > _lookStackCard;

	CTexture _cancelButton;
	Vector2 _cancelButtonPos;
	CRectangle _cancelButtonHitBox;
	float _scale;

public:
	StackCards();
	void ReSet();
	void Initialize();
	void SetCardContainer(CardContainer* cardContainer) { _cardContainer = cardContainer; }
	void SetHandInCard(HandInCard* handInCard) { _handInCard = handInCard; }

	void Update();
	void SetCard(Card* card);
	bool EndTurn();
	void AddHandInCard();

	void LookSackCards();
	void SortLookCard(int number);
	bool DoneLook(Vector2 mousePos);

	void Render();
	void Release();
};

