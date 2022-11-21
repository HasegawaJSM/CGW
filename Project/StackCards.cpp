#include "StackCards.h"

StackCards::StackCards() {}

void StackCards::Initialize() {
	_maxSeedTime = 100;

	_cancelButton.Load("CancelButton.jpg");
	_scale = 0.7f;
	_cancelButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _cancelButton.GetWidth()* _scale / 2, g_pGraphics->GetTargetHeight() - _cancelButton.GetHeight() * _scale - 50);
	_cancelButtonHitBox =CRectangle(_cancelButtonPos.x, _cancelButtonPos.y, _cancelButtonPos.x+ _cancelButton.GetWidth() * _scale, _cancelButtonPos.y+ _cancelButton.GetHeight() * _scale);
}

void StackCards::ReSet() {

	_stackCards.clear();
}

void StackCards::Update() {

	_seedCount++;
	if (_seedCount >= _maxSeedTime) _seedCount = 0;
}

void StackCards::SetCard(Card* card) {

	_stackCards.emplace_back(card);
	card->Initialize();
}

bool StackCards::EndTurn() {
	return _handInCard->IsMaxHeldCard() || _stackCards.size() <= 0;
}

void StackCards::AddHandInCard() {
	if (_handInCard->IsMaxHeldCard() || _stackCards.size() <= 0) return;

	_random.SetSeed(_seedCount);
	int cardNumber = _random.Random(_stackCards.size());

	_handInCard->SetCard(_stackCards[cardNumber]);
	_stackCards.erase(_stackCards.begin() + cardNumber);
}

void StackCards::LookSackCards() {
	if (_stackCards.size() <= 0)return;
	for (int i = 0;i < _stackCards.size();i++) SortLookCard(i);
}

void StackCards::SortLookCard(int number) {
	for (auto itr = _lookStackCard.begin();itr != _lookStackCard.end();itr++) {
		if (_stackCards[number]->GetCardName() != itr->first->GetCardName()) continue;
		else {
			itr->second++;
			return;
		}
	}
	_lookStackCard[_stackCards[number]] = 1;
}

bool StackCards::DoneLook(Vector2 mousePos) {
	if (!_cancelButtonHitBox.CollisionPoint(mousePos)) return false;

	_lookStackCard.clear();
	return true;
}

void StackCards::Render() {
	if (_stackCards.size() <= 0)return;
	
	float cardSizeX = _stackCards[0]->GetTexture()->GetWidth() + 20;
	int count = 0;
	for (auto itr = _lookStackCard.begin();itr!=  _lookStackCard.end();itr++) {
		itr->first->GetTexture()->Render(g_pGraphics->GetTargetWidth() / 2 + ((float)count - ((float)_lookStackCard.size() / 2)) * cardSizeX, g_pGraphics->GetTargetHeight() / 2);
		CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth() / 2 + ((float)count - ((float)_lookStackCard.size() / 2)) * cardSizeX, g_pGraphics->GetTargetHeight() / 2 - 20,MOF_COLOR_HBLACK, "~ %d", itr->second);
		count++;
	}

	_cancelButton.RenderScale(_cancelButtonPos.x,_cancelButtonPos.y, _scale);
}

void StackCards::Release() {
	_lookStackCard.clear();
	_stackCards.clear();
	_cancelButton.Release();
}