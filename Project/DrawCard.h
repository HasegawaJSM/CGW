#pragma once
#include	"IBaseTurn.h"
#include	"StackCards.h"
class DrawCard : public IBaseTurn
{
	StackCards* _stackCards;
public:
	void SetStackCards(StackCards* stackCards) { _stackCards = stackCards; }
	void Update();
	bool EndTurn();
};