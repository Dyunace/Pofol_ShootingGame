#include "BackGround.h"
#include "CursorManager.h"
#include "BGIcon.h"

BackGround* BackGround::Instance = nullptr;
BackGround::BackGround(){}
BackGround::~BackGround(){}

void BackGround::Initialize()
{
	// 배경 그리기
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
			for (int i = 0; i < rand() % 5 + 5; ++i)
			{
				srand(DWORD(GetTickCount64() * (i + 1) * (x+1) * (y+1)));

				// 아이콘 만들기
				BGIcon* Icon = new BGIcon;
				Icon->setIcon(rand() % 2);

				// 아이콘 위치 정하기
				float Width = (rand() % ConsoleWidthSize / 3) + (ConsoleWidthSize / 3 * x);
				float Height = (rand() % ConsoleHeightSize / 3) + (ConsoleHeightSize / 3 * y);

				Icon->SetPosition(Width, Height);
				BGIconList.push_back(Icon);
			}
		}
	}
}
