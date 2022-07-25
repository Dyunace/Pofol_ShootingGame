// Shooting v1.11.3 EnemyMovement
/*
	주요 변경점:
		SmallEnemy 생성
			1. SmallEnemy는 Player의 x축을 기준으로 Direction만큼 x축 이동함.
			2. Y축 이동은 자신의 MoveSpeed만큼 이동함.
			3. 이동 방식은 아래의 가변 패턴을 사용

		EnemyMovement 행동 가변 Type 만들기
			1. Movement에 가변형 Type을 위한 case를 만든다.
			2. Movement에서 MoveCount를 확인하고, 일정 틱이 지나면 다음 Type으로 바꾼다.
			3. Stage에서는 초기 설정으로 가변 Type을 설정한다.


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