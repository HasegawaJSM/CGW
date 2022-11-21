#include "CardDataLoad.h"

void CardDataLoad::Initialize() {
	FILE* file = fopen("CardData.txt", "rt");
	if (file == NULL) return;

	fseek(file, 0, SEEK_END);
	_fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* buffer = (char*)malloc(_fileSize + 1);
	_fileSize = fread(buffer, 1, _fileSize, file);
	buffer[_fileSize] = '\0';

	_cardValue = atoi(strtok(buffer, ","));

	_choicesCardArray = new ChoicesCard[_cardValue];
	for (int i = 0;i < _cardValue;i++) {
		_choicesCardArray[i].cardName = strtok(NULL, ",");
		_choicesCardArray[i].cardValue = atoi(strtok(NULL, ","));
	}

	fclose(file);
	free(buffer);
}

void CardDataLoad::Release() {
	delete[] _choicesCardArray;
}