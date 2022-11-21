#include "ArrowEnemy.h"

void ArrowEnemy::Initialize() {
	_attackType = ATTACK_TYPE::AllCorrespondence;

	_attackMovePos = 20;
	_attackCount = _attckTime = 20;
	_attacked = _underAttack = false;
}

void ArrowEnemy::Load() {
}

void ArrowEnemy::SetPos(Vector2 pos) {
	_pos.x = pos.x - _enemyTexture->GetWidth() * _scale / 2;
	_pos.y = pos.y - _enemyTexture->GetHeight() * _scale;
}

void ArrowEnemy::Update() {
	if (_underAttack) AttackMove();
}

void ArrowEnemy::AttackMove() {
	if (_attackCount <= 0) return;
	_attackCount--;

	if (_attackCount > 0) return;
	_attacked = true;
	_underAttack = false;
}

void ArrowEnemy::Attack() {
	if (_underAttack) return;

	_player->OnDamege(1);
	_attackCount = _attckTime;
	_underAttack = true;
}

void ArrowEnemy::ResetAttck() {
	_attacked = false;
}

void ArrowEnemy::Render() {
	_underAttack ? _enemyTexture->RenderScale(_pos.x - _attackMovePos, _pos.y,_scale ) : _enemyTexture->RenderScale(_pos.x, _pos.y,_scale);
}

void ArrowEnemy::Release() {
}