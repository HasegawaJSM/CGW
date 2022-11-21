#pragma once
#include	"Enemy.h"
#include	"map"
#include	"string"

#include	"IBaseEnemyAction.h"
#include	"SwordEnemyAction.h"
#include	"ArrowEnemyAction.h"
#include	"AxeEnemyAction.h"
#include	"DaggerEnemyAction.h"

class EnemyContainer
{
	std::map<std::string, Enemy*> _locateEnemy;
	CTexture _sordEnemyTexture;
	CTexture _arrowEnemyTexture;
	CTexture _axeEnemyTexture;
	CTexture _daggerEnemyTexture;
	CTexture _tankEnemyTexture;

	SwordEnemyAction _swordEnemyAction;
	ArrowEnemyAction _arrowEnemyAction;
	AxeEnemyAction _axeEnemyAction;
	DaggerEnemyAction _daggerEnemyAction;

public:
	void Initialize();
	void Release();

	void CreateEnemy(std::string enemyName,Enemy* enemy);
	Enemy* GetEnemy(std::string enemyName);
};