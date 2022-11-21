#pragma once
#include	"Mof.h"
#include	"map"
#include	"IBaseObject.h"
#include	"Player.h"
#include	"Enemy.h"

enum class ADJOIN_PLACE {
	LEFT,
	FRONT,
	RIGHT,
	BACK,
};

class Block
{
	CTexture* _blockTexture;
	Vector2 _pos;
	float _sizeX, _sizeY;
	const float _scale = 0.4f;
	bool _shineUp, _attackable;
	int _attackableShineAlpha, _shinePower;
	const int _maxAlpha = 255;

	std::map<ADJOIN_PLACE, Block*> _adjoinBlockArray;
	Enemy* _enemy = nullptr;
	IBaseObject* _object = nullptr;
	Player* _player = nullptr;

	CRectangle _hitBox;
	float _hitBoxSupSpaceX, _hitBoxSupSpaceY;

public:
	void Initialize();
	void SetTexture(CTexture* tx) { _blockTexture = tx; }
	void SetStatu(int x, int y);
 	
	void SetEnemy(Enemy* enemy);
	void SetObject(IBaseObject* object);
	Enemy* GetEnemy() { return _enemy; }
	void SetAdjoinBlock(Block* block, ADJOIN_PLACE adjoinPlace) { _adjoinBlockArray[adjoinPlace] = block; }
	Block* GetAdjoinBlock(ADJOIN_PLACE adjoinPlace) { return _adjoinBlockArray[adjoinPlace]; }

	void Update();
	void Advance();

	void Render();
	void Release();
	void Delete();
	void DeleteEnemy();
	void DeleteObject();

	bool IsHeldEnemy() { return  _enemy != nullptr; }
	bool IsHeldObject() { return _object != nullptr; }
	bool IsHeldPlayer() { return _player != nullptr; }

	bool CheckOnMouse(Vector2 mousePos) { return ((_hitBox.Left < mousePos.x && _hitBox.Right > mousePos.x) && (_hitBox.Top < mousePos.y && _hitBox.Bottom > mousePos.y)); }
	void EnemyAttck();
	bool CheckEnemyCanAttck() {return !(_enemy->GetAttackType() == ATTACK_TYPE::FrontCorrespondence && GetAdjoinBlock(ADJOIN_PLACE::FRONT) != nullptr);}

	IBaseObject* GetBlockOnObject() { return _object; }
	void ActionObject();

	void ShineUp() { _shineUp = true; }
	void SetAttackableFlg(bool flg);
	void InitialAlpha();
	void AddAttackableAlpha();

	void SetPlayer(Player* player);
	Player* GetPlayer() { return _player; }
	CRectangle GetRect() { return CRectangle(_pos.x, _pos.y - _sizeY, _pos.x + _sizeX, _pos.y + _sizeY); }
};