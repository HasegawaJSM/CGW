#include "GameClear.h"
#include "SceneManager.h"

void GameClear::Initialize() {
	_clearCount = _maxClearTime = 200;
}

void GameClear::Update() {
	_clearCount--;
	if (_clearCount > 0) return;

	_clearCount = _maxClearTime;
	SceneManager::Instance().ReSet();
	SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE);
}

void GameClear::Render() {

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_COLOR_HYELLOW);
	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth()/2 - 80, g_pGraphics->GetTargetHeight()/2, MOF_COLOR_HBLACK, "Game Clear");
}

void GameClear::Release() {

}