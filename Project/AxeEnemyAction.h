#pragma once
#include	"IBaseEnemyAction.h"
#include	"Player.h"
class AxeEnemyAction :public IBaseEnemyAction
{

public:
	void Action(Player* player) {
		player->OnDamege(4);
	}
};