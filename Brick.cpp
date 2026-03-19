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

	// 만약 Collider에 위치를 수동으로 찍어줘야 하는 구조라면:
	if (collider && transform)
	{
		// Collider의 중심이나 범위를 현재 내 위치로 갱신
		// (함수 이름은 프레임워크에 맞게 수정하세요. 예: SetCenter, SetPosition 등)
		//collider-> 
	}

}

void Brick::LateUpdate()
{
	GameObject::LateUpdate();

}