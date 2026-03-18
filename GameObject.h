#pragma once
#include "stdafx.h"

class Component;
class Transform;
class Renderer;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

private:
	bool isActive;
	std::vector<Component*> components; // 모든 컴포넌트를 관리할 리스트

public:
	std::string name;		//객체 고유의 이름
	Transform* transform;	//위치, 회전값, 크기값 등을 가짐
	Renderer* renderer;

	virtual void Initialize() {}		//오브젝트가 처음 만들었을 때 호출
	virtual void Update();				//매 프레임마다 호출
	virtual void LateUpdate() {}		//Update가 호출된 이후 호출
	virtual void OnDestroy() {}			//오브젝트가 삭제될 때 호출

	// 나중에 새로운 부품을 끼워넣고 싶을 때를 위해
	void AddComponent(Component* component);

	bool GetActive();
};

