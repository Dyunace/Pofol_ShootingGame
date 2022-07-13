// Shooting v1.6.0 Bullet + ObjManager + ObjectPool
// 다음 할 일 : 레이저 무기 만들고 테스트하기 + (임시)메뉴에서 UInst에 값 넣고 Stage에서 넘겨받기
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