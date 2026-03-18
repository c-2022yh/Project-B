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

	Vector2 velocity;			// 공의 속도 (방향 + 힘)
	float speed = 200.0f;		// 이동 속력

	float screenX;
	float screenY;
	
	void CheckScreenCollision();
	void CheckPaddleCollision();
	void CheckBrickCollision();
	

};
