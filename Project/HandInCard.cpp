#include "HandInCard.h"

void HandInCard::Initialize() {
	_cardArray = new Card * [_maxCardValue];
}

void HandInCard::ReSet() {
	DeleteCard();
	_cardValue = 0;
}

void HandInCard::Update() {
	for (int i = 0;i < _cardValue;i++) _cardArray[i]->Update();
}

void HandInCard::SetCard(Card* card) {

	_cardArray[_cardValue] = card;
	_cardValue++;

	for (int i = 0;i < _cardValue;i++) _cardArray[i]->Orderliness(_cardValue, i);
}

Card* HandInCard::GetMouseOnCard(Vector2 mousePos) {
	if (_onSelectCard) return nullptr;

	int number = -1;
	for (int i = _cardValue - 1;i >= 0;i--) {
		if (_cardArray[i]->CheckOnMouse(mousePos)) {
			number = i;
			break;
		}
	}

	return number == -1 ? nullptr : _cardArray[number];
}

void HandInCard::ScaleUpCard(int number) {
	for (int i = 0;i < _cardValue;i++) {
		if (i == number) _cardArray[i]->SetOnMouseFlg(true);
		else _cardArray[i]->SetOnMouseFlg(false);
	}
}

void HandInCard::ScaleDownCard(Card* card) {
		card->SetOnMouseFlg(false);
}

void HandInCard::UseCard(Card* card) {

	int pickNumber = -1;
	for (int i = 0;i < _cardValue;i++) if (card == _cardArray[i]) pickNumber = i;
	if (pickNumber == -1) return;

	for (int i = 0;i < _cardValue - 1;i++) {
		if (i >= pickNumber) _cardArray[i] = _cardArray[i + 1];
	}

	_cardArray[_cardValue]->Release();
	_cardArray[_cardValue] = nullptr;

	_cardValue--;

	for (int i = 0;i < _cardValue;i++) _cardArray[i]->Orderliness(_cardValue, i);
}


CRectangle HandInCard::GetRenderCardsRect() {
	float space = 20;
	return CRectangle(
		_cardArray[0]->GetPos().x - space,
		_cardArray[0]->GetPos().y - space,
		_cardArray[_cardValue - 1]->GetPos().x + _cardArray[_cardValue - 1]->GetSize().x + space,
		_cardArray[_cardValue - 1]->GetPos().y + _cardArray[_cardValue - 1]->GetSize().y + space);
}

void HandInCard::Render() {
	for (int i = 0;i < _cardValue;i++) _cardArray[i]->Render();
}

void HandInCard::DeleteCard() {
	for (int i = 0;i < _cardValue;i++) {
		_cardArray[i]->Release();
		delete _cardArray[i];
		_cardArray[i] = nullptr;
	}
}

void HandInCard::Release() {
	DeleteCard();
	delete[] _cardArray;
}