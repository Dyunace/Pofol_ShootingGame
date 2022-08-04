// Shooting v1.12.4 Stage & Enemy
/*
	주요 변경점:
		폭탄 초안 작성
			임시 폭탄, 키 작동 확인
			현재 기능 없음

	다음 할 일:
		보스 리스트 및 데미지 식 다시 작성

		보스 총알 구현하기
			팔: 2탄
			머리 : 3탄
			장갑 : 1탄
			코어 : 특수탄 (이미지는 ＠ 사용)

		플레이어 피격 구현

		스테이지 웨이브 늘리기

		UI 화면에 띄우기

		BufferCheck 위치 옮기기?
			현재 ObjectPool에서 각 객체를 참조하고, 각 객체 내부에서 자신의 Pos값으로 반환하며 삭제.
			이게 삭제가 느려지는 원인이 될 수도 있다.
			마지막에 구현할 기능 중 하나.
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