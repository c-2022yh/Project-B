#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "stdafx.h"
#include "GameObject.h"
#include "ResourceManager.h"


class Scene
{
	friend class Framework;
public:
	Scene();
	virtual ~Scene();
	
private:
	static Scene* currentScene;
	static Scene* nextScene;
	static void SwapScene();

public:
	static void ChangeScene(Scene* nextScene);
	static Scene& GetCurrentScene();			

private:
	std::list<GameObject*> gameObjectList;			//모든 게임오브젝트 리스트
	std::list<GameObject*> renderableList;			//렌더오브젝트의 리스트
	std::list<GameObject*> destroyedObjectList;		//삭제처리된 오브젝트 리스트
	ResourceManager* resourceManager;				//이미지 파일\

public:
	virtual void Initialize() = 0;
	virtual void Update();					//업데이트
	virtual void Render();					//렌더

public:
	GameObject* PushBackGameObject(GameObject* gameObject);	//게임오브젝트 푸쉬백
	void Destroy(GameObject* o);							//삭제처리

public:
	ResourceManager& GetResourceManager();					//Getter
};

