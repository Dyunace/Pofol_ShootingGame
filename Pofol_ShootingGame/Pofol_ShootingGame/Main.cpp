// Shooting v1.11.2 EnemyMovement
/*
	주요 변경점:
		UserInterface 클래스 생성
		Scene::MakeBorder 함수 대체 사용

	다음 할 일:
		본격적으로 EnemySetting하기
		Enemy 종류 늘리기
*/
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title LSW - Shoot Star");

	system("mode con cols=80 lines=55");

	auto Time = GetTickCount64();

	MainUpdate main;
	main.Initialize();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			main.Update();
			main.Render();
		}
	}
}