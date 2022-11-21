#include "DrawCard.h"

void DrawCard::Update() {

	_stackCards->AddHandInCard();
}

bool DrawCard::EndTurn() {
	return 	_stackCards->EndTurn();
}