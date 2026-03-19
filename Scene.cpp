#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"

Scene* Scene::currentScene;
Scene* Scene::nextScene;

Scene::Scene(): resourceManager(new ResourceManager())
{
}

Scene::~Scene()
{
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}
	//모두 delete된 변수이므로 리스트만 비워줌
	gameObjectList.clear();
	renderableList.clear();
	SAFE_DELETE(resourceManager);
}

void Scene::SwapScene()
{
	if (!nextScene)
		return;

	SAFE_DELETE(currentScene);
	currentScene = nextScene;
	nextScene = nullptr;

	currentScene->Initialize();
}

void Scene::ChangeScene(Scene* nextScene)
{
	Scene::nextScene = nextScene;
}

Scene& Scene::GetCurrentScene()
{
	return *Scene::currentScene;
}

void Scene::Update()
{
	//Update
	for (auto& i : gameObjectList)	
		if(i->GetActive())
			i->Update();

	//LateUpdate
	for (auto& i : gameObjectList)
		if (i->GetActive())
			i->LateUpdate();

	
	if (!destroyedObjectList.empty())
	{
		for (auto* obj : destroyedObjectList)
		{
			obj->OnDestroy();
			gameObjectList.remove(obj);
			renderableList.remove(obj);
			SAFE_DELETE(obj); // 실제 메모리 해제
		}
		destroyedObjectList.clear();
	}
}

void Scene::Render()
{
	//싱글턴 패턴, Getter
	//d2dapp과 rendertarget을 받아옴
	D2DApp& d2dapp = Framework::GetInstance().GetD2DApp();
	ID2D1HwndRenderTarget& renderTarget = Framework::GetInstance().GetD2DApp().GetRenderTarget();

	
	d2dapp.BeginRender();//렌더 시작	
	for (auto& i : renderableList)
		i->renderer->Render(renderTarget,*i->transform);	
	d2dapp.EndRender();//렌더 종료
}

GameObject* Scene::PushBackGameObject(GameObject* gameObject)
{
	gameObjectList.push_back(gameObject);
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;
}

void Scene::Destroy(GameObject* o)
{
	destroyedObjectList.push_back(o);
}


ResourceManager& Scene::GetResourceManager()
{
	return *resourceManager;
}
