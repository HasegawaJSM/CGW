#pragma once
class IBaseScene
{

public:
	virtual void ReSet() {};
	virtual void Initialize() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void Release() {};
};