#pragma once
#include	"Block.h"
enum class ACTION_TYPE {
	AllCorrespondence,
	FrontCorrespondence,
	PlayerCorrespondence
};

class IBaseAction
{

public:
	virtual void Action(Block* block) = 0;
	virtual void ShineUpBlock(Block* block) = 0;
	virtual ACTION_TYPE GetType() = 0;

protected:
	virtual void ShineUp(Block* block) {
		block->ShineUp();
	}
};

