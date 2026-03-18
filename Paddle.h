#pragma once
#include "GameObject.h"

class Paddle : public GameObject
{
public:

	Paddle();
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();


private:
	const float imageX = 120.0f;
	const float imageY = 20.0f;



};
