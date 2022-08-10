// Shooting v1.13.6 End Phase
/*
	주요 변경점:
		Pause Menu
			메인 메뉴로 돌아가기, 계속하기 선택지 구현

		Game Over
			게임 오버 시 텍스트 띄우기
			메인 메뉴로 나가기 기능 구현

		UserInstance
			WeaponSelect 진입 시 디폴트값으로 초기화 추가

	다음 할 일 (우선 순위 순서) :
		스테이지 웨이브 늘리기
			한 10웨이브 정도는 있어야 하지 않나?
			다음 웨이브로 넘어갈 때까지 필요한 타이머 증가
				폭탄 깔고 웨이브를 처리하자마자 다음 웨이브까지 박살나버림.
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