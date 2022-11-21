#include "CardStrongBox.h"

CardStrongBox::CardStrongBox(CTexture* strongBoxTexture, CardManager* cardManager) {
	_strongBoxTexture = strongBoxTexture;
	_cardManager = cardManager;
}

void CardStrongBox::Initialize() {

}

void CardStrongBox::SetPos(Vector2 pos) {
	_pos.x = pos.x - _strongBoxTexture->GetWidth() * _scale / 2;
	_pos.y = pos.y  - _strongBoxTexture->GetHeight()*_scale;
}

void CardStrongBox::Action() {
	_cardManager->SelectCard();
}

void CardStrongBox::Render() {
	_strongBoxTexture->RenderScale(_pos.x, _pos.y, _scale);
}

void CardStrongBox::Release() {
}