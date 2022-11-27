#pragma once
#include	"map"
#include	"IBaseScene.h"

enum class SceneType {
	Title,
	Map,
	InGame,
	EndGame,
};

class SceneManager
{
	static SceneManager* _instance;

	IBaseScene* _currentScene;
	std::map<SceneType, IBaseScene*> _sceneArray;

public:

	void ReSet();
	void Initialize();
	void Update();
	void Render();
	void Release();

	static SceneManager& Instance() {
		if (_instance == nullptr) _instance = new SceneManager();
		return *_instance;
	}

	void ChangeScene(SceneType nextScene) { _currentScene = _sceneArray[nextScene]; }
	IBaseScene* GetScene(SceneType sceneType) { return _sceneArray[sceneType]; }

private:
	void SetSceneArray();
};