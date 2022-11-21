#pragma once
#include	"Explanation.h"

class Tutorial
{
	const int _explanationValue = 3;
	Explanation* _explanationArray;
	int _currentExplanationNumber;
	bool _end;
	CTexture _cardExplanationTexture, _enemyExplanationTexture, _stairsExplanationTexture;

public:
	Tutorial();
	void Initialize();
	void ReSet();
	void SetPickUpRect(int number, CRectangle rect) { _explanationArray[number].SetPickUpRectangle(rect); }

	void Update();
	void Push();
	void Pull();

	void Render();
	void Release();

	bool IsEnd() { return _end; }

private:
	void LoadTexture();
	void NextExplanation();
	void CreateExplanation( int number, CTexture*,Vector2 Pos);
};