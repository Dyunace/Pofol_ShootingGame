// Shooting v1.8.0 UserInstance
/*
	������:
		LaserBullet �ϼ�
		UserInstnace �ۼ� : �������� ���� ������ ���� �� �ʱ�ȭ
		Menu���� ź�� ���� ���ε�, Stage���� �ٿ�ε� ��� �ۼ� �� �׽�Ʈ �Ϸ�

	���� �� ��:
*/
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title LSW - ");

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