#pragma once
#include	"Mof.h"
#include	"Player.h"
#include	"IBaseEnemyAction.h"

enum class ATTACK_TYPE {
	AllCorrespondence,
	FrontCorrespondence
};

class Enemy 
{
	CTexture* _enemyTexture = nullptr;
	Vector2 _pos;
	float _scale;

	Player* _player;
	ATTACK_TYPE _attackType;
	IBaseEnemyAction* _action;

	int _hp;

	float _attackMovePos;
	int _attackCount, _attckTime;
	bool _attacked, _underAttack;

public:
	Enemy(CTexture* enemyTexture, ATTACK_TYPE attackType, IBaseEnemyAction* action);
	void SetPlayer(Player* player) { _player = player; }
	void Initialize();
	void Load();
	void SetScale(float scale) { _scale = scale; }
	void SetPos(Vector2 pos);

	void Update();
	void Attack();
	void OnDamage(int damage) { _hp -= damage; }
	bool IsDead() { return _hp <= 0; }

	bool IsAttacked() { return  _attacked; }
	void ResetAttck();

	void Render();
	void Release();

	Enemy* GetClone() { return new Enemy(_enemyTexture,_attackType,_action); }
	ATTACK_TYPE GetAttackType() { return _attackType; }

private:
	void AttackMove();
};