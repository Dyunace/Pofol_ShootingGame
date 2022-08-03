// Shooting v1.12.3 Stage & Enemy
/*
	주요 변경점:
		Stage1Boss 추가
			각각 코어, 머리, 팔, 장갑으로 이루어짐
			총 2페이즈로 구성
				1페이즈는 코어를 제외한 부위 파괴 가능
				2페이즈는 코어 전투

		DamageCheck 함수 생성
			기존 CollisionCheck에 있던 기능을 분리

		BossDamageCheck 함수 생성
			각각의 보스는 페이즈 별 데미지 계산이 다르기 때문에 스테이지에서 개별 관리

		BigEnemy 이미지 변경
			1945 대형 적 이미지 차용. 가로가 넓은 삼각형 형태의 적

	다음 할 일:
		스테이지 웨이브 늘리기
		보스 총알 구현하기
			팔: 2탄
			머리 : 3탄
			장갑 : 1탄
			코어 : 특수탄 (이미지는 ＠ 사용)

		폭탄 기능 구현
		플레이어 피격 구현

		UI 화면에 띄우기
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