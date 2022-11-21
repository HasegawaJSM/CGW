#pragma once
#include	"map"
#include	"Mof.h"
#include	"Card.h"
#include	"CardLocater.h"

#include	"SordAction.h"
#include	"ArrowAction.h"
#include	"AxeAction.h"
#include	"RecoveryAction.h"
#include	"InvincibleAction.h"
#include	"DaggerAction.h"


struct CardData {
	std::string cardName;
	CTexture cardTexture;
	std::string cardText;
	IBaseAction* action;
};

class CardContainer
{
	CardLocater _cardLocater;
	CRandom _random;

	SordAction _sordAction;
	ArrowAction _arrowAction;
	AxeAction _axeAction;
	RecoveryAction _recoveryAction;
	InvincibleAction _invincibleAction;
	DaggerAction _daggerAction;

	std::vector<CardData*> _cardDataArray;

public:
	void Initialize();
	Card* GetCard(std::string cardName);
	Card* GetRandomCard();
	CTexture* GetCardTexture(std::string cardName) { return _cardLocater._locateCard[cardName]->GetTexture(); }
	std::string GetCardText(std::string);
	void CreateBaseCard();

	void Release();

private:
	void AddCardData(std::string, std::string,std::string, IBaseAction*);
};