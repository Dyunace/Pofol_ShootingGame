// Shooting v1.13.0 End Phase
/*
	�ֿ� ������:
		������ ��� ���� (��ź)
			�� ���̺� �� 1��, ���� �� óġ �� ���
			������ �������� 1�� �̵��ӵ��� �̵�
			���� ���� �ٴٸ� ���, ��ġ�� ���� �̵� ���� -1�� ����

		��ź ��� �߰�
			��ź�� 0���� �� �߻� �Ұ���
			��ź�� �߻� �� �� 1���� ����

		��ź ������ �߰�
			ȹ�� �� ��ź 1�� �߰�

		���� ���׷��̵� ������ ��� �߰�
			ȹ�� �� ���� ���� ��� �Ǵ� ���� ����

		�������� ��� �� ����
			for�� �ߺ� �ڵ� ���� �� ����ȭ

	���� �� �� (�켱 ���� ����) :

		���� �Ѿ� �����ϱ�
			�ھ� : Ư��ź (�̹����� �� ���)

		�������� ���̺� �ø���

		UI ȭ�鿡 ���ߵ��ϰ� �ٹ̱�

		�÷��̾� �ǰ� ����
			1. ������ ��� �÷��̾� ĳ���� óġ (unVisible�� ��� ����°� Ȯ����)
				�� unVisible ���� �ൿ ���� �Ҵ�
			2. ��� �� UserInstance���� Life ������Ű�� ȭ�� �߾ӿ� �����̸� ��Ȱ

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