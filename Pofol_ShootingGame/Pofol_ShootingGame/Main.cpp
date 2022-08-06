// Shooting v1.13.0 End Phase
/*
	주요 변경점:
		아이템 기능 구현 (폭탄)
			각 웨이브 당 1번, 대형 적 처치 시 드랍
			랜덤한 방향으로 1의 이동속도로 이동
			버퍼 끝에 다다를 경우, 위치에 따라 이동 값에 -1을 곱산

		폭탄 기능 추가
			폭탄은 0개일 때 발사 불가능
			폭탄이 발사 될 때 1개씩 차감

		폭탄 아이템 추가
			획득 시 폭탄 1개 추가

		무기 업그레이드 아이템 기능 추가
			획득 시 무기 레벨 상승 또는 무기 변경

		스테이지 계산 식 개선
			for문 중복 코드 제거 및 간결화

	다음 할 일 (우선 순위 순서) :

		보스 총알 구현하기
			코어 : 특수탄 (이미지는 ＠ 사용)

		스테이지 웨이브 늘리기

		UI 화면에 알잘딱하게 꾸미기

		플레이어 피격 구현
			1. 맞으면 즉시 플레이어 캐릭터 처치 (unVisible로 잠시 숨기는게 확실함)
				ㄴ unVisible 동안 행동 조작 불능
			2. 잠시 후 UserInstance에서 Life 차감시키고 화면 중앙에 깜빡이며 부활

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