#pragma once
#include	"Mof.h"
#include	"map"
#include	"IBaseScene.h"
#include	"IEndGameProcess.h"

enum class ProcessType {
	GameClear,
	GameOver,
};

class EndGameProcess :public IBaseScene
{
	const int _processTime = 100;
	int _processCount;

	std::map<ProcessType, IEndGameProcess*> _processArray;
	IEndGameProcess* _currentProcess = nullptr;

public:
	void Initialize();
	void ReSet();

	void Update();
	void Render();
	void Release();

	void SetProcess(ProcessType type) { _currentProcess = _processArray[type]; }

private:
	void CreateProcessArray();
	void Timer();
};