// Shooting v1.11.1 EnemyMovement
/*
	�ֿ� ������:
		Stage ���� Ŭ���� ���� �� �ݺ� �Լ� �ۼ�

		EnemyMovement Ŭ���� ����
		Movement �Լ��� EnemyBridge���� ����

		Enemy�� �̵��� �ʿ��� ������ �ۼ�
		Stage���� EnemyMovement �׽�Ʈ �Ϸ�


	��Ÿ ������:
		Map ���� ���� ���� �ذ�
		EnemyBullet�� ȭ�� �ֻ�ܿ� �������ǵ��� ����

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