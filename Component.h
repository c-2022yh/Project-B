#pragma once
#include "stdafx.h"

class GameObject;

class Component
{
protected: 
	GameObject* owner;

public:
	Component(GameObject* owner) : owner(owner) {}
	virtual ~Component() {}

	virtual void Initialize() {};
	virtual void Update() = 0;
	virtual void Uninitialze() {};

	bool isActive;
};

