// Shooting v1.13.6 End Phase
/*
	�ֿ� ������:
		Pause Menu
			���� �޴��� ���ư���, ����ϱ� ������ ����

		Game Over
			���� ���� �� �ؽ�Ʈ ����
			���� �޴��� ������ ��� ����

		UserInstance
			WeaponSelect ���� �� ����Ʈ������ �ʱ�ȭ �߰�

	���� �� �� (�켱 ���� ����) :
		�������� ���̺� �ø���
			�� 10���̺� ������ �־�� ���� �ʳ�?
			���� ���̺�� �Ѿ ������ �ʿ��� Ÿ�̸� ����
				��ź ��� ���̺긦 ó�����ڸ��� ���� ���̺���� �ڻ쳪����.
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