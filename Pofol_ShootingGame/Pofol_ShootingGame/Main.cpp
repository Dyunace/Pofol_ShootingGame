// Shooting v1.8.1 WeaponSelect
/*
	������:
		WeaponSelect ���� �ۼ� �Ϸ�
		Priview �ۼ� �Ϸ�
			Player ��ġ (�۵� ��� ����)
			Bullet ���� �� Priview ���� BufferOver üũ �Լ� �ۼ�

	���� �� ��:
		Priview���� Bullet�� ���� �� ź�� �����ֱ�
			Bullet�� Level �� ź�� �����ϱ�
			Bullet�� Target �����ϴ� �Լ� �����ϱ�
				NormalBullet�� �������� ������ ���� ���̱� ������ �ʿ���
		
		Player ���� �߰� Bullet�� �����ٸ�?
			UserInstance���� BulletLevel�� �޾ƿ´�.
			BulletLevel�� ���� if���� ���� �߰������� ź���� �����Ѵ�.

			���� ���� Target�� �����Ѵ�.	(���� Framework������ Target ��ǥ�� ���� �̵��Ͽ���.)
				��ǥ�� ���� �̵��ϴ� ���� �ƴ�, ������ �������� ��� �̵��� ���̱� �����̴�.
				** ���� �÷��̾ ���� �߻��ϱ� ������, ��ǥ ���� Target�� ����Ѵ�. (Framework�� ����) **
			
			Bullet���� SetTarget �Լ��� �����, ���� ���͸� �ʱ�ȭ�Ѵ�.
				Bullet�� Target ���Ͱ���ŭ �̵� �ϸ�, BufferOver üũ�� �Ѵ�.

		Target ���� ���� ���ϴ� ��
			Default (����)
				x, y += 1
			Additional NormalBullet 
				Lv.2
					x +-= 0.5, y += 1
				Lv.3
					x +-= 1, y += 1
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