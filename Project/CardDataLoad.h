#pragma once
#include	"Mof.h"
#include	"CardSelect.h"
class CardDataLoad
{
	long _fileSize;
	int _cardValue;
	ChoicesCard* _choicesCardArray;
public:
	void Initialize();
	int GetCardValue() { return _cardValue; }
	ChoicesCard* GetChoicesCardArray() { return _choicesCardArray;}
	void Release();
};