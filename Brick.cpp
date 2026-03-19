#include "stdafx.h"
#include "Brick.h"
#include "Framework.h"
#include "GameScene.h"
#include "InputManager.h"
#include "AABBCollider.h"
#include "ResourceManager.h"

Brick::Brick() : GameObject()
{
	name = "Brick";
	
}

void Brick::Initialize()
{

	ResourceManager& res = Scene::GetCurrentScene().GetResourceManager();
	Sprite* brickSprite = res.LoadBitmapFromFile(L"resources/sprites/brick.png");

	if (this->renderer && brickSprite)
	{
		renderer->SetSprite(brickSprite);
	}

	collider = new AABBCollider(this, imageX / 2, imageY / 2);

	AddComponent(collider);

}


void Brick::Update()
{
	GameObject::Update();

}

void Brick::LateUpdate()
{
	GameObject::LateUpdate();

}