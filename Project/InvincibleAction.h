#pragma once
#include	"IBaseAction.h"
#include	"Player.h"
class InvincibleAction :public IBaseAction
{
	ACTION_TYPE _cardType = ACTION_TYPE::PlayerCorrespondence;
public:
	void Action(Block* block) { block->GetPlayer()->OnInvincible(); }
	void ShineUpBlock(Block* block) {
		ShineUp(block);
	}
	ACTION_TYPE GetType() { return _cardType; }
};