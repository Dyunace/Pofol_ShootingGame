// Shooting v1.6.0 Bullet + ObjManager + ObjectPool
// ���� �� �� : ������ ���� ����� �׽�Ʈ�ϱ� + (�ӽ�)�޴����� UInst�� �� �ְ� Stage���� �Ѱܹޱ�
#define _CRT_SECLRE_NO_WARNING
#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	system("title �̽¿� - ���ð���");

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