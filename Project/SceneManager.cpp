#include "SceneManager.h"

#include "Title.h"
#include "Map.h"
#include "Game.h"
#include "GameClear.h"

SceneManager* SceneManager::_instance = nullptr;

void SceneManager::Initialize() {
	SetSceneArray();

	dynamic_cast<Game*> (_sceneArray[SCENE_TYPE::INGAME])->GetContactFile()->SetMap(dynamic_cast<Map*>(_sceneArray[SCENE_TYPE::MAP]));
	for (auto itr = _sceneArray.begin();itr != _sceneArray.end();itr++) itr->second->Initialize();

	_currentScene = _sceneArray[SCENE_TYPE::TITLE];
}

void SceneManager::ReSet() {
	for (auto itr = _sceneArray.begin();itr != _sceneArray.end();itr++) itr->second->ReSet();
}

void SceneManager::SetSceneArray() {

	_sceneArray[SCENE_TYPE::TITLE] = new Title();
	_sceneArray[SCENE_TYPE::MAP] = new Map();
	_sceneArray[SCENE_TYPE::INGAME] = new Game();
	_sceneArray[SCENE_TYPE::GAMECLEAR] = new GameClear();
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