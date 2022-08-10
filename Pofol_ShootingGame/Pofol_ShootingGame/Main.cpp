// Shooting v1.13.5 End Phase
/*
	주요 변경점:
		UserInterface 변경

		게임 중 ESC로 Pause 사용 가능

		WeaponSelect Privew 코드 변경
			제대로 삭제되지 않던 버그 해결

		Gameover 시 게임이 멈추던 버그 해결

		PauseMenu 작성 중

	다음 할 일 (우선 순위 순서) :
		ESC 메뉴
			퍼즈 메뉴는 게임 재개, 메인메뉴로 돌아가기를 선택 가능하다.
		
		게임 오버
			캐릭터의 생명이 모두 소진한 상태에서 피격 당하면 실행
			오브젝트 매니저에 퍼즈를 걸고 GameOver 문구를 띄운다.
			키 입력 텍스트를 출력하고, 입력 시 메뉴 화면으로 이동한다.

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