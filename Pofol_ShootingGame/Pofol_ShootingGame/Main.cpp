// Shooting v1.12.5 Stage & Enemy
/*
	�ֿ� ������:
		��ź ����
			DŰ�� �߻�
			�߻� �� 30ƽ ���� �������� �̵�
			���� 60ƽ ���� ȭ�鿡 �����鼭 ȭ�� �� ��ü ������
				1. ��� �Ϲ� ���� �׻� �������� �Դ´�.
				2. ���� ���� BossPhase�� �������� ������ �� ����� �ش��ϴ� �������� �Դ´�.

	���� �� ��:
		���� �Ѿ� �����ϱ�
			��: 2ź
			�Ӹ� : 3ź
			�尩 : 1ź
			�ھ� : Ư��ź (�̹����� �� ���)

		�÷��̾� �ǰ� ����
			1. ������ ��� �÷��̾� ĳ���� óġ (unVisible�� ��� ����°� Ȯ����)
				�� unVisible ���� �ൿ ���� �Ҵ�
			2. ��� �� UserInstance���� Life ������Ű�� ȭ�� �߾ӿ� �����̸� ��Ȱ

		�������� ���̺� �ø���

		UserInsetance���� ��ź ������Ű�� �� ��ź�� ���Ҵ��� üũ

		UI ȭ�鿡 ����

		BufferCheck ��ġ �ű��?
			���� ObjectPool���� �� ��ü�� �����ϰ�, �� ��ü ���ο��� �ڽ��� Pos������ ��ȯ�ϸ� ����.
			�̰� ������ �������� ������ �� ���� �ִ�.
			�������� ������ ��� �� �ϳ�.
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