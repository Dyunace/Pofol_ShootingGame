// Shooting v1.9.2 WeaponSelect
/*
	������:
		WeaponSelect�� �� ���� ���� ����
		WeaponSelect���� Stage�� �Ѿ��
		WeaponSelect���� Stage�� ���� ���� �Ѱ��ֱ�

		LaserBullet �߻� ��� ����
		
	���� �� ��:
		�� �߰� ����
		�� �Ѿ� �߻�
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