// Shooting v1.12.2 Stage & Enemy
/*
	주요 변경점:
		Stage에서 사용할 StageWave, StageCount 변수 생성
			StageCount는 Scene에 있던 SceneCount를 가져옴
			Wave가 시작되면 StageCount가 증가하면서 Enemy 생성
			해당 웨이브의 마지막 Enemy가 생성되고 모든 적이 화면에서 사라지면 Wave 진행 및 StageCount 초기화

		MakeEnemy 함수로 적 생성 코드 간략화
			매개변수를 EnemyType, Position, MoveType으로 간략화

		Enemy의 BufferCheck 에서 Y 0 에 삭제되지 않도록 변경
			적들은 Y 0 부터 등장할 예정

		Enemy 생성 시 y축에 따른 이미지 출력이 깨지지 않도록 변경
			y축이 0과 같거나 작을 경우, Enemy 자신의 Buffer를 일부만 출력
			y축 출력 값 조정 (소수점을 계산하지 않는 식으로 변경)

	다음 할 일:
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