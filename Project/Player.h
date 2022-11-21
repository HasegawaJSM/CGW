#pragma once
#include	"Mof.h"
class Player
{
	CTexture _playerTexture;
	Vector2 _playerPos;
	float _scale;

	int _maxHp, _hp;
	int _maxInvincibleValue,_invincibleCount;
public:
	void Initialize();
	void SetScale(float scale) { _scale = scale; }
	void SetPosition(Vector2 pos);
	void OnDamege(int damage);
	void OnRecovery() { _hp = _maxHp; }
	void OnInvincible() { _invincibleCount = _maxInvincibleValue; }
	void MaxHpFluctuation(int value);
	bool IsDead() { return _hp <= 0; }


	void FlowTurn();
	
	void Render();
	void Release();
};