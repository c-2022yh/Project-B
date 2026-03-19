#pragma once
#include "GameObject.h"
#include "math.h"

class Paddle;


class Ball : public GameObject
{
public:
	Ball();
	virtual void Initialize();
	virtual void Update() override;
	virtual void LateUpdate();
	void OnCollision(GameObject* other);

	

	void SetTargetPaddle(Paddle* p) { paddle = p; }
private:
	Paddle* paddle = nullptr;
	const float imageRadius = 8.0f;

	Vector2 velocity;
	float speed = 200.0f;

	float screenX;
	float screenY;
	
	void CheckScreenCollision();
	void CheckPaddleCollision();
	void CheckBrickCollision();
	

};
