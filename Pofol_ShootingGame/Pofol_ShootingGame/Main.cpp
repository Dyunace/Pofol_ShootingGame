// Shooting v1.13.4 End Phase
/*
	�ֿ� ������:
		UserInterface ����

		���� �� ESC�� Pause ��� ����

	���� �� �� (�켱 ���� ����) :

		�������� ���̺� �ø���
			�� 10���̺� ������ �־�� ���� �ʳ�?
			���� ���̺�� �Ѿ ������ �ʿ��� Ÿ�̸� ����
				��ź ��� ���̺긦 ó�����ڸ��� ���� ���̺���� �ڻ쳪����.

		ESC �޴�
			���� �޴��� ���� �簳, ���θ޴��� ���ư��⸦ ���� �����ϴ�.

		���� ����
			ĳ������ ������ ��� ������ ���¿��� �ǰ� ���ϸ� ����
			������Ʈ �Ŵ����� ��� �ɰ� GameOver ������ ����.
			Ű �Է� �ؽ�Ʈ�� ����ϰ�, �Է� �� �޴� ȭ������ �̵��Ѵ�.

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