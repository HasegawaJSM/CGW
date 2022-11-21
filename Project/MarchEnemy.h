#pragma once
#include	"IBaseTurn.h"
#include	"Field.h"
class MarchEnemy :public IBaseTurn
{
	Field* _field;
public:
	void SetField(Field* field) { _field = field; }
	void Update();
	bool EndTurn();
};