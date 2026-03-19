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
	CheckBrickCollision();


	//this->OnCollision(other);


}

void Ball::OnCollision(GameObject* other)
{

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
	if (paddleCollider == nullptr) return;

	CircleCollider* ballCollider = GetComponent<CircleCollider>();

	if (paddleCollider->Intersected(ballCollider->GetTransformedCircle()))
	{
		if (velocity.y > 0)
		{
			// 위치 보정: 패들 윗면에 딱 붙임
			transform->position.y = paddle->transform->position.y - paddle->getImageY() / 2.0f - imageRadius;

			velocity.y *= -1.0f;

			// 반사각 조절 (패들 중심에서의 거리 기반)
			float halfWidth = paddle->getImageX() * 0.5f;
			float diff = transform->position.x - paddle->transform->position.x;
			velocity.x = diff / halfWidth;
			velocity.Normalize();
			velocity *= speed;
		}
	}


}

void Ball::CheckBrickCollision()
{

}
