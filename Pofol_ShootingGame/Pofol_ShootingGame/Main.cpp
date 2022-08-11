// Shooting v1.13.7 End Phase
/*
	주요 변경점:
		사망 애니메이션 출력

		폭탄 애니메이션 출력

		스테이지 웨이브 추가

	다음 할 일 (우선 순위 순서) :
*/
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title LSW - Shoot Star");

	system("mode con cols=80 lines=60");

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