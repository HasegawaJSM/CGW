#include "MarchEnemy.h"

void MarchEnemy::Update() {

	_field->MarchEnemy();
}

bool MarchEnemy::EndTurn() {
	
	return _field->IsEndMarchEnemy();
}