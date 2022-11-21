#include "AxeAction.h"

void AxeAction::Action(Block* block) {
	block->GetEnemy()->OnDamage(1);
	CheckDeadEnemy(block);

	SideBlockAttack(block, ADJOIN_PLACE::LEFT);
	SideBlockAttack(block, ADJOIN_PLACE::RIGHT);
}

void AxeAction::ShineUpBlock(Block* block) {
	ShineUp(block);

	SideBlockShineUp(block, ADJOIN_PLACE::LEFT);
	SideBlockShineUp(block, ADJOIN_PLACE::RIGHT);
}

void AxeAction::SideBlockAttack(Block* block, ADJOIN_PLACE adjoinPlace) {
	Block* adjoinBlock = GetSideBlock(block, adjoinPlace);
	if (adjoinBlock == nullptr) return;

	Attack(adjoinBlock);
	SideBlockAttack(adjoinBlock, adjoinPlace);
}

void AxeAction::SideBlockShineUp(Block* block, ADJOIN_PLACE adjoinPlace) {
	Block* adjoinBlock = GetSideBlock(block, adjoinPlace);
	if (adjoinBlock == nullptr) return;

	ShineUp(adjoinBlock);
	SideBlockShineUp(adjoinBlock, adjoinPlace);
}

void AxeAction::Attack(Block* block) {
	if (!block->IsHeldEnemy()) return;

	block->GetEnemy()->OnDamage(1);
	CheckDeadEnemy(block);
}

void AxeAction::CheckDeadEnemy(Block* enemyUnderBlock) {
	if (enemyUnderBlock->GetEnemy()->IsDead()) enemyUnderBlock->DeleteEnemy();
}