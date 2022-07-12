#include "Scene.h"
#include "CursorManager.h"

Scene::Scene()
{
}

Scene::Scene(string* _str)
{
}

Scene::~Scene()
{
}


void Scene::MakeBorder(float _x, float _y, float _Width, float _Height)
{
	// 최상/최하단 줄
	for (int i = 0; i < _Width; ++i)
		for (int j = 0; j < 2; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + i * 2, _y + ((_Height * 3 + 3) * j), (char*)"##");

	// 가장자리 줄
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < (_Height * 3 + 2); ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + i * (_Width * 2 - 2), _y + 1 + j, (char*)"##");

	// 중앙 공백
	for (int i = 0; i < _Width - 2; ++i)
		for (int j = 0; j < _Height * 3 + 2; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (i * 2) + 2, _y + j + 1, (char*)"  ");
}
