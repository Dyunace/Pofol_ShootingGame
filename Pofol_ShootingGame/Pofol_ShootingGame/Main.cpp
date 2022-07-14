// Shooting v1.7.1 Bullet + StageTest + CollisionTest
// 다음 할 일 : 레이저 탄 만들기 + 프리뷰 && 로딩화면 만들지 말 지 정하기(보여주기 식이라 상관없음)
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title 이승우 - 슈팅게임");

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