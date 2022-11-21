#include "SordEnemy.h"

void SordEnemy::Initialize() {
	_attackType = ATTACK_TYPE::FrontCorrespondence;

	_attackMovePos = 20;
	_attackCount = _attckTime = 20;
	_attacked= _underAttack=false;
}

void SordEnemy::Load() {
}

void SordEnemy::SetPos(Vector2 pos) {
	_pos.x = pos.x - _enemyTexture->GetWidth() * _scale / 2;
	_pos.y = pos.y - _enemyTexture->GetHeight() * _scale;
}

void SordEnemy::Update() {
	if(_underAttack) AttackMove();
}

void SordEnemy::AttackMove() {
	if (_attackCount <= 0) return;
	_attackCount--;

	if (_attackCount > 0) return;
	_attacked = true;
	_underAttack = false;
}

void SordEnemy::Attack() {

	if (_underAttack) return;

	_player->OnDamege(1);
	_attackCount = _attckTime;
	_underAttack = true;
}

void SordEnemy::ResetAttck() {
	_attacked = false;
}

void SordEnemy::Render() {
	_underAttack ? _enemyTexture->RenderScale(_pos.x - _attackMovePos, _pos.y, _scale) : _enemyTexture->RenderScale(_pos.x, _pos.y, _scale);
}

void SordEnemy::Release() {
}