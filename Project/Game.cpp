#include "Game.h"

void Game::Initialize() {

	_input.SetField(&_field);
	_input.SetCardManager(&_cardManager);
	_input.SetUseCard(_flowTurn.GetUseCard());
	_input.SetTutorial(&_tutorial);

	_flowTurn.SetStatu(&_cardManager, &_input, &_field);

	_contactFile.SetField(&_field);

	_field.SetCardManager(&_cardManager);

	_field.Initialize();
	_cardManager.Initialize();
	_flowTurn.Initialize();
	_contactFile.Initialize();

	_contactFile.SetStageManager();
	_contactFile.SetStage();

	_tutorial.Initialize();
	_fadeIn.SetFadeInTime(_time);
	_fadeIn.ReSet();
}

void Game::SetStatuTutorial() {
	_tutorial.SetPickUpRect(0, _cardManager.GetHandInCard()->GetRenderCardsRect());
	_tutorial.SetPickUpRect(1, _field.GetTutorialEnemyBlockRect());
	_tutorial.SetPickUpRect(2, _field.GetTutorialStairsOnBlockRect());
}

void Game::ReSet() {
	_contactFile.ReSet();
	_flowTurn.ReSet();
	_cardManager.ReSet();
	_tutorial.ReSet();
	_fadeIn.ReSet();
	_field.ReSet();
}

void Game::Update() {

	if (!_fadeIn.IsEnd()) {
		_fadeIn.Update();
		if (_fadeIn.IsEnd()) SetStatuTutorial();
	}
	else _input.Update();

	if (_tutorial.IsEnd())_field.Update();
	_cardManager.Update();
	_flowTurn.Update();
}

void Game::NextStage() {
	_contactFile.SetNextStage();
}

void Game::Render(){
	_field.Render();
	_cardManager.Render();

	if (!_tutorial.IsEnd()) _tutorial.Render();
	if (!_fadeIn.IsEnd())_fadeIn.Render();
}

void Game::Release(){
	_field.Release();
	_cardManager.Release();
	_flowTurn.Release();
	_contactFile.Release();
	_tutorial.Release();
}