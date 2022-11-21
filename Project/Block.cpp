#include "Block.h"
#include "Stairs.h"

void Block::Initialize() {
	if (_enemy != nullptr) _enemy->Initialize();
	for (int i = 0;i < _adjoinBlockArray.size();i++) {
		_adjoinBlockArray[(ADJOIN_PLACE)i] = nullptr;
	}

	_shinePower = 5;
	_attackable = _shineUp = false;
}

void Block::SetStatu(int x, int y) {

	_sizeX = _blockTexture->GetWidth() * _scale;
	_sizeY = _blockTexture->GetHeight() * _scale;

	_pos.x = g_pGraphics->GetTargetWidth() / 2 + (_sizeX / 2 * x) - (_sizeX / 2 * y);
	_pos.y = 200 + (_sizeY / 2 * y) + (_sizeY / 2 * x);

	_hitBoxSupSpaceX = _sizeX / 5;
	_hitBoxSupSpaceY = _sizeY / 5;
	_hitBox = CRectangle(_pos.x + _hitBoxSupSpaceX, _pos.y + _hitBoxSupSpaceY, _pos.x + _sizeX - _hitBoxSupSpaceX, _pos.y + _sizeY - _hitBoxSupSpaceY);

	if (_player != nullptr)_player->SetPosition(Vector2(_pos.x + _sizeX / 2, _pos.y + _sizeY));
}

void Block::SetEnemy(Enemy* enemy) {
	_enemy = enemy;
	_enemy->SetScale(_scale);
	_enemy->SetPos(Vector2(_pos.x + _sizeX / 2, _pos.y + _sizeY));
	_enemy->Initialize();
}

void Block::SetObject(IBaseObject* object) {
	_object = object;
	_object->SetScale(_scale);
	_object->SetPos(Vector2(_pos.x + _sizeX / 2, _pos.y + _sizeY));
	_object->Initialize();
}

void Block::SetPlayer(Player* player) {
	_player = player;
	_player->SetScale(_scale);
}


void Block::Update() {
	if (_enemy != nullptr) _enemy->Update();

	if (_attackable) AddAttackableAlpha();
	_shineUp = false;
}

void Block::Advance() {
	Block* frontBlock = GetAdjoinBlock(ADJOIN_PLACE::FRONT);
	if (frontBlock == nullptr || frontBlock->IsHeldEnemy() || frontBlock->IsHeldObject())return;

	if (_enemy != nullptr) {
		frontBlock->SetEnemy(_enemy);
		_enemy = nullptr;
	}

	if (_object != nullptr) {
		frontBlock->SetObject(_object);
		_object = nullptr;
	}
}

void Block::EnemyAttck() {
	if(CheckEnemyCanAttck()) _enemy->Attack();
}

void Block::ActionObject() {
	if (_object == nullptr) return;

	bool onDelete = dynamic_cast<Stairs*>(_object) == nullptr;
	_object->Action();
	if (onDelete) DeleteObject();
}

void Block::SetAttackableFlg(bool flg) {
	_attackable = flg;
}

void Block::AddAttackableAlpha() {
	_attackableShineAlpha += _shinePower;
	if (_attackableShineAlpha >= _maxAlpha) _attackableShineAlpha = 0;
}

void Block::InitialAlpha() {
	_attackableShineAlpha = 0;
}


void Block::Render() {
	if (_blockTexture == nullptr)return;

	_blockTexture->RenderScale(_pos.x, _pos.y, _scale);
	if (_shineUp) _blockTexture->RenderScale(_pos.x, _pos.y, _scale, MOF_COLOR_HRED);
	else if (_attackable)_blockTexture->RenderScale(_pos.x, _pos.y, _scale, MOF_ARGB(_attackableShineAlpha, 200, 200, 255));

	if (_enemy != nullptr) _enemy->Render();
	if (_object != nullptr) _object->Render();
}

void Block::Delete() {

	DeleteEnemy();
	DeleteObject();
}

void Block::DeleteEnemy() {
	if (_enemy != nullptr) {
		delete _enemy;
		_enemy = nullptr;
	}
}

void Block::DeleteObject() {
	if (_object != nullptr) {
		delete _object;
		_object = nullptr;
	}
}

void Block::Release() {
	Delete();
}