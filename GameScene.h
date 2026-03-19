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
	void Initialize();
	void Update();
	void LateUpdate();

	void CheckCollision();


private:
	Ball* ball = nullptr;
	std::vector<Brick*> brickList;
	Paddle* paddle = nullptr;
};
