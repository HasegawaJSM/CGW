#include "UseCard.h"
#include "SceneManager.h"
#include "EndGameProcess.h"

void UseCard::Update() {
	if (_handInCard->GetHeldCardValue() <= 0) {
		GameOver();
		return;
	}
	UpdateUI();
}

void UseCard::PushCard(Vector2 mousePos) {
	_mousePos = mousePos;
	PickCard();
}

void UseCard::PickCard() {
	if (_cardManager->IsSelectCard()) return;

	ActionCard();
	Card* mouseOnCard = _handInCard->GetMouseOnCard(_mousePos);
	if (mouseOnCard == nullptr) return;

	if (_pickCard != nullptr) _pickCard->SetOnMouseFlg(false);
	if (mouseOnCard == _pickCard) {
		_pickCard = nullptr;
	}
	else {
		_pickCard = mouseOnCard;
		_pickCard->SetOnMouseFlg(true);
	}
}

void UseCard::UpdateUI() {
	g_pInput->GetMousePos(_mousePos);

	
	if (_handInCard->GetMouseOnCard(_mousePos) != nullptr) {
		_cardManager->SetRenderText(_handInCard->GetMouseOnCard(_mousePos)->GetCardName());
		ShineAttackableBlock(_handInCard->GetMouseOnCard(_mousePos));
	}
	else if (_pickCard != nullptr) {
		ShineUpBlock();
		ShineAttackableBlock(_pickCard);
		_cardManager->SetRenderText(_pickCard->GetCardName());
	}
	else {
		_cardManager->SetRenderText("");
		_field->TurnOffAttackable();
	}
}

void UseCard::ShineUpBlock() {
	if (IsAuditAction()) _pickCard->ShineUpBlock(_pickBlock);
}

void UseCard::ShineAttackableBlock(Card* card) {

	switch (card->GetActionType()) {
	case ACTION_TYPE::AllCorrespondence:
		ChangeCurrentAttackable(ACTION_TYPE::AllCorrespondence);
		_field->AllAttackable();
		break;

	case ACTION_TYPE::FrontCorrespondence:
		ChangeCurrentAttackable(ACTION_TYPE::FrontCorrespondence);
		_field->FrontAttackable();
		break;

	case ACTION_TYPE::PlayerCorrespondence:
		ChangeCurrentAttackable(ACTION_TYPE::PlayerCorrespondence);
		_field->GetPlayerOnBlock()->SetAttackableFlg(true);
		break;
	}
}

void UseCard:: ChangeCurrentAttackable(ACTION_TYPE nextType) {
	if (_currentAttackable == nextType) return;

	_field->TurnOffAttackable();
	_field->InitialAttackable();
	_currentAttackable = nextType;
}

void UseCard::ActionCard() {

	if (_pickCard == nullptr) _field->ActionFieldOnObject(_mousePos);
	else if (IsAuditAction()) {

		_pickCard->Action(_pickBlock);
		_handInCard->UseCard(_pickCard);
		_pickCard = nullptr;
		_pickBlock = nullptr;
		_useCard = true;
	}
}

bool UseCard::IsAuditAction() {
	if (_cardManager->IsSelectCard()) return false;
	
	if (_pickCard->GetActionType() == ACTION_TYPE::PlayerCorrespondence) {
		_pickBlock = _field->GetMouseOnBlock(_mousePos);
		if (_pickBlock == nullptr) return false;
		if (!_pickBlock->IsHeldPlayer()) return false;
	}
	else {
		_pickBlock = _field->GetMouseOnBlock(_mousePos);
		if (_pickBlock == nullptr) return false;
		if (_pickBlock->IsHeldPlayer()) return false;
		if(_pickCard->GetActionType() == ACTION_TYPE::FrontCorrespondence && _pickBlock->GetAdjoinBlock(ADJOIN_PLACE::FRONT) != nullptr) return false;
	}
	return true;
}

bool UseCard::EndTurn() {
	if (!_useCard) return false;
	_useCard = false;
	return true;
}

void UseCard::GameOver() {
	dynamic_cast<EndGameProcess*>(SceneManager::Instance().GetScene(SceneType::EndGame))->SetProcess(ProcessType::GameOver);
	SceneManager::Instance().ChangeScene(SceneType::EndGame);
}