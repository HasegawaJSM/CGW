#include "GameClear.h"

void GameClear::Initialize() {
	LoadTexture();
}

void GameClear::LoadTexture() {

}

void GameClear::Render() {

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_COLOR_HYELLOW);
	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth()/2 - 80, g_pGraphics->GetTargetHeight()/2, MOF_COLOR_HBLACK, "Game Clear");
}

void GameClear::Release() {

}