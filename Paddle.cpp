#include "stdafx.h"
#include "Paddle.h"
#include "Framework.h"
#include "GameScene.h"
#include "InputManager.h"
#include "AABBCollider.h"
#include "ResourceManager.h"

Paddle::Paddle() : GameObject()
{
    name = "Paddle"; 

   

}

void Paddle::Initialize()
{
    GameObject::Initialize();
    
    ResourceManager& res = Scene::GetCurrentScene().GetResourceManager();
    Sprite* paddleSprite = res.LoadBitmapFromFile(L"resources/sprites/paddle.png");
    
    if (this->renderer && paddleSprite)
    {
        renderer->SetSprite(paddleSprite);
    }
    
    float sw = (float)Framework::GetInstance().GetWinApp().GetScreenWidth();
    float sh = (float)Framework::GetInstance().GetWinApp().GetScreenHeight();
    transform->position = Vector2(sw / 2.0f, sh - 50.0f);

    collider  = new AABBCollider(this, imageX / 2, imageY / 2);

    AddComponent(collider);

   
}

void Paddle::Update()
{
    GameObject::Update();

    float x = InputManager::GetMouseX() * 1.0f;

    if (x < 60) x = 60;
    if (x > 540) x = 540;

    transform->position.x = x;
}

void Paddle::LateUpdate()
{
    GameObject::LateUpdate();
}