#pragma once
#include	"IBaseTurn.h"
#include	"DrawCard.h"
#include	"UseCard.h"
#include	"AttackEnemy.h"
#include	"MarchEnemy.h"

#include	"StackCards.h"
#include	"Input.h"
#include	"Field.h"

class FlowTurn
{
	const int _turnValue = 4;
	int _nowTurnNumber = 0;
	IBaseTurn** _turnArray;
	DrawCard _drawCard;
	UseCard _useCard;
	AttackEnemy _attackEnemy;
	MarchEnemy _marchEnemy;

public:
	void ReSet();
	void Initialize();
	void SetStatu(CardManager*, Input* , Field* );
	void Update();
	void ChangeTurn();
	void Release();

	UseCard* GetUseCard() { return &_useCard; }
};