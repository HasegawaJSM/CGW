#pragma once
#include	"Mof.h"
#include	"CardManager.h"
#include	"Block.h"
#include	"Player.h"
#include	"Enemy.h"
#include	"CardStrongBox.h"
#include	"Stairs.h"

class Field
{
	CardManager* _cardManager;

	Block** _blockArray;
	int _blockValueX, _blockValueY;
	CTexture _blockTexture;
	bool _endMarch;

	Block _playerOnBlock;
	Player _player;

	CTexture _strongBoxTexture;
	CTexture _stairsTexture;

	CTexture _gameOverTexture;
	bool _gameOver = false;
	int _gameOverCount,_gameOverTime;

public:
	void Initialize();
	void SetCardManager(CardManager* cardManager) { _cardManager = cardManager; }
	void Load();

	void CreateField(int blockValueX,int blockValueY);
	void SetEnemy(char** enemyData,int enemyTextureValue, Enemy** enemyTypeArray);
	void SetStrongBox(char** strongBoxData, int strongBoxValue);
	void SetStairs(char** stairsData);

	void Update();
	void MarchEnemy();
	bool IsEndMarchEnemy();
	void AttackEnemy();
	bool IsEndAttackEnemy();

	void ActionFieldOnObject(Vector2 mousePos);
	void InitialAttackable();
	void TurnOffAttackable();
	void AllAttackable();
	void FrontAttackable();

	void Render();
	void Release();
	void DeleteBlockArray();

	Block* GetMouseOnBlock(Vector2 mousePos);
	Block* GetPlayerOnBlock() { return  &_playerOnBlock; }
	CRectangle GetTutorialStairsOnBlockRect() { return _blockArray[2][1].GetRect(); }
	CRectangle GetTutorialEnemyBlockRect() { return _blockArray[2][2].GetRect(); }

private:
	void SetAdjoinBlock();
};