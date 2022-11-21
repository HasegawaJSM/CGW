#include "Input.h"

void Input::Update() {

	g_pInput->GetMousePos(_mousePos);
	InputKey();
	InputMouse();
}

void Input::InputKey() {

	
}

void Input::InputMouse() {

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
		if (_tutorial->IsEnd()) {
			_cardManager->PickSelectCard(_mousePos);
			_cardManager->LookStackCards(_mousePos);
			_useCard->PushCard(_mousePos);
		}
		else _tutorial->Push();
	}
}