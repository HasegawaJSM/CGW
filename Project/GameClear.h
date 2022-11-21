#pragma once
#include	"IBaseScene.h"
#include	"Mof.h"
class GameClear :public IBaseScene
{
	int _clearCount, _maxClearTime;
public:
	void ReSet() {}
	void Initialize();
	void Update();
	void Render();
	void Release();
};

