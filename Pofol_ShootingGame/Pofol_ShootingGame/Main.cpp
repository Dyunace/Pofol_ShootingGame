// Shooting v1.11.0 EnemyMovement
/*
	�ֿ� ������:
		EnemyMovement �ʱ� �ۼ�

	���� �� ��:
		Enemy�� ���� �ۼ��ϱ�
			1. MoveType
			2. MoveCount
			3. �� 2�� Get, Set
		Enemy ���� �ÿ� �� ��

		EnemyMovement �׽�Ʈ �غ���
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