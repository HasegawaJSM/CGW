#include "CardSelect.h"

void CardSelect::Initialzie() {
	_backGround.Load("CardSelectBackGround.png");
	_pickButton.Load("CardSelectPickButton.jpg");

	_buttonSizeX = _buttonSizeY = 100;
	_backGroundScale = 0.7f;
	_buttonScale = 0.6f;

	_backGroundPosition = Vector2(g_pGraphics->GetTargetWidth() / 2 - _backGround.GetWidth() * _backGroundScale / 2,
		g_pGraphics->GetTargetHeight() / 2 - _backGround.GetHeight() * _backGroundScale / 2);

	_butttonRectangle = CRectangle(g_pGraphics->GetTargetWidth() / 2 - _pickButton.GetWidth() * _buttonScale / 2, 600,
		g_pGraphics->GetTargetWidth() / 2 + _pickButton.GetWidth() * _buttonScale / 2, 600 + _pickButton.GetHeight() * _buttonScale);


	_choicesButtonArray = new CRectangle[_choicesCardValue];
	for (int i = 0;i < _choicesCardValue;i++) _choicesButtonArray[i] =
		CRectangle(g_pGraphics->GetTargetWidth() / 2 - (((float)_choicesCardValue / 2 - i) * _buttonSizeX), g_pGraphics->GetTargetHeight() / 2,
			g_pGraphics->GetTargetWidth() / 2 - (((float)_choicesCardValue / 2 - (i + 1)) * _buttonSizeX), g_pGraphics->GetTargetHeight() / 2 + _buttonSizeY * 2);

	_currentCardNumber = new int[_maxSelectCardValue] {-1};

	_maxSeedTime = 100;
}

void CardSelect::SetSelectCard() {
	_random.SetSeed(_seedCount);
	for (int i = 0;i < _choicesCardValue;i++) {
		int cardNumber = _random.Random(_choicesCardArrayValue);

		_selectCardArray[i] = _choicesCardArray[cardNumber];
	}

	_currentSelectCardCount = 0;
}

void CardSelect::PickCard(Vector2 mousePos) {

	for (int i = 0;i < _choicesCardValue;i++) {
		if (_choicesButtonArray[i].CollisionPoint(mousePos)) {

			//既にピック済にカードを非ピック状態に戻す
			for (int x = 0;x < _currentSelectCardCount;x++) {
				if (_currentCardNumber[x] == i) {
					if (x != _currentSelectCardCount - 1) {
						for (int y = _currentSelectCardCount - 1;y > 0; y--)
							_currentCardNumber[y-1] = _currentCardNumber[y];
					}

					_currentCardNumber[_currentSelectCardCount - 1] = -1;
					_currentSelectCardCount--;
					return;
				}
			}

			if (_currentSelectCardCount < _maxSelectCardValue) {
				_currentCardNumber[_currentSelectCardCount] = i;
				_currentSelectCardCount++;
				break;
			}
			//ピック済数がピック可能枚数を上回ってるなら入れ替え
			else {
				
				for (int x = 0;x < _maxSelectCardValue - 1;x++) 
					_currentCardNumber[x] = _currentCardNumber[x + 1];
				_currentCardNumber[_maxSelectCardValue - 1] = i;
			}
		}
	}
}

bool CardSelect::CheckPickedCard(Vector2 mousePos) {
	if (_currentSelectCardCount < _maxSelectCardValue) return false;
	if (!_butttonRectangle.CollisionPoint(mousePos)) return false;
		return true;
}

std::string CardSelect::GetPickCardName(int number) {
	return _selectCardArray[_currentCardNumber[number]].cardName;
}

void CardSelect::Update() {
	_seedCount++;
	if (_seedCount >= _maxSeedTime) _seedCount = 0;
}

void CardSelect::Render() {
	_backGround.RenderScale(_backGroundPosition.x, _backGroundPosition.y, _backGroundScale);
	if (_currentSelectCardCount >= _maxSelectCardValue) _pickButton.RenderScale(_butttonRectangle.Left, _butttonRectangle.Top, _buttonScale);

	for (int i = 0;i < _choicesCardValue;i++) {

		if(_currentSelectCardCount>0) PickCardRender(i);
		else {
			_selectCardArray[i].cardTexture->Render(_choicesButtonArray[i].Left, _choicesButtonArray[i].Top);
		}
		CGraphicsUtilities::RenderString(_choicesButtonArray[i].Left, _choicesButtonArray[i].Top - 30, MOF_COLOR_HBLACK, "× %d", _selectCardArray[i].cardValue);
	}

	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth() / 2 - 150, 200, MOF_COLOR_HWHITE, "カードを%dセット選ぼう", _maxSelectCardValue);
}

void CardSelect::PickCardRender(int number) {

	for (int x = 0;x < _currentSelectCardCount;x++) {
		if (number == _currentCardNumber[x]) {
			_selectCardArray[number].cardTexture->Render(_choicesButtonArray[number].Left, _choicesButtonArray[number].Top + _buttonSizeY / 2);
			return;
		}
	}
	_selectCardArray[number].cardTexture->Render(_choicesButtonArray[number].Left, _choicesButtonArray[number].Top);
}

void CardSelect::Release() {
	_backGround.Release();
	_pickButton.Release();

	delete[] _choicesButtonArray;
}