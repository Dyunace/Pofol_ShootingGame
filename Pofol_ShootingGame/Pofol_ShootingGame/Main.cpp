// Shooting v1.12.6 Stage & Enemy
/*
	주요 변경점:
		BulletDamage 계산 식 변경 및 적 체력 변경

		보스 총알 구현하기
			팔: 2탄
			머리 : 3탄
			장갑 : 1탄

		Boom 사용 시 화면 내 전체 적 총알 삭제
		
		EnemyBullet 발사 각도 조정
			난이도 하향

		디버그 렌더링 해제

		WaveCheck 시 오류 해결
			Check하려는 EnemyList의 nullptr 검사를 하지 않은 것이 원인
			int WaveCount를 만들고 nullptr일 때 1 더하기, 이외에는 size가 0일때 1 더하기로 합 3이 되면 통과

	다음 할 일:
		보스 총알 구현하기
			코어 : 특수탄 (이미지는 ＠ 사용)

		스테이지 웨이브 늘리기

		UserInsetance에서 폭탄 차감시키기 및 폭탄이 남았는지 체크

		무기 교체 (또는 파워업) 아이템 만들기
			대형 몬스터를 잡으면 드랍될 것
			웨이브 당 하나 드랍시키기
			이미지는 대각 방향 테두리에 가운데에 탄환 이미지

		UI 화면에 띄우기

		BufferCheck 위치 옮기기?
			현재 ObjectPool에서 각 객체를 참조하고, 각 객체 내부에서 자신의 Pos값으로 반환하며 삭제.
			이게 삭제가 느려지는 원인이 될 수도 있다.
			마지막에 구현할 기능 중 하나.

		플레이어 피격 구현
			1. 맞으면 즉시 플레이어 캐릭터 처치 (unVisible로 잠시 숨기는게 확실함)
				ㄴ unVisible 동안 행동 조작 불능
			2. 잠시 후 UserInstance에서 Life 차감시키고 화면 중앙에 깜빡이며 부활
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