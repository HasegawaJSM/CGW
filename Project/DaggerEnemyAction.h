#pragma once
#include	"IBaseEnemyAction.h"
#include	"Player.h"
	class DaggerEnemyAction :public IBaseEnemyAction
{

public:
	void Action(Player* player) {
		player->MaxHpFluctuation(-3);
	}
};