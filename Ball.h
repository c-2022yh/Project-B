#pragma once
#include "GameObject.h"
#include "math.h"

class Paddle;
class Brick;
class CircleCollider;

class Ball : public GameObject
{
public:
	Ball();
	virtual void Initialize();
	virtual void Update() override;
	virtual void LateUpdate();

	CircleCollider* GetCollider() { return ballCollider; }
	
	void SetTargetPaddle(Paddle* p) { paddle = p; }

	void OnCollisionBrick(Brick* b);

private:
	Paddle* paddle = nullptr;
	const float imageRadius = 8.0f;

	Vector2 velocity;
	float speed = 500.0f;

	float screenX;
	float screenY;
	
	void CheckScreenCollision();
	void CheckPaddleCollision();

	CircleCollider* ballCollider = nullptr;

	

};
