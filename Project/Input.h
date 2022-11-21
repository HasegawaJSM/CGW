#pragma once
#include	"Field.h"
#include	"CardManager.h"
#include	"UseCard.h"
#include	"Tutorial.h"

class Input
{
	Field* _field;
	Vector2 _mousePos;

	Block* _pickBlock = nullptr;
	CardManager* _cardManager;
	UseCard* _useCard;

	Tutorial* _tutorial;

public:
	void SetField(Field* field) { _field = field; }
	void SetCardManager(CardManager* cardManager) { _cardManager = cardManager; }
	void SetUseCard(UseCard* useCard) { _useCard = useCard; }
	void SetTutorial(Tutorial* tutorial) { _tutorial = tutorial; }

	void Update();

private:
	void InputKey();
	void InputMouse();
};

