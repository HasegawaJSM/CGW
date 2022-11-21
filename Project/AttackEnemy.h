#pragma once
#include	"IBaseTurn.h"
#include	"Field.h"
class AttackEnemy :public IBaseTurn
{
	Field* _field;
public:
	void SetField(Field* field) { _field = field; }
	void Update() { _field->AttackEnemy(); }
	bool EndTurn() { return _field->IsEndAttackEnemy(); }
};

