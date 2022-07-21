// Shooting v1.10.0 EnemyBullet + Damage
/*
	�ֿ� ������:
		EnemyBulletBridge, ENormalBullet �߰� (���� EnemyBullet)

		Enemy�� ���� �ֱ⸶�� EnemyBullet�� Player�� ���� �߻��ϵ��� ����
		EnemyBullet�� Player�� �浹 �� ��Ʈ ���� ����

		PlayerBullet�� ������ �� Enemy�� ü�� �߰� �� ������ ��� ����

		LaserBullet�� ������ �� Enemy�� ������ �ȼ����� �������� ���� ���� ����
			Stage���� �浹 ��� �� Player�� Bullet�� Laser�� ��쿡 ���

	��Ÿ ������:
		Bullet�� BufferOverüũ ���� ����

		EnemyBullet�� PlayerBullet�� �浹 ��� �и�
			�� �̻� �ڱ� �ڽ��� ������ ����
		
		PlayerDelayCount ��� ��� ����
		
		LaserBullet �߻� ��ġ ����

	���� �� ��:
		Enemy Movement �����ϱ� : �켱�� ������ �ͺ���
			1. ������ �Ʒ��� ��������
			2. �Ʒ��� �̵� �� ����
			3. ���� �Ǵ� ���������� �̵��ϱ� + (������ Ż�� or �ݺ�)
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