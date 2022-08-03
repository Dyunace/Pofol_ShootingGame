// Shooting v1.12.3 Stage & Enemy
/*
	�ֿ� ������:
		Stage1Boss �߰�
			���� �ھ�, �Ӹ�, ��, �尩���� �̷����
			�� 2������� ����
				1������� �ھ ������ ���� �ı� ����
				2������� �ھ� ����

		DamageCheck �Լ� ����
			���� CollisionCheck�� �ִ� ����� �и�

		BossDamageCheck �Լ� ����
			������ ������ ������ �� ������ ����� �ٸ��� ������ ������������ ���� ����

		BigEnemy �̹��� ����
			1945 ���� �� �̹��� ����. ���ΰ� ���� �ﰢ�� ������ ��

	���� �� ��:
		�������� ���̺� �ø���
		���� �Ѿ� �����ϱ�
			��: 2ź
			�Ӹ� : 3ź
			�尩 : 1ź
			�ھ� : Ư��ź (�̹����� �� ���)

		��ź ��� ����
		�÷��̾� �ǰ� ����

		UI ȭ�鿡 ����
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