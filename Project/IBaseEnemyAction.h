#pragma once
#include	"Player.h"
class IBaseEnemyAction
{

public:
	virtual void Action(Player* player) = 0;
};