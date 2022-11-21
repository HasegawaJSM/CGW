#include "Card.h"

Card::Card(IBaseAction* action,CTexture* tx,std::string name) {
	_action = action;
	_cardTexture = tx;
	_cardName = name;
}

void Card::Initialize() {
	_sizeX = _cardTexture->GetWidth();
	_sizeY = _cardTexture->GetHeight();

	_upScale = 1.2f;
	_scaleUp = false;

	_spaceX = 10;
	_spaceY = 40;
}

void Card::Update() {
	_hitBox = CRectangle(_pos.x, _pos.y, _pos.x + _sizeX, _pos.y + _sizeY);
}

void Card::Orderliness(int value, int number) {
	_pos.x = g_pGraphics->GetTargetWidth() / 2 + ((float)number - (float)value / 2) * (_sizeX + _spaceX);
	_pos.y = g_pGraphics->GetTargetHeight() - _sizeY - _spaceY;
}

bool Card::CheckOnMouse(Vector2 mousePos) {
	return ((mousePos.x > _hitBox.Left && mousePos.x < _hitBox.Right) && (mousePos.y > _hitBox.Top && mousePos.y < _hitBox.Bottom));
}

void Card::SetOnMouseFlg(bool flg) {
	_scaleUp = flg;
}

void Card::Action(Block* block) {
	if (block == nullptr || (!block->IsHeldEnemy() && block->GetPlayer() == nullptr)) return;
	_action->Action(block);
}

void Card::ShineUpBlock(Block* block) {
	_action->ShineUpBlock(block);
}

void Card::Render() {
	if (_scaleUp)_cardTexture->RenderScale(_pos.x - (_sizeX * _upScale - _sizeX) / 2, _pos.y - (_sizeY * _upScale - _sizeY) / 2, _upScale);
	else _cardTexture->Render(_pos.x, _pos.y);
}

void Card::Release() {

}