#include "EndGameProcess.h"
#include "SceneManager.h"
#include "GameClear.h"
#include "GameOver.h"

void EndGameProcess::Initialize() {
	CreateProcessArray();

	for (auto itr = _processArray.begin();itr != _processArray.end();itr++) {
		itr->second->Initialize();
	}

	_processCount = _processTime;
}

void EndGameProcess::CreateProcessArray() {
	_processArray[ProcessType::GameClear] = new GameClear();
	_processArray[ProcessType::GameOver] = new GameOver();
}

void EndGameProcess::ReSet() {
	_processCount = _processTime;
}

void EndGameProcess::Update() {
	if (_currentProcess == nullptr) return;

	Timer();
}

void EndGameProcess::Timer() {
	_processCount--;
	if (_processCount > 0) return;

	SceneManager::Instance().ReSet();
	SceneManager::Instance().ChangeScene(SceneType::Title);
}

void EndGameProcess::Render() {
	if (_currentProcess == nullptr) return;

	_currentProcess->Render();
}

void EndGameProcess::Release() {
	for (auto itr = _processArray.begin();itr != _processArray.end();itr++) {
		itr->second->Release();
	}
}