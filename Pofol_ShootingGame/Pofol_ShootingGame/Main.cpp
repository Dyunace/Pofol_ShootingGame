// Shooting v1.12.6 Stage & Enemy
/*
	�ֿ� ������:
		BulletDamage ��� �� ���� �� �� ü�� ����

		���� �Ѿ� �����ϱ�
			��: 2ź
			�Ӹ� : 3ź
			�尩 : 1ź

		Boom ��� �� ȭ�� �� ��ü �� �Ѿ� ����
		
		EnemyBullet �߻� ���� ����
			���̵� ����

		����� ������ ����

		WaveCheck �� ���� �ذ�
			Check�Ϸ��� EnemyList�� nullptr �˻縦 ���� ���� ���� ����
			int WaveCount�� ����� nullptr�� �� 1 ���ϱ�, �̿ܿ��� size�� 0�϶� 1 ���ϱ�� �� 3�� �Ǹ� ���

	���� �� ��:
		���� �Ѿ� �����ϱ�
			�ھ� : Ư��ź (�̹����� �� ���)

		�������� ���̺� �ø���

		UserInsetance���� ��ź ������Ű�� �� ��ź�� ���Ҵ��� üũ

		���� ��ü (�Ǵ� �Ŀ���) ������ �����
			���� ���͸� ������ ����� ��
			���̺� �� �ϳ� �����Ű��
			�̹����� �밢 ���� �׵θ��� ����� źȯ �̹���

		UI ȭ�鿡 ����

		BufferCheck ��ġ �ű��?
			���� ObjectPool���� �� ��ü�� �����ϰ�, �� ��ü ���ο��� �ڽ��� Pos������ ��ȯ�ϸ� ����.
			�̰� ������ �������� ������ �� ���� �ִ�.
			�������� ������ ��� �� �ϳ�.

		�÷��̾� �ǰ� ����
			1. ������ ��� �÷��̾� ĳ���� óġ (unVisible�� ��� ����°� Ȯ����)
				�� unVisible ���� �ൿ ���� �Ҵ�
			2. ��� �� UserInstance���� Life ������Ű�� ȭ�� �߾ӿ� �����̸� ��Ȱ
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