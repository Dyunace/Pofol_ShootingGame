// Shooting v1.7.3 Bridge
/*
	������:
		Bullet�� BufferOver�� ������� �ʴ� ���� �ذ�

	���� �� ��:
		�޴����� �Ѿ�� �� �÷��̾� �ν��Ͻ��� ���� �Ѱ��ְ�, ������������ �޾ƿ���
		������ ź �ϼ� �� �߻� �׽�Ʈ
		�÷��̾ ���� ��ü �ý��� �����
		���� ��ü ������ �ۼ� �� ������������ �׽�Ʈ
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