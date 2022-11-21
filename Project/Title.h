#pragma once
#include	"IBaseScene.h"
#include	"SceneManager.h"
#include	"Mof.h"
class Title:public IBaseScene
{

public:
	void ReSet() {}
	void Initialize();
	void Update();
	void Render();
	void Release();
};