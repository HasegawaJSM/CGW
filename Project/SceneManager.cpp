#include "SceneManager.h"

#include "Title.h"
#include "Map.h"
#include "Game.h"
#include "EndGameProcess.h"

SceneManager* SceneManager::_instance = nullptr;

void SceneManager::Initialize() {
	SetSceneArray();

	dynamic_cast<Game*> (_sceneArray[SceneType::InGame])->GetContactFile()->SetMap(dynamic_cast<Map*>(_sceneArray[SceneType::Map]));
	for (auto itr = _sceneArray.begin();itr != _sceneArray.end();itr++) itr->second->Initialize();

	_currentScene = _sceneArray[SceneType::Title];
}

void SceneManager::ReSet() {
	for (auto itr = _sceneArray.begin();itr != _sceneArray.end();itr++) itr->second->ReSet();
}

void SceneManager::SetSceneArray() {

	_sceneArray[SceneType::Title] = new Title();
	_sceneArray[SceneType::Map] = new Map();
	_sceneArray[SceneType::InGame] = new Game();
	_sceneArray[SceneType::EndGame] = new EndGameProcess();
}

void SceneManager::Update() {
	_currentScene->Update();
}

void SceneManager::Render() {
	_currentScene->Render();
}

void SceneManager::Release() {
	for (auto itr = _sceneArray.begin();itr != _sceneArray.end();itr++) {
		itr->second->Release();
		delete itr->second;
	}

	if (_instance != nullptr) delete _instance;
}