// Shooting v1.9.1 WeaponSelect
/*
	변경점:
		WeaponSelect에서 나갔다 들어오면 Player가 중복 생성되는 문제 해결

		BulletManager 구현, 레벨 별 탄막 생성 및 방향 결정 구현
		레벨 별 탄막은 WeaponSelect에서 확인 가능

		무기 선택 시 Priview에 바뀐 무기 표시되도록 적용

		MakeBorder 함수 교정

	다음 할 일:
		WeaponSelect에 각 무기 설명 쓰기
		WeaponSelect에서 Stage로 넘어가기
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