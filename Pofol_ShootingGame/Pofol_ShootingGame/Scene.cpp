#include "Scene.h"
#include "CursorManager.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}


void Scene::MakeBorder(float _x, float _y, float _Width, float _Height)
{
	// �ֻ�/���ϴ� ��
	for (int i = 0; i < _Width + 2; ++i)
		for (int j = 0; j < 2; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (-2) + (2 * i), _y + (-1) + ((_Height + 1) * j), (char*)"##");

	// �����ڸ� ��
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < _Height; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (-2) + ((_Width * 2 + 2) * i), _y + j, (char*)"##");

	// �߾� ����
	for (int i = 0; i < _Width; ++i)
		for (int j = 0; j < _Height; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (2 * i), _y + j, (char*)"  ");
}
