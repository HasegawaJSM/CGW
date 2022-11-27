#pragma once
#include	"Mof.h"
#include	"IEndGameProcess.h"

class GameOver :public IEndGameProcess
{
	CTexture _gameClearTexture;
public:
	void Initialize();

	void Render();
	void Release();

private:
	void LoadTexture();
};