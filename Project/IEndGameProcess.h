#pragma once
class IEndGameProcess
{
public:
	virtual void Initialize() {}
	virtual void Render() {}
	virtual void Release() {}
};