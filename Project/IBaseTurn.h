#pragma once
class IBaseTurn
{

public:
	virtual void Update() = 0;
	virtual bool EndTurn() = 0;
};