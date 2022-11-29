#pragma once
#include	"IBaseAction.h"
#include	"Enemy.h"
class SordAction :public IBaseAction
{
	ACTION_TYPE _cardType = ACTION_TYPE::FrontCorrespondence;
public:
	void Action(Block* block) {	
		if (block->GetEnemy() != nullptr) {
			block->GetEnemy()->OnDamage(1);
			CheckDeadEnemy(block);
		}
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