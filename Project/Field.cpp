#include "Field.h"
#include "SceneManager.h"

void Field::Initialize() {

	_endMarch  = false;

	_blockTexture.Load("Block.png");
	_strongBoxTexture.Load("StrongBox.png");
	_stairsTexture.Load("stairs.png");
	_gameOverTexture.Load("GameOver.png");

	_playerOnBlock.SetPlayer(&_player);
	_player.Initialize();

	_gameOverTime = _gameOverCount = 200;
}

void Field::CreateField(int blockValueX, int blockValueY) {

	DeleteBlockArray();

	_blockValueX = blockValueX;
	_blockValueY = blockValueY;

	_blockArray = new Block * [_blockValueX];
	for (int i = 0;i < _blockValueX;i++) _blockArray[i] = new Block[_blockValueY];


	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {

			_blockArray[x][y].SetTexture(&_blockTexture);
			_blockArray[x][y].SetStatu(x, y);
			_blockArray[x][y].Initialize();
		}
	}

	SetAdjoinBlock();

	_playerOnBlock.SetTexture(&_blockTexture);
	_playerOnBlock.SetStatu(_blockValueX / 2, _blockValueY+1);
}

void Field::SetAdjoinBlock() {
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {

			if (x > 0)_blockArray[x][y].SetAdjoinBlock(&_blockArray[x - 1][y], ADJOIN_PLACE::LEFT);
			if (y + 1 < _blockValueY)_blockArray[x][y].SetAdjoinBlock(&_blockArray[x][y + 1], ADJOIN_PLACE::FRONT);
			if (x + 1 < _blockValueX)_blockArray[x][y].SetAdjoinBlock(&_blockArray[x + 1][y], ADJOIN_PLACE::RIGHT);
			if (y > 0)_blockArray[x][y].SetAdjoinBlock(&_blockArray[x][y - 1], ADJOIN_PLACE::BACK);
		}
	}
}

void Field::Load() {


}

void Field::SetEnemy(char** enemyData, int enemyTextureValue, Enemy** enemyTypeArray) {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			if (enemyData[x][y] == 0) continue;

			_blockArray[x][y].SetEnemy(enemyTypeArray[enemyData[x][y] - 1]->GetClone());
			_blockArray[x][y].GetEnemy()->SetPlayer(&_player);
		}
	}
}

void Field::SetStrongBox(char** strongBoxData, int strongBoxValue) {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			if (strongBoxData[x][y] == 0)continue;

			_blockArray[x][y].SetObject(new CardStrongBox(&_strongBoxTexture,_cardManager));
		}
	}
}

void Field::SetStairs(char** stairsData) {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			if (stairsData[x][y] == 0)continue;

			_blockArray[x][y].SetObject(new Stairs(&_stairsTexture));
		}
	}
}


void Field::Update() {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].Update();
		}
	}
	_playerOnBlock.Update();

	if (_gameOver) {
		_gameOverCount--;
		if (_gameOverCount > 0) return;

		_gameOverCount = _gameOverTime;
		_gameOver = false;
		SceneManager::Instance().ReSet();
		SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE);
	}
}

void Field::MarchEnemy() {

	for (int y = _blockValueY - 1;y >= 0;y--) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].Advance();
		}
	}
	_endMarch = true;
}

bool Field::IsEndMarchEnemy() {

	if (!_endMarch) return false;
	_endMarch = false;

	return true;
}


void Field::AttackEnemy() {

	for (int y = _blockValueY - 1;y >= 0;y--) {
		for (int x = 0;x < _blockValueX;x++) {
			if (!_blockArray[x][y].IsHeldEnemy()) continue;
			if (!_blockArray[x][y].CheckEnemyCanAttck()||_blockArray[x][y].GetEnemy()->IsAttacked()) continue;

			_blockArray[x][y].EnemyAttck();
			return;
		}
	}
}

bool Field::IsEndAttackEnemy() {

	for (int y = 0;y < _blockValueY;y++)
		for (int x = 0;x < _blockValueX;x++) {
			if (!_blockArray[x][y].IsHeldEnemy()) continue;
			if (!_blockArray[x][y].CheckEnemyCanAttck()) continue;
			if (!_blockArray[x][y].GetEnemy()->IsAttacked())return false;
		}
	
	for (int y = 0;y < _blockValueY;y++)
		for (int x = 0;x < _blockValueX;x++) {
			if (!_blockArray[x][y].IsHeldEnemy()) continue;
			_blockArray[x][y].GetEnemy()->ResetAttck();
		}

	_player.FlowTurn();
	if (_player.IsDead()) _gameOver = true;

	return true;
}

void Field::ActionFieldOnObject(Vector2 mousePos) {

	for (int x = 0;x < _blockValueX;x++)
		if (_blockArray[x][_blockValueY - 1].CheckOnMouse(mousePos)) {
			_blockArray[x][_blockValueY - 1].ActionObject();
			MarchEnemy();
			return;
		}
}

Block* Field::GetMouseOnBlock(Vector2 mousePos) {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			if (_blockArray[x][y].CheckOnMouse(mousePos)) {
				return &_blockArray[x][y];
			}
		}
	}

	if (_playerOnBlock.CheckOnMouse(mousePos))return &_playerOnBlock;
	return nullptr;
}

void Field::InitialAttackable() {
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].InitialAlpha();
		}
	}

	_playerOnBlock.InitialAlpha();
}

void Field::TurnOffAttackable() {
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].SetAttackableFlg(false);
		}
	}

	_playerOnBlock.SetAttackableFlg(false);
}

void Field::AllAttackable() {
	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].SetAttackableFlg(true);
		}
	}
}

void Field::FrontAttackable() {
	for (int x = 0;x < _blockValueX;x++)
		_blockArray[x][_blockValueY - 1].SetAttackableFlg(true);
}


void Field::Render() {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].Render();
		}
	}

	_playerOnBlock.Render();
	_player.Render();


	if (_gameOver) _gameOverTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _gameOverTexture.GetWidth() / 2, g_pGraphics->GetTargetHeight() / 2 - _gameOverTexture.GetHeight() / 2);
}

void Field::DeleteBlockArray() {
	if (_blockArray == nullptr) return;

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].Delete();
		}
	}

	for (int i = 0;i < _blockValueX;i++) delete[] _blockArray[i];
	delete[] _blockArray;

	_blockArray = nullptr;
}

void Field::Release() {

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX;x++) {
			_blockArray[x][y].Release();
		}
	}
	DeleteBlockArray();
	_playerOnBlock.Release();

	_blockTexture.Release();
	_strongBoxTexture.Release();
	_stairsTexture.Release();
	_gameOverTexture.Release();

	_player.Release();
}