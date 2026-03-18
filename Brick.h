#pragma once
#include "GameObject.h"
class Brick : public GameObject
{
public:
	Brick();
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();

private:
	float imageX = 60.0f;
	float imageY = 20.0f;
};

