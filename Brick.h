#pragma once
#include "GameObject.h"

class AABBCollider;

class Brick : public GameObject
{
public:
	Brick();
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();

	AABBCollider* GetCollider() { return collider; }

	float getImageX() const { return imageX; };
	float getImageY() const { return imageY; };



private:
	const float imageX = 60.0f;
	const float imageY = 20.0f;


	AABBCollider* collider = nullptr;
};

