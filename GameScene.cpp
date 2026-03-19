#include "stdafx.h"
#include "GameScene.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "Transform.h"
#include "AABBCollider.h"
#include "CIrcleCollider.h"





void GameScene::Initialize()
{


	paddle = new Paddle();
	paddle->Initialize();
	PushBackGameObject(paddle);

	ball = new Ball();
	ball->Initialize();
	ball->SetTargetPaddle(paddle);
	PushBackGameObject(ball);   
	ball->transform->position = Vector2(200.0f, 200.0f);

	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Brick* brick = new Brick();
			brick->transform->position = Vector2(36.0f + (i * 62.0f), 20.0f + (j * 22.0f));
			
			brick->Initialize();
			PushBackGameObject(brick);
			brickList.push_back(brick);
			

		}
		
	}

}
void GameScene::Update()
{
	Scene::Update();
	CheckCollision();
	
}


void GameScene::LateUpdate()
{
	
}


void GameScene::CheckCollision()
{
	for (auto it = brickList.begin();it != brickList.end();)
	{
		if ((*it)->GetCollider()->Intersected(ball->GetCollider()->GetTransformedCircle())) //충돌
		{

			ball->OnCollisionBrick(*it); //공 움직임 조정

			Scene::GetCurrentScene().Destroy(*it);
			it = brickList.erase(it);
		}
		else it++;
	}
}



