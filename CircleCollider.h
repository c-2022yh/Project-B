#pragma once
#include "Collider.h"

class GameObject;

class CircleCollider : public Collider
{
public:
	CircleCollider(GameObject* owner, const Circle& circle);
	CircleCollider(GameObject* owner, const Vector2& center, float radius);
	CircleCollider(GameObject* owner, float x, float y, float radius);

public:
	Circle boundingCircle;

public:
	Circle GetTransformedCircle();
	Vector2 GetCenterOnScreen();
	float GetXOnScreen();
	float GetYOnScreen();
	

	virtual void Update() override {}
	virtual bool Intersected(Collider& col);
	virtual bool Intersected(const AABBBox& box);
	virtual bool Intersected(const Circle& circle); 
	virtual bool Intersected(const Vector2& vector);
};

