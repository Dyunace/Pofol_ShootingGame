// Shooting v1.12.2 Stage & Enemy
/*
	�ֿ� ������:
		Stage���� ����� StageWave, StageCount ���� ����
			StageCount�� Scene�� �ִ� SceneCount�� ������
			Wave�� ���۵Ǹ� StageCount�� �����ϸ鼭 Enemy ����
			�ش� ���̺��� ������ Enemy�� �����ǰ� ��� ���� ȭ�鿡�� ������� Wave ���� �� StageCount �ʱ�ȭ

		MakeEnemy �Լ��� �� ���� �ڵ� ����ȭ
			�Ű������� EnemyType, Position, MoveType���� ����ȭ

		Enemy�� BufferCheck ���� Y 0 �� �������� �ʵ��� ����
			������ Y 0 ���� ������ ����

		Enemy ���� �� y�࿡ ���� �̹��� ����� ������ �ʵ��� ����
			y���� 0�� ���ų� ���� ���, Enemy �ڽ��� Buffer�� �Ϻθ� ���
			y�� ��� �� ���� (�Ҽ����� ������� �ʴ� ������ ����)

	���� �� ��:
		BossEnemy ���� ��

		�̵� ���� �����
			����
				1. ���� �������� �� �������� �̵� (����)
			����
				1. ���� �� ���������� �ӹ����� ������ ���������� (����)
			����
				1. ���� ��, �� ��� �ݺ� �̵��ϱ� (����, ����)
				2. ���� ��, ���ڸ� ���� (����, �ټ�)

			4. �̵� �Լ����� ��ǥ ������ �����ϰ� �� ��ġ�� �̵��� �� (���� �̵���)
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