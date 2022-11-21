#pragma once
#include	"IBaseScene.h"
#include	"Mof.h"
class Map :public IBaseScene
{
	CTexture _mapChip;
	int _mapValue;
	int _nextStageNumber;
	Vector2* _mapChipPosArray = nullptr;
	CTexture** _mapChipTextureArray = nullptr;

	int _count,_time;
public:
	void ReSet() {}
	void Initialize();
	void SetMapValue(int mapValue);
	void SetNextStageNumber(int number) { _nextStageNumber = number; }
	void Update();
	void Render();
	void Release();

private:
	void SetMapChipStatu();
};