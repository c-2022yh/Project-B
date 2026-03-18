#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Framework.h"

GameObject::GameObject() : isActive(true), name("New Object")
{
	//기본 부품들을 생성 (자신을 주인으로 설정)
	transform = new Transform(this);
	components.push_back(transform);

	renderer = new Renderer(this);
	components.push_back(renderer);

}

GameObject::~GameObject()
{
	for (auto c : components)
	{
		if (c) delete c;
	}
	components.clear();

	transform = nullptr;
	renderer = nullptr;
}


void GameObject::Update()
{
	if (!isActive) return;

	for (auto c : components)
	{
		if (c) c->Update();
	}
}
bool GameObject::GetActive()
{
	return isActive;
}

void GameObject::AddComponent(Component* component)
{
	if (component) components.push_back(component);
}

