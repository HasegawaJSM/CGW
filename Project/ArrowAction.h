#pragma once
#include	"IBaseAction.h"
#include	"Enemy.h"
class ArrowAction :public IBaseAction
{
	ACTION_TYPE _cardType = ACTION_TYPE::AllCorrespondence;
public:
	void Action(Block* block) {
		block->GetEnemy()->OnDamage(1);
		CheckDeadEnemy(block);
	}
	void ShineUpBlock(Block* block) {
		ShineUp(block);
	}

	ACTION_TYPE GetType() { return _cardType; }

private:
	void CheckDeadEnemy(Block* _enemyUnderBlock) {
		if (_enemyUnderBlock->GetEnemy()->IsDead()) _enemyUnderBlock->DeleteEnemy();
	}
};