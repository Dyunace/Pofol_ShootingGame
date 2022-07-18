// Shooting v1.7.3 Bridge
/*
	변경점:
		Bullet이 BufferOver시 사라지지 않던 문제 해결

	다음 할 일:
		메뉴에서 넘어올 때 플레이어 인스턴스에 정보 넘겨주고, 스테이지에서 받아오기
		레이저 탄 완성 후 발사 테스트
		플레이어에 무기 교체 시스템 만들기
		무기 교체 아이템 작성 후 스테이지에서 테스트
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