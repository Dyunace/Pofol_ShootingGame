#pragma once
#include "Headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}
private:
	Scene* SceneState;
private:
	SceneManager();
public:
	~SceneManager();
public:
	void SetScene(SCENEID _SceneState);
	void Update();
	void Render();
	void Release();
};

