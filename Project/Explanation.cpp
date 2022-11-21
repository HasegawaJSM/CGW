#include "Explanation.h"

void Explanation::Initialize(){
}

void Explanation::Render(){
	_pickUp.Render();
	_texture->Render(_texturePos.x, _texturePos.y);
}

void Explanation::Release(){

}