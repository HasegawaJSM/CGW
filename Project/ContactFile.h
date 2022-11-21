#pragma once
#include	"Mof.h"
#include	"Map.h"
#include	"Field.h"
#include	"string"
#include	"cstring"
#include	"EnemyContainer.h"
#include	"Enemy.h"

class ContactFile
{
	Field* _field;
	EnemyContainer _enemyContainer;
	Map* _map;

	std::string* _stageNameArray;
	int stageValue;
	int _crrentStageNumber = 0;
	long _fileSize;
	Enemy** _enemyTypeArray = nullptr;
	int enemyTypeValue;
public:
	void ReSet();
	void SetField(Field* field) { _field = field; }
	void SetMap(Map* map) { _map = map; }
	void Initialize();
	void SetStageManager();
	void SetNextStage();
	void SetStage();
	void Delete();
	void Release();
};