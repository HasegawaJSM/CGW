#include "EnemyContainer.h"

void EnemyContainer::Initialize() {
	_sordEnemyTexture.Load("SordEnemy.png");
	_arrowEnemyTexture.Load("ArrowEnemy.png");
	_axeEnemyTexture.Load("AxeEnemy.png");
	_daggerEnemyTexture.Load("DaggerEnemy.png");
	_tankEnemyTexture.Load("TankEnemy.png");

	CreateEnemy("sord", new Enemy(&_sordEnemyTexture,ATTACK_TYPE::FrontCorrespondence, &_swordEnemyAction));
	CreateEnemy("arrow", new Enemy(&_arrowEnemyTexture, ATTACK_TYPE::AllCorrespondence, &_arrowEnemyAction));
	CreateEnemy("axe", new Enemy(&_axeEnemyTexture, ATTACK_TYPE::FrontCorrespondence, &_axeEnemyAction));
	CreateEnemy("dagger", new Enemy(&_daggerEnemyTexture, ATTACK_TYPE::FrontCorrespondence, &_daggerEnemyAction));
	CreateEnemy("tank", new Enemy(&_tankEnemyTexture, ATTACK_TYPE::FrontCorrespondence, &_swordEnemyAction));
}

void EnemyContainer::CreateEnemy(std::string enemyName, Enemy* enemy) {
	_locateEnemy[enemyName] = enemy;
}

Enemy* EnemyContainer::GetEnemy(std::string enemyName) {
	return _locateEnemy[enemyName]->GetClone();
}

void EnemyContainer::Release() {
	_sordEnemyTexture.Release();
	_arrowEnemyTexture.Release();
	_axeEnemyTexture.Release();
	_daggerEnemyTexture.Release();
	_tankEnemyTexture.Release();

	for (auto itr = _locateEnemy.begin();itr != _locateEnemy.end();itr++) delete itr->second;
}