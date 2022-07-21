// Shooting v1.11.0 EnemyMovement
/*
	주요 변경점:
		EnemyMovement 초기 작성

	다음 할 일:
		Enemy에 다음 작성하기
			1. MoveType
			2. MoveCount
			3. 위 2개 Get, Set
		Enemy 생성 시에 할 것

		EnemyMovement 테스트 해보기
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