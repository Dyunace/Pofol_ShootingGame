// Shooting v1.12.5 Stage & Enemy
/*
	주요 변경점:
		폭탄 구현
			D키로 발사
			발사 후 30틱 동안 전방으로 이동
			이후 60틱 동안 화면에 남으면서 화면 내 전체 데미지
				1. 모든 일반 적은 항상 데미지를 입는다.
				2. 보스 적은 BossPhase에 돌입했을 때에만 각 페이즈에 해당하는 데미지만 입는다.

	다음 할 일:
		보스 총알 구현하기
			팔: 2탄
			머리 : 3탄
			장갑 : 1탄
			코어 : 특수탄 (이미지는 ＠ 사용)

		플레이어 피격 구현
			1. 맞으면 즉시 플레이어 캐릭터 처치 (unVisible로 잠시 숨기는게 확실함)
				ㄴ unVisible 동안 행동 조작 불능
			2. 잠시 후 UserInstance에서 Life 차감시키고 화면 중앙에 깜빡이며 부활

		스테이지 웨이브 늘리기

		UserInsetance에서 폭탄 차감시키기 및 폭탄이 남았는지 체크

		UI 화면에 띄우기

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