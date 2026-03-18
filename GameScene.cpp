#include "stdafx.h"
#include "GameScene.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "Transform.h"



void GameScene::Initialize()
{


	Paddle* paddle = new Paddle();
	paddle->Initialize();
	PushBackGameObject(paddle);

	Ball* ball = new Ball();
	ball->Initialize();
	ball->SetTargetPaddle(paddle);
	PushBackGameObject(ball);   
	ball->transform->position = Vector2(200.0f, 200.0f);

	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Brick* brick = new Brick();
			brick->Initialize();
			PushBackGameObject(brick);

			brick->transform->position = Vector2(36.0f + (i * 62.0f), 20.0f + (j * 22.0f));
			brickList.push_back(brick);

		}
		
	}

}
