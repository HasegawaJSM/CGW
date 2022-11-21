#include "Enemy.h"

Enemy::Enemy(CTexture* enemyTexture, ATTACK_TYPE attackType, IBaseEnemyAction* action){
	_enemyTexture = enemyTexture; 
	_attackType = attackType;
	_action = action;
}

void Enemy::Initialize() {

	_attackMovePos = 20;
	_attackCount = _attckTime = 30;
	_attacked = _underAttack = false;
	_hp = 1;
}

void Enemy::Load() {
}

void Enemy::SetPos(Vector2 pos) {
	_pos.x = pos.x - _enemyTexture->GetWidth() * _scale / 2;
	_pos.y = pos.y - _enemyTexture->GetHeight() * _scale;
}

void Enemy::Update() {
	if (_underAttack) AttackMove();
}

void Enemy::AttackMove() {
	if (_attackCount <= 0) return;
	_attackCount--;

	if (_attackCount > 0) return;
	_attacked = true;
	_underAttack = false;
}

void Enemy::Attack() {

	if (_underAttack) return;

	_action->Action(_player);
	_attackCount = _attckTime;
	_underAttack = true;
}

void Enemy::ResetAttck() {
	_attacked = false;
}

void Enemy::Render() {
	_underAttack ? _enemyTexture->RenderScale(_pos.x - _attackMovePos, _pos.y, _scale) : _enemyTexture->RenderScale(_pos.x, _pos.y, _scale);
}

void Enemy::Release() {
}