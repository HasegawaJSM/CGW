#include "ContactFile.h"
#include "SceneManager.h"

//
void ContactFile::Initialize() {
	_enemyContainer.Initialize();
}

void ContactFile::ReSet() {
	_crrentStageNumber = 0;
	SetStage();
	_map->SetNextStageNumber(_crrentStageNumber);
}

void ContactFile::SetStageManager() {
	FILE* file = fopen("StageManager.txt", "rt");
	if (file == NULL) return;

	fseek(file, 0, SEEK_END);
	_fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* buffer = (char*)malloc(_fileSize + 1);
	_fileSize = fread(buffer, 1, _fileSize, file);
	buffer[_fileSize] = '\0';

	stageValue = atoi(strtok(buffer, ","));
	_stageNameArray = new std::string[stageValue];

	
	for (int i = 0;i < stageValue;i++) {
		_stageNameArray[i] = strtok(NULL, ",");
	}

	_map->SetMapValue(stageValue);
	
	fclose(file);
	free(buffer);
}

void ContactFile::SetNextStage() {
	_crrentStageNumber++;
	if (_crrentStageNumber >= stageValue) {
		_crrentStageNumber = 0;
		SceneManager::Instance().ChangeScene(SCENE_TYPE::GAMECLEAR);
		return;
	}
	_map->SetNextStageNumber(_crrentStageNumber);
	SetStage();
	
	SceneManager::Instance().ChangeScene(SCENE_TYPE::MAP);
}

void ContactFile::SetStage() {

	Delete();

	FILE* file = fopen(_stageNameArray[_crrentStageNumber].c_str(), "rt");
	if (file == NULL) return;

	fseek(file, 0, SEEK_END);
	_fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);


	char* buffer = (char*)malloc(_fileSize + 1);
	_fileSize = fread(buffer, 1, _fileSize, file);
	buffer[_fileSize] = '\0';

	int blockValueX = atoi(strtok(buffer, ","));
	int blockValueY = atoi(strtok(NULL, ","));

	enemyTypeValue = atoi(strtok(NULL, ","));
	_enemyTypeArray = new Enemy*[enemyTypeValue];
	for (int i = 0;i < enemyTypeValue;i++) {
		std::string tmp = strtok(NULL, ",");
		_enemyTypeArray[i] = _enemyContainer.GetEnemy(tmp);
	}


	char** fileData = new char*[blockValueX];
	for (int i = 0;i < blockValueX;i++)fileData[i] = new char[blockValueY];

	for (int y = 0;y < blockValueY;y++) {
		for (int x = 0;x < blockValueX;x++) {
			fileData[x][y]= atoi(strtok(NULL, ","));
		}
	}

	_field->CreateField(blockValueX, blockValueY);
	_field->SetEnemy(fileData, enemyTypeValue, _enemyTypeArray);


	int strongBoxValue=atoi(strtok(NULL,","));

	for (int y = 0;y < blockValueY;y++) {
		for (int x = 0;x < blockValueX;x++) {
			fileData[x][y] = atoi(strtok(NULL, ","));
		}
	}

	_field->SetStrongBox(fileData, strongBoxValue);


	for (int y = 0;y < blockValueY;y++) {
		for (int x = 0;x < blockValueX;x++) {
			fileData[x][y] = atoi(strtok(NULL, ","));
		}
	}

	_field->SetStairs(fileData);

	for (int i = 0;i < blockValueX;i++) delete[] fileData[i];
	delete[] fileData;

	fclose(file);
	free(buffer);
}

void ContactFile::Delete() {
	if (_enemyTypeArray == nullptr) return;
	delete[] _enemyTypeArray;
	_enemyTypeArray = nullptr;
}

void ContactFile::Release() {
	Delete();
	_enemyContainer.Release();
}