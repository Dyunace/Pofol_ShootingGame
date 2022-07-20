// Shooting v1.9.2 WeaponSelect
/*
	변경점:
		WeaponSelect에 각 무기 설명 쓰기
		WeaponSelect에서 Stage로 넘어가기
		WeaponSelect에서 Stage로 무기 정보 넘겨주기

		LaserBullet 발사 방식 개선
		
	다음 할 일:
		적 추가 구현
		적 총알 발사
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