// Shooting v1.13.3 End Phase
/*
	주요 변경점:
		플레이어 피격 구현
			1. 체력이 1초과일 때 다음 실행
			
			2. 폭탄, 총알 레벨 초기화. (탄종은 유지)
			3. 폭탄 아이템 드랍, 총알 레벨이 2 이상일 때 총알 아이템 드랍
			4. 총알 삭제 및 플레이어 isVisible = false

			5. 잠시 후, 플레이어 위치 옮기고 isVisible = true
			6. 무적 타이머 동안 플레이어 깜빡거리고 조작 가능

		스테이지 벗어날 시 다른 객체 모두 Release

	다음 할 일 (우선 순위 순서) :

		스테이지 웨이브 늘리기
			한 10웨이브 정도는 있어야 하지 않나?
			다음 웨이브로 넘어갈 때까지 필요한 타이머 증가
				폭탄 깔고 웨이브를 처리하자마자 다음 웨이브까지 박살나버림.

		UI 화면에 알잘딱하게 꾸미기

		연출하기
			1. 게임 오버
				캐릭터는 isVisible = false 상태
				화면에 Game Over 표시
				키를 눌러 메뉴로 나가기

			2. ESC 메뉴
				메뉴를 눌러 Pause 메뉴를 열고 나머지 조작을 멈춤

				Stage에서 실행되는 모든 Update는 bool isPuase == false 의 체크를 받는다.
				ESC를 누르면 isPuase가 true가 되고, 퍼즈 메뉴가 열린다.

				퍼즈 메뉴는 게임 재개, 메인메뉴로 돌아가기를 선택 가능하다.

	기타 할 일 :

		BufferCheck 위치 옮기기?
			현재 ObjectPool에서 각 객체를 참조하고, 각 객체 내부에서 자신의 Pos값으로 반환하며 삭제.
			이게 삭제가 느려지는 원인이 될 수도 있다.
			마지막에 구현할 기능 중 하나.
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