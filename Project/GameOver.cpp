#include "GameOver.h"

void GameOver::Initialize() {
	LoadTexture();
}

void GameOver::LoadTexture() {

}

void GameOver::Render() {

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_COLOR_HBLACK);
	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth() / 2 - 80, g_pGraphics->GetTargetHeight() / 2, MOF_COLOR_RED, "Game Over");
}

void GameOver::Release() {

}