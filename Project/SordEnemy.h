#pragma once
#include	"Mof.h"
#include	"IBaseEnemy.h"
#include	"Player.h"
class SordEnemy:public IBaseEnemy
{
	CTexture* _enemyTexture = nullptr;
	Vector2 _pos;
	float _scale;

	Player* _player;
	ATTACK_TYPE _attackType;

	int _hp;

	float _attackMovePos;
	int _attackCount, _attckTime;
	bool _attacked, _underAttack;

public:
	SordEnemy(CTexture* enemyTexture) { _enemyTexture = enemyTexture; }
	void SetPlayer(Player* player) { _player = player; }
	void Initialize();
	void Load();
	void SetScale(float scale) { _scale = scale; }
	void SetPos(Vector2 pos);

	void Update();
	void Attack();
	void OnDamage(int damage) { _hp -= damage; }
	bool IsDead() { return _hp <= 0; }

	bool IsAttacked() { return  _attacked;}
	void ResetAttck();

	void Render();
	void Release();

	IBaseEnemy* GetClone() { return new SordEnemy(_enemyTexture); }
	ATTACK_TYPE GetAttackType() { return _attackType; }

private:
	void AttackMove();
};