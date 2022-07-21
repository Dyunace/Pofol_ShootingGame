// Shooting v1.10.0 EnemyBullet + Damage
/*
	주요 변경점:
		EnemyBulletBridge, ENormalBullet 추가 (이하 EnemyBullet)

		Enemy가 일정 주기마다 EnemyBullet을 Player를 향해 발사하도록 수정
		EnemyBullet이 Player와 충돌 시 히트 판정 구현

		PlayerBullet의 데미지 및 Enemy의 체력 추가 및 데미지 계산 구현

		LaserBullet이 공격할 때 Enemy가 겹쳐진 픽셀마다 데미지가 들어가는 버그 수정
			Stage에서 충돌 계산 시 Player의 Bullet이 Laser일 경우에 계산

	기타 변경점:
		Bullet의 BufferOver체크 범위 조정

		EnemyBullet과 PlayerBullet의 충돌 계산 분리
			더 이상 자기 자신을 때리지 않음
		
		PlayerDelayCount 계산 방식 개선
		
		LaserBullet 발사 위치 조정

	다음 할 일:
		Enemy Movement 구현하기 : 우선은 간단한 것부터
			1. 위에서 아래로 내려가기
			2. 아래로 이동 후 정지
			3. 왼쪽 또는 오른쪽으로 이동하기 + (밖으로 탈출 or 반복)
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