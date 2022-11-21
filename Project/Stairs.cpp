#include "Stairs.h"
#include "SceneManager.h"
#include "Game.h"

void Stairs::Initialize() {

}

void Stairs::SetPos(Vector2 pos) {
	_stairsPosition.x = pos.x - _stairsTexture->GetWidth() * _scale / 2;
	_stairsPosition.y = pos.y - _stairsTexture->GetHeight() * _scale;
}

void Stairs::Action() {
	dynamic_cast<Game*>(SceneManager::Instance().GetScene(SCENE_TYPE::INGAME))->NextStage();
}

void Stairs::Render() {
	_stairsTexture->RenderScale(_stairsPosition.x, _stairsPosition.y,_scale);
}

void Stairs::Release() {
}