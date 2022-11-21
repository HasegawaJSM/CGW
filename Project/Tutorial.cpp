#include "Tutorial.h"

Tutorial::Tutorial() :
	_currentExplanationNumber(0),
	_end(false)
{
}

void Tutorial::Initialize(){

	LoadTexture();
	_explanationArray = new Explanation[_explanationValue];

	int number = 0;
	CreateExplanation( number++, &_cardExplanationTexture, Vector2(g_pGraphics->GetTargetWidth() / 2 - _cardExplanationTexture.GetWidth() / 2, 200));
	CreateExplanation( number++, &_enemyExplanationTexture, Vector2(g_pGraphics->GetTargetWidth()- _enemyExplanationTexture .GetWidth()-50, 500));
	CreateExplanation( number++, &_stairsExplanationTexture, Vector2(g_pGraphics->GetTargetWidth() - _enemyExplanationTexture.GetWidth() - 50, 500));
}

void Tutorial::LoadTexture() {
	_cardExplanationTexture.Load("cardExplanation.jpg");
	_enemyExplanationTexture.Load("enemyExplanation.jpg");
	_stairsExplanationTexture.Load("stairsExplanation.jpg");
}

void Tutorial::ReSet() {
	_end = false;
	_currentExplanationNumber = 0;
}

void Tutorial::CreateExplanation(int number, CTexture* texture,Vector2 Pos) {
	_explanationArray[number].SetTexture(texture);
	_explanationArray[number].SetTexturePos(Pos);
}

void Tutorial::Update(){

}

void Tutorial::Push(){
	NextExplanation();
}

void Tutorial::NextExplanation() {
	_currentExplanationNumber++;

	if (_currentExplanationNumber >= _explanationValue) {
		_end = true;
		_currentExplanationNumber = 0;
	}
}

void Tutorial::Pull(){

}

void Tutorial::Render(){
	_explanationArray[_currentExplanationNumber].Render();
}

void Tutorial::Release(){
	for (int i = 0;i < _explanationValue;i++) _explanationArray[i].Release();

	delete[] _explanationArray;

	_cardExplanationTexture.Release();
	_enemyExplanationTexture.Release();
	_stairsExplanationTexture.Release();
}