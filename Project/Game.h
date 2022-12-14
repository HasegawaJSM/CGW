#pragma once
#include	"Mof.h"
#include	"IBaseScene.h"
#include	"Field.h"
#include	"CardManager.h"
#include	"Input.h"
#include	"FlowTurn.h"
#include	"ContactFile.h"
#include	"Tutorial.h"
#include	"FadeIn.h"

class Game:public IBaseScene
{
	Field _field;
	CardManager _cardManager;
	Input _input;
	FlowTurn _flowTurn;
	ContactFile _contactFile;
	Tutorial _tutorial;
	FadeIn _fadeIn;

	int _time = 50;

public:
	void ReSet();
	void Initialize();
	void Update();
	void Render();
	void Release();

	void NextStage();

	ContactFile* GetContactFile() { return &_contactFile; }

private:
	void SetStatuTutorial();
};