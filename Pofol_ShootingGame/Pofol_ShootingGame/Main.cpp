// Shooting v1.12.4 Stage & Enemy
/*
	�ֿ� ������:
		��ź �ʾ� �ۼ�
			�ӽ� ��ź, Ű �۵� Ȯ��
			���� ��� ����

	���� �� ��:
		���� ����Ʈ �� ������ �� �ٽ� �ۼ�

		���� �Ѿ� �����ϱ�
			��: 2ź
			�Ӹ� : 3ź
			�尩 : 1ź
			�ھ� : Ư��ź (�̹����� �� ���)

		�÷��̾� �ǰ� ����

		�������� ���̺� �ø���

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