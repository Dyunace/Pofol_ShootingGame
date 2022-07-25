// Shooting v1.11.3 EnemyMovement
/*
	�ֿ� ������:
		SmallEnemy ����
			1. SmallEnemy�� Player�� x���� �������� Direction��ŭ x�� �̵���.
			2. Y�� �̵��� �ڽ��� MoveSpeed��ŭ �̵���.
			3. �̵� ����� �Ʒ��� ���� ������ ���

		EnemyMovement �ൿ ���� Type �����
			1. Movement�� ������ Type�� ���� case�� �����.
			2. Movement���� MoveCount�� Ȯ���ϰ�, ���� ƽ�� ������ ���� Type���� �ٲ۴�.
			3. Stage������ �ʱ� �������� ���� Type�� �����Ѵ�.


	���� �� ��:
		���������� EnemySetting�ϱ�
		Enemy ���� �ø���
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