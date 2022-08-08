// Shooting v1.13.2 End Phase
/*
	주요 변경점:
		게임 끝나고 연출
			연출이라고 하기엔 좀 뭐하지만...
			스테이지 클리어시 클리어 문구 띄우기
			남은 생명과 폭탄에 따라 보너스 점수 문구 띄우기
			정산 종료 후 진행 키를 눌러 메뉴로 나가기

		점수 정산
			공격 시, 적 처치 시, 아이템 획득 시, 게임 끝나고
			각각의 점수를 얻도록 변경

			CursorManager에서 4자리수 이상을 표현 못하기 때문에
			각 자릿수를 하나씩 띄우기

			점수는 2개의 변수를 이용해 점차적으로 상승

	다음 할 일 (우선 순위 순서) :
		플레이어 피격 구현
			1. 맞으면 즉시 플레이어 캐릭터 처치 (unVisible로 잠시 숨기는게 확실함)
				ㄴ unVisible 동안 행동 조작 불능
			2. 잠시 후 UserInstance에서 Life 차감시키고 화면 중앙에 깜빡이며 부활

		스테이지 웨이브 늘리기
			한 10웨이브 정도는 있어야 하지 않나?

		UI 화면에 알잘딱하게 꾸미기

	기타 할 일 :
		다음 웨이브로 넘어갈 때까지 필요한 타이머 증가
			폭탄 깔고 웨이브를 처리하자마자 다음 웨이브까지 박살나버림.

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