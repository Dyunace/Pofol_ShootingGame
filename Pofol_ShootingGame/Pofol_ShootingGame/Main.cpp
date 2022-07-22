// Shooting v1.11.1 EnemyMovement
/*
	주요 변경점:
		Stage 하위 클래스 생성 및 반복 함수 작성

		EnemyMovement 클래스 삭제
		Movement 함수는 EnemyBridge에서 관리

		Enemy의 이동에 필요한 변수들 작성
		Stage에서 EnemyMovement 테스트 완료


	기타 변경점:
		Map 정렬 순서 정리 해결
		EnemyBullet이 화면 최상단에 렌더링되도록 변경

	다음 할 일:
		본격적으로 EnemySetting하기
		Enemy 종류 늘리기
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