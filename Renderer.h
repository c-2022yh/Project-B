#pragma once
#include "Component.h"

struct Sprite;
class Transform;

class Renderer : public Component
{
public:

	Renderer(GameObject* owner);
	Renderer(GameObject* owner, Sprite* startSprite, float alpha = 1.0f);
	virtual ~Renderer() {} 

protected:
	Sprite* currentSprite = nullptr;
	float alpha;
	bool initialized;		//스프라이트가 있는지

public:
	bool GetInitialized();
	Sprite& GetSprite();
	virtual void Update() {}virtual void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);

	void SetSprite(Sprite* sprite) { currentSprite = sprite; initialized = (sprite != nullptr); }
};

