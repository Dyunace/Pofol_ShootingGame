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
/// UI용 보드 만들기
/// 가로 길이는 절반 값으로 넣을 것 (2바이트 계산)
/// </summary>
/// <param name="_x">x 시작 위치</param>
/// <param name="_y">y 시작 위치</param>
/// <param name="_Width">가로 길이 / 2</param>
/// <param name="_Height">세로 길이 == 원소 갯수</param>
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
			CursorManager::GetInstance()->WriteBuffer(_x + (i * 2) + 3, _y + j + 1, (char*)"  ");
}
