#include "Player.h"

void Player::Initialize(){
	_maxHp = _hp = 30;
	_maxInvincibleValue = 2;

	_playerTexture.Load("Player.png");
}

void Player::ReSet() {
	_hp = _maxHp;
}

void Player::SetPosition(Vector2 pos) {
	_playerPos.x = pos.x - _playerTexture.GetWidth() * _scale / 2;
	_playerPos.y = pos.y - _playerTexture.GetHeight() * _scale;
}

void Player::OnDamege(int damage){
	if (_invincibleCount > 0) return;

	_hp -= damage;
	if (_hp < 0)_hp = 0;
}

void Player::MaxHpFluctuation(int value) {
	if (_invincibleCount > 0) return;
	_hp += value;
}

void Player::FlowTurn() {
	if (_invincibleCount > 0) _invincibleCount--;
}

void Player::Render(){
	CGraphicsUtilities::RenderString(30, 30,MOF_COLOR_HBLACK, "‘Ì—Í@@ :%d", _hp);
	if(_invincibleCount>0) CGraphicsUtilities::RenderString(30, 60, MOF_COLOR_HBLACK, "–³“GŽžŠÔ :%d", _invincibleCount);

	_playerTexture.RenderScale(_playerPos.x, _playerPos.y, _scale);
}

void Player::Release(){
	_playerTexture.Release();
}