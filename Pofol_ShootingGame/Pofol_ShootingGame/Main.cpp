// Shooting v1.8.0 UserInstance
/*
	변경점:
		LaserBullet 완성
		UserInstnace 작성 : 스테이지 유저 정보를 생성 및 초기화
		Menu에서 탄종 정보 업로드, Stage에서 다운로드 기능 작성 및 테스트 완료

	다음 할 일:
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