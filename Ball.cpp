#include "stdafx.h"
#include "Ball.h"
#include "Paddle.h"
#include "Framework.h"
#include "GameScene.h"
#include "InputManager.h"
#include "Collision.h"
#include "Collider.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
#include "ResourceManager.h"
#include "TimeManager.h"

Ball::Ball() : GameObject()
{
	name = "Ball";
	screenX = (float)Framework::GetInstance().GetWinApp().GetScreenWidth();
	screenY = (float)Framework::GetInstance().GetWinApp().GetScreenHeight();

	velocity = Vector2(1.0f, -1.0f);

}

void Ball::Initialize()
{
	GameObject::Initialize();

	ResourceManager& res = Scene::GetCurrentScene().GetResourceManager();
	Sprite* ballSprite = res.LoadBitmapFromFile(L"resources/sprites/ball.png");

	if (this->renderer && ballSprite)
	{
		renderer->SetSprite(ballSprite);
	}
	AddComponent(new CircleCollider(this, imageRadius));

	ballCollider = GetComponent<CircleCollider>();


}

void Ball::Update()
{
	GameObject::Update();

	transform->position += velocity * speed * TimeManager::GetDeltaTime();

}

void Ball::LateUpdate()
{
	GameObject::LateUpdate();

	CheckScreenCollision();
	CheckPaddleCollision();


}

void Ball::CheckScreenCollision() //벽에 닿으면 튕기게
{
	
	if (transform->position.x < imageRadius)
	{
		transform->position.x = imageRadius;
		if (velocity.x < 0) velocity.x *= -1.0f;
	}
	else if (transform->position.x > screenX - imageRadius)
	{
		transform->position.x = screenX - imageRadius;
		if (velocity.x > 0) velocity.x *= -1.0f;
	}

	if (transform->position.y < imageRadius)
	{
		transform->position.y = imageRadius;
		if (velocity.y < 0) velocity.y *= -1.0f;
	}
	else if (transform->position.y > screenY - imageRadius)
	{
		transform->position.y = screenY - imageRadius;
		if (velocity.y > 0) velocity.y *= -1.0f;
	}
}

void Ball::CheckPaddleCollision() //공-패들 간 충돌처리
{
	if (paddle == nullptr) return;

	AABBCollider* paddleCollider = paddle->GetComponent<AABBCollider>();
	ballCollider = GetCollider();

	if (!paddleCollider || !ballCollider) return;

	if (paddleCollider->Intersected(ballCollider->GetTransformedCircle()))
	{
		if (velocity.y > 0)
		{
			// 위치 보정: 패들 윗면에 딱 붙임

			float paddleTopY = paddleCollider->GetTopOnScreen();

			float ballHeight = ballCollider->GetTransformedCircle().radius * 2.0f;
			transform->position.y = paddleTopY - ballHeight - 1.0f;

			velocity.y *= -1.0f;

			// 반사각 조절 (패들 중심에서의 거리 기반)
			float paddleCenterX = paddleCollider->GetCenterOnScreen().x;
			float ballCenterX = ballCollider->GetCenterOnScreen().x;
			float halfWidth = paddleCollider->GetWidth() * 0.5f;

			velocity.x = (ballCenterX - paddleCenterX) / halfWidth;

			velocity.Normalize();

		}
	}


}




void Ball::OnCollisionBrick(Brick* b)
{

}
