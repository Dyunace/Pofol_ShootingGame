// Shooting v1.8.1 WeaponSelect
/*
	변경점:
		WeaponSelect 기초 작성 완료
		Priview 작성 완료
			Player 배치 (작동 기능 없음)
			Bullet 생성 및 Priview 전용 BufferOver 체크 함수 작성

	다음 할 일:
		Priview에서 Bullet의 레벨 당 탄막 보여주기
			Bullet의 Level 당 탄막 구현하기
			Bullet의 Target 지정하는 함수 구현하기
				NormalBullet은 수직으로 나가지 않을 것이기 때문에 필요함
		
		Player 에서 추가 Bullet을 만들어낸다면?
			UserInstance에서 BulletLevel을 받아온다.
			BulletLevel에 따라 if문을 통해 추가적으로 탄막을 생성한다.

			방향 벡터 Target을 생성한다.	(기존 Framework에서는 Target 좌표를 향해 이동하였다.)
				목표를 향해 이동하는 것이 아닌, 정해진 방향으로 계속 이동할 것이기 때문이다.
				** 적은 플레이어를 향해 발사하기 때문에, 목표 벡터 Target을 사용한다. (Framework와 동일) **
			
			Bullet에는 SetTarget 함수를 만들어, 방향 벡터를 초기화한다.
				Bullet은 Target 벡터값만큼 이동 하며, BufferOver 체크를 한다.

		Target 방향 벡터 정하는 법
			Default (수직)
				x, y += 1
			Additional NormalBullet 
				Lv.2
					x +-= 0.5, y += 1
				Lv.3
					x +-= 1, y += 1
*/
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title LSW - ");

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