#pragma once
#include	"IBaseAction.h"
#include	"Enemy.h"
class AxeAction:public IBaseAction
{
	ACTION_TYPE _cardType = ACTION_TYPE::FrontCorrespondence;
public:
	void Action(Block* block);
	void ShineUpBlock(Block* block);

	ACTION_TYPE GetType() { return _cardType; }

private:
	void SideBlockAttack(Block* block, ADJOIN_PLACE adjoinPlace);
	void SideBlockShineUp(Block* block, ADJOIN_PLACE adjoinPlace);
	void Attack(Block* block);
	void CheckDeadEnemy(Block* enemyUnderBlock);

	Block* GetSideBlock(Block* block, ADJOIN_PLACE adjoinPlace) {
		return block->GetAdjoinBlock(adjoinPlace);
	}
};