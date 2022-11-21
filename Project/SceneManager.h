#pragma once
#include	"map"
#include	"IBaseScene.h"

enum class SCENE_TYPE {
	TITLE,
	MAP,
	INGAME,
	GAMECLEAR,
};

class SceneManager
{
	static SceneManager* _instance;

	IBaseScene* _currentScene;
	std::map<SCENE_TYPE, IBaseScene*> _sceneArray;

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

	void ChangeScene(SCENE_TYPE nextScene) { _currentScene = _sceneArray[nextScene]; }
	IBaseScene* GetScene(SCENE_TYPE sceneType) { return _sceneArray[sceneType]; }

private:
	void SetSceneArray();
};