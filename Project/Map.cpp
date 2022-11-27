#include "Map.h"
#include "SceneManager.h"

void Map::Initialize() {
	_mapChip.Load("mapChip.png");

	_time = _count = 250;
}

void Map::SetMapValue(int mapValue) {
	_mapValue = mapValue;
	_mapChipPosArray = new Vector2[_mapValue];
	_mapChipTextureArray = new CTexture*[_mapValue];

	SetMapChipStatu();
}

void Map::SetMapChipStatu() {

	for (int i = 0;i < _mapValue;i++) {
		_mapChipPosArray[i].x = g_pGraphics->GetTargetWidth() / 2 + ((float)i - (float)_mapValue / 2) * _mapChip.GetWidth() + 20;
		_mapChipPosArray[i].y = g_pGraphics->GetTargetHeight() / 2;

		_mapChipTextureArray[i] = &_mapChip;
	}
}

void Map::Update() {
	_count--;
	if (_count <= 0) {
		_count = _time;
		SceneManager::Instance().ChangeScene(SceneType::InGame);
	}
}

void Map::Render() {

	for (int i = 0;i < _mapValue;i++) {
		if (i == _nextStageNumber )_mapChipTextureArray[i]->Render(_mapChipPosArray[i].x, _mapChipPosArray[i].y, MOF_COLOR_HRED);
		else _mapChipTextureArray[i]->Render(_mapChipPosArray[i].x, _mapChipPosArray[i].y);
	}
}

void Map::Release() {

	if (_mapChipPosArray != nullptr) delete[] _mapChipPosArray;
	if (_mapChipTextureArray != nullptr)delete[] _mapChipTextureArray;
	_mapChip.Release();
}