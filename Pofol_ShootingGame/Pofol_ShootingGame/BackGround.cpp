#include "BackGround.h"
#include "CursorManager.h"
#include "BGIcon.h"

BackGround* BackGround::Instance = nullptr;
BackGround::BackGround() : MaxIcon(0), MinIcon(0) {}
BackGround::~BackGround(){}

void BackGround::Initialize()
{
	// ���� �� ������ ���� ����
	// ��밪 = (Min ~ Max) * 9
	MaxIcon = 3;
	MinIcon = 3;

	// ��� �׸���
	MakeBG();
}

void BackGround::Update()
{
	for (auto iter = BGIconList.begin(); iter != BGIconList.end(); ++iter)
		(*iter)->Update();
}

void BackGround::Render()
{
	for (auto iter = BGIconList.begin(); iter != BGIconList.end(); ++iter)
		(*iter)->Render();
}

void BackGround::Release()
{
}

void BackGround::MakeBG()
{
	for (int x = 0; x < 3; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int i = 0; i < rand() % MaxIcon + MinIcon; ++i)
			{
				srand(DWORD(GetTickCount64() * (i + 1) + (x + 1) + ((y + 1) * 3)));

				// ������ �����
				BGIcon* Icon = new BGIcon;
				Icon->setIcon(rand() % 2);

				// ������ ��ġ ���ϱ�
				float Width = (float)((rand() % ConsoleWidthSize / 3) + (ConsoleWidthSize / 3 * x));
				float Height = (float)((rand() % ConsoleHeightSize / 3) + (ConsoleHeightSize / 3 * y));

				Icon->SetPosition(Width, Height);
				BGIconList.push_back(Icon);
			}
		}
	}
}
