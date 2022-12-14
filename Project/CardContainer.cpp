#include "CardContainer.h"

void CardContainer::Initialize() {

	AddCardData("sword", "SwordCard.jpg", "1列目の敵1体を攻撃する。", &_sordAction);
	AddCardData("arrow", "ArrowCard.jpg", "敵1体を攻撃する。", &_arrowAction);
	AddCardData("axe", "AxeCard.jpg", "1列目の敵を全部攻撃する。", &_axeAction);
	AddCardData("dagger", "DaggerCard.jpg", "1列目の敵1体をキルする。", &_daggerAction);
	AddCardData("recovery", "RecoveryCard.jpg", "体力が回復する。", &_recoveryAction);
	AddCardData("invincible", "InvincibleCard.jpg", "2ターンの間敵からダメージを受けなくなる。", &_invincibleAction);

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