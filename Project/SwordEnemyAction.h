#pragma once
#include	"IBaseEnemyAction.h"
#include	"Player.h"
class SwordEnemyAction:public IBaseEnemyAction
{

public:
	void Action(Player* player) {
		player->OnDamege(1);
	}
};