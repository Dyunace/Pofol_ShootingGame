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

/// <summary>
/// UI�� ���� �����
/// ���� ���̴� ���� ������ ���� �� (2����Ʈ ���)
/// </summary>
/// <param name="_x">x ���� ��ġ</param>
/// <param name="_y">y ���� ��ġ</param>
/// <param name="_Width">���� ���� / 2</param>
/// <param name="_Height">���� ���� == ���� ����</param>
void Scene::MakeBorder(float _x, float _y, float _Width, float _Height)
{
	// �ֻ�/���ϴ� ��
	for (int i = 0; i < _Width; ++i)
		for (int j = 0; j < 2; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + i * 2, _y + ((_Height * 3 + 3) * j), (char*)"##");

	// �����ڸ� ��
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < (_Height * 3 + 2); ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + i * (_Width * 2 - 2), _y + 1 + j, (char*)"##");

	// �߾� ����
	for (int i = 0; i < _Width - 2; ++i)
		for (int j = 0; j < _Height * 3 + 2; ++j)
			CursorManager::GetInstance()->WriteBuffer(_x + (i * 2) + 3, _y + j + 1, (char*)"  ");
}
