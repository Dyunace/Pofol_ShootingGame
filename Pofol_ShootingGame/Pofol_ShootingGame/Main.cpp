// Shooting v1.13.3 End Phase
/*
	�ֿ� ������:
		�÷��̾� �ǰ� ����
			1. ü���� 1�ʰ��� �� ���� ����
			
			2. ��ź, �Ѿ� ���� �ʱ�ȭ. (ź���� ����)
			3. ��ź ������ ���, �Ѿ� ������ 2 �̻��� �� �Ѿ� ������ ���
			4. �Ѿ� ���� �� �÷��̾� isVisible = false

			5. ��� ��, �÷��̾� ��ġ �ű�� isVisible = true
			6. ���� Ÿ�̸� ���� �÷��̾� �����Ÿ��� ���� ����

		�������� ��� �� �ٸ� ��ü ��� Release

	���� �� �� (�켱 ���� ����) :

		�������� ���̺� �ø���
			�� 10���̺� ������ �־�� ���� �ʳ�?
			���� ���̺�� �Ѿ ������ �ʿ��� Ÿ�̸� ����
				��ź ��� ���̺긦 ó�����ڸ��� ���� ���̺���� �ڻ쳪����.

		UI ȭ�鿡 ���ߵ��ϰ� �ٹ̱�

		�����ϱ�
			1. ���� ����
				ĳ���ʹ� isVisible = false ����
				ȭ�鿡 Game Over ǥ��
				Ű�� ���� �޴��� ������

			2. ESC �޴�
				�޴��� ���� Pause �޴��� ���� ������ ������ ����

				Stage���� ����Ǵ� ��� Update�� bool isPuase == false �� üũ�� �޴´�.
				ESC�� ������ isPuase�� true�� �ǰ�, ���� �޴��� ������.

				���� �޴��� ���� �簳, ���θ޴��� ���ư��⸦ ���� �����ϴ�.

	��Ÿ �� �� :

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