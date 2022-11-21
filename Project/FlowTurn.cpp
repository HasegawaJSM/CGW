#include "FlowTurn.h"

void FlowTurn::Initialize(){
	_turnArray = new IBaseTurn * [_turnValue];

	_turnArray[0] = &_drawCard;
	_turnArray[1] = &_useCard;
	_turnArray[2] = &_attackEnemy;
	_turnArray[3] = &_marchEnemy;
}

void FlowTurn::ReSet() {
	_nowTurnNumber = 0;
}

void FlowTurn::SetStatu(CardManager* cardManager, Input* input, Field* field){
	_drawCard.SetStackCards(cardManager->GetStackCards());
	_useCard.SetHandInCard(cardManager->GetHandInCard());
	_useCard.SetCardManager(cardManager);
	_useCard.SetField(field);
	_attackEnemy.SetField(field);
	_marchEnemy.SetField(field);

}

void FlowTurn::Update(){
	if (_turnArray[_nowTurnNumber]->EndTurn()) {
		ChangeTurn();
	}
	_turnArray[_nowTurnNumber]->Update();
}

void FlowTurn::ChangeTurn(){
	_nowTurnNumber++;

	if (_nowTurnNumber >= _turnValue) {
		_nowTurnNumber = 0;
	}
}

void FlowTurn::Release() {
	delete[] _turnArray;
}