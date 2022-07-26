// Shooting v1.12.0 Stage & Enemy
/*
	주요 변경점:
		BigEnemy 추가
		MakeEnemyBullet 생성 방식 개선
			자료 조사 정보를 기반으로 약간 개선
			1. 소형 적은 1탄을 쓴다.
			2. 중형 적은 2탄을 쓴다.
			3. 대형 적은 3탄을 쓴다.

		PlayerBullet 변경, Enemy Hp 변경
		StageCheck에서 소형, 대형 적을 인식하도록 변경

	다음 할 일:
		DamageManager를 만들어서 데미지 관리를 따로 할 것
		적 피격 시 깜빡임 이펙트 추가할 것
		BossEnemy 만들 것

		이동 패턴 만들기
			소형
				1. 출현 시점부터 한 방향으로 이동 (소형)
			중형
				1. 출현 후 스테이지에 머무르다 밖으로 빠져나가기 (중형)
			대형
				1. 출현 후, 좌 우로 반복 이동하기 (대형, 단일)
				2. 출현 후, 제자리 고정 (대형, 다수)

			4. 이동 함수에서 목표 지점을 설정하고 그 위치로 이동할 것 (직선 이동용)



	자료 조사 (1945):
		일단 탄이 많이 나온다.
			1. 한 번에 두 발 쏘는 경우도 있고, 연사를 하는 경우도 있다.
			2. 보스 패턴에서는 정해진 방향으로 나가는 작은 산탄들이 있다.
			3. 기본 탄은 플레이어를 향해 쏘고, 산탄이 나갈 경우 일정 각도로 퍼져 나간다.
			4. 적들이 피격 시 깜빡임 연출이 나온다. (중요) -> 데미지 매니저를 만들어서 관리할 것
			5. 소형 적은 정해진 루트로만 빠르게 지나간다. -> 플레이어 유도는 쓰지 않아도 될 것 같다.
			6. 중형 적 또한 정해진 루트로 이동하고 빠지며, 그 동안만 탄을 쏜다.
			7. 대형 적이 자주 등장하며, 화면에 남아서 공격한다. 이 경우 산탄을 쏜다.

		속도감이 빠르다. 이 쪽은 데모용이기 때문에 좀 느린 템포로 갈 것이다.
		맵 구성에 대형 적과 중형 적을 자주 배치한다.
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