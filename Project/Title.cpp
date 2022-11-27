#include "Title.h"

void Title::Initialize() {

}

void Title::Update() {
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) SceneManager::Instance().ChangeScene(SceneType::Map);
}

void Title::Render() {

	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth() / 2 - 60, g_pGraphics->GetTargetHeight() / 2,MOF_COLOR_HBLACK, "”L‚ÆƒJ[ƒh");
	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth() / 2 - 80, g_pGraphics->GetTargetHeight() / 2+100,MOF_COLOR_HBLACK, "Push to Start");
}

void Title::Release() {

}