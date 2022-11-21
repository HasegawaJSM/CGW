#include "CardManager.h"

void CardManager::Initialize(){

	_stackCards.SetCardContainer(&_cardContainer);
	_stackCards.SetHandInCard(&_handInCard);

	_cardDataLoad.Initialize();
	_cardContainer.Initialize();
	_handInCard.Initialize();
	_stackCards.Initialize();
	_cardSelect.Initialzie();

	GetInitialCard();
	SetChoiceCardArray();
	

	_onSelectCard = false;

	_bagTexture.Load("CardBag.jpg");
	_bagPos = Vector2(100,600);
	_bagScale = 0.7f;
	_bagHitBox = CRectangle(_bagPos.x, _bagPos.y, _bagPos.x + _bagTexture.GetWidth()* _bagScale, _bagPos.y + _bagTexture.GetHeight()* _bagScale);

	_cardTextPos = Vector2(_bagPos.x, _bagPos.y - 100);
	_renderCardText = false;
}

void CardManager::ReSet() {
	
	_handInCard.ReSet();
	_stackCards.ReSet();
	GetInitialCard();
	_onSelectCard = false;
}

void CardManager::SetChoiceCardArray() {

	_choiceCardValue = _cardDataLoad.GetCardValue();
	_choicesCardArray = _cardDataLoad.GetChoicesCardArray();

	for (int i = 0;i < _choiceCardValue;i++)
		_choicesCardArray[i].cardTexture = _cardContainer.GetCardTexture(_choicesCardArray[i].cardName);
	
	_cardSelect.SetChoicesCardValue(_choiceCardValue);
	_cardSelect.SetChoicesCardArray(_choicesCardArray);
}

//‰ŠúƒJ[ƒh
void CardManager::GetInitialCard() {

	for (int i = 0;i < 2;i++) _stackCards.SetCard(_cardContainer.GetCard("sword"));
	for (int i = 0;i < 2;i++) _stackCards.SetCard(_cardContainer.GetCard("arrow"));
	for (int i = 0;i < 1;i++) _stackCards.SetCard(_cardContainer.GetCard("axe"));
}

void CardManager::Update(){

	_handInCard.Update();
	_cardSelect.Update();
}

void CardManager::LookStackCards(Vector2 mousePos) {

	if (!_lookStackCard) {
		if (_bagHitBox.CollisionPoint(mousePos)) {
			_lookStackCard = true;
			_stackCards.LookSackCards();
		}
	}
	else {
		if (_stackCards.DoneLook(mousePos)) {
			_lookStackCard = false;
		}
	}
}

void CardManager::SelectCard() {

	_onSelectCard = true;
	_cardSelect.SetSelectCard();
	_handInCard.SetSelectFlg(true);
}

void CardManager::PickSelectCard(Vector2 mousePos) {
	if (!_onSelectCard) return;

	_cardSelect.PickCard(mousePos);

	if (_cardSelect.CheckPickedCard(mousePos)) {
		for (int i = 0;i < _cardSelect.GetSelectCardValue();i++) {
			for (int x = 0;x < _cardSelect.GetPickCardValue(i);x++) {
				_stackCards.SetCard(_cardContainer.GetCard(_cardSelect.GetPickCardName(i)));
			}
		}
		_onSelectCard = false;
		_stackCards.AddHandInCard();
		_handInCard.SetSelectFlg(false);
	}
}

void CardManager::SetRenderText(std::string cardName) {
	if (cardName == "") _cardText = "";
	_renderCardText = true;
	_cardText = _cardContainer.GetCardText(cardName);
}

void CardManager::Render(){
	if (_onSelectCard) _cardSelect.Render();
	else if (_lookStackCard) _stackCards.Render();
	else {
		_handInCard.Render();
		_bagTexture.RenderScale(_bagPos.x, _bagPos.y, _bagScale);

		if (_renderCardText) CGraphicsUtilities::RenderString(_cardTextPos.x, _cardTextPos.y, MOF_COLOR_HWHITE, "%s", _cardText.c_str());
	}
}

void CardManager::Release(){

	_stackCards.Release();
	_handInCard.Release();
	_cardContainer.Release();
	_cardSelect.Release();
	_cardDataLoad.Release();

	_bagTexture.Release();
}