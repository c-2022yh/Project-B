#include "stdafx.h"
#include "Ball.h"
#include "Framework.h"
#include "GameScene.h"
#include "InputManager.h"
#include "AABBCollider.h"
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

}

void Ball::Update()
{
	GameObject::Update();

	transform->position += velocity * speed * TimeManager::GetDeltaTime();

}

void Ball::LateUpdate()
{
	GameObject::LateUpdate();

	//º®¿¡ ´êÀ¸¸é Æ¨±â°Ô
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

	//this->OnCollision(other);


}

void Ball::OnCollision(GameObject* other)
{

}
