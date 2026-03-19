#pragma once
#include "Scene.h"
#include <vector>

class Ball;
class Brick;
class Paddle;

class GameScene :
	public Scene
{
public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();

	void CheckCollision();


private:
	Ball* ball = nullptr;
	std::vector<Brick*> brickList;
	Paddle* paddle = nullptr;
};
