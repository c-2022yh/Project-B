#include "stdafx.h"
#include "CircleCollider.h"
#include "Collision.h"

CircleCollider::CircleCollider(GameObject* owner, const Circle& circle)
	:Collider(owner),boundingCircle(circle)
{
}

CircleCollider::CircleCollider(GameObject* owner, const Vector2& center, float radius)
	: Collider(owner), boundingCircle(center, radius)
{
}

CircleCollider::CircleCollider(GameObject* owner, float x, float y, float radius)
	:Collider(owner), boundingCircle(x,y,radius)
{
}

Collider::Circle CircleCollider::GetTransformedCircle()
{
	return Circle(boundingCircle.center + transform->position, boundingCircle.radius);
}

Vector2 CircleCollider::GetCenterOnScreen()
{
	return transform->position+ boundingCircle.center;
}

float CircleCollider::GetXOnScreen()
{
	return transform->position.x+boundingCircle.center.x;
}

float CircleCollider::GetYOnScreen()
{
	return transform->position.y+boundingCircle.center.y;
}

bool CircleCollider::Intersected(Collider& col)
{
	return col.Intersected(GetTransformedCircle());
}

bool CircleCollider::Intersected(const AABBBox& box)
{
	return Collision::Intersected(box,GetTransformedCircle());
}

bool CircleCollider::Intersected(const Circle& circle)
{
	return Collision::Intersected(GetTransformedCircle(),circle);
}

bool CircleCollider::Intersected(const Vector2& vector)
{
	return Collision::Intersected(GetTransformedCircle(),vector);
}
