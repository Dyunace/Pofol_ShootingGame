#include "BackGround.h"
#include "CursorManager.h"
#include "BGIcon.h"

BackGround* BackGround::Instance = nullptr;
BackGround::BackGround(){}
BackGround::~BackGround(){}

void BackGround::Initialize()
{
	for (int i = 0; i < rand() % 20 + 20; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		BGIcon* Icon = new BGIcon;
		Icon->setIcon(1, rand() % 2);

		srand(DWORD(GetTickCount64() * (i + 1)));
		float Width = rand() % ConsoleWidthSize;
		float Height = rand() % ConsoleHeightSize;
		Icon->SetPosition(Width, Height);

		BGIconList.push_back(Icon);
	}
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
