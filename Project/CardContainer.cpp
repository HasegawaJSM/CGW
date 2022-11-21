#include "CardContainer.h"

void CardContainer::Initialize() {

	AddCardData("sword", "SwordCard.jpg", "1—ñ–Ú‚Ì“G1‘Ì‚ðUŒ‚‚·‚éB", &_sordAction);
	AddCardData("arrow", "ArrowCard.jpg", "“G1‘Ì‚ðUŒ‚‚·‚éB", &_arrowAction);
	AddCardData("axe", "AxeCard.jpg", "1—ñ–Ú‚Ì“G‚ð‘S•”UŒ‚‚·‚éB", &_axeAction);
	AddCardData("dagger", "DaggerCard.jpg", "1—ñ–Ú‚Ì“G1‘Ì‚ðƒLƒ‹‚·‚éB", &_daggerAction);
	AddCardData("recovery", "RecoveryCard.jpg", "‘Ì—Í‚ª‰ñ•œ‚·‚éB", &_recoveryAction);
	AddCardData("invincible", "InvincibleCard.jpg", "2ƒ^[ƒ“‚ÌŠÔ“G‚©‚çƒ_ƒ[ƒW‚ðŽó‚¯‚È‚­‚È‚éB", &_invincibleAction);

	CreateBaseCard();
}

void CardContainer::AddCardData(std::string name, std::string textureName, std::string text, IBaseAction* ac) {
	_cardDataArray.push_back(new CardData);
	_cardDataArray[_cardDataArray.size() - 1]->cardName = name;
	_cardDataArray[_cardDataArray.size() - 1]->cardTexture.Load(textureName.c_str());
	_cardDataArray[_cardDataArray.size() - 1]->cardText = text;
	_cardDataArray[_cardDataArray.size() - 1]->action = ac;
}

void CardContainer::CreateBaseCard() {

	for (int i = 0;i < _cardDataArray.size();i++) {
		_cardLocater._locateCard[_cardDataArray[i]->cardName] = new Card(_cardDataArray[i]->action, &_cardDataArray[i]->cardTexture, _cardDataArray[i]->cardName);
	}
}

std::string CardContainer::GetCardText(std::string name) {

	for (int i = 0;i < _cardDataArray.size();i++) {
		if (_cardDataArray[i]->cardName == name) return _cardDataArray[i]->cardText;
	}
	return "";
}

Card* CardContainer::GetCard(std::string cardName) {
	return _cardLocater._locateCard[cardName]->GetClone();
}

Card* CardContainer::GetRandomCard() {

	_random.SetSeed(3);
	int cardNumber = _random.Random(_cardLocater._locateCard.size());
	int count = 0;

	for (auto itr = _cardLocater._locateCard.begin();itr != _cardLocater._locateCard.end();itr++) {
		if (count == cardNumber) {
			return itr->second;
		}
		count++;
	}

	return nullptr;
}

void CardContainer::Release() {
	
	for (int i = 0;i < _cardDataArray.size();i++) {
		_cardDataArray[i]->cardTexture.Release();
		delete _cardDataArray[i];
	}

	//_cardLocater.Release();
}