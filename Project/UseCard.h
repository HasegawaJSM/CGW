#pragma once
#include	"IBaseTurn.h"
#include	"Card.h"
#include	"CardManager.h"
#include	"Field.h"
class UseCard :public IBaseTurn
{
	Card* _pickCard = nullptr;
	bool _useCard = false;
	Field* _field;
	Block* _pickBlock = nullptr;
	CardManager* _cardManager;
	HandInCard* _handInCard;
	Vector2 _mousePos;
	ACTION_TYPE _currentAttackable;

public:
	void SetCardManager(CardManager* cardManager) { _cardManager = cardManager; }
	void SetHandInCard(HandInCard* handInCard) { _handInCard = handInCard; }
	void SetField(Field* field) { _field = field; }

	void PushCard(Vector2 mousePos);
	void Update();
	bool EndTurn();

private:
	void PickCard();
	void ActionCard();
	bool IsAuditAction();
	void ShineUpBlock();
	void UpdateUI();
	void ShineAttackableBlock(Card*);
	void ChangeCurrentAttackable(ACTION_TYPE nextType);

	void GameOver();
};