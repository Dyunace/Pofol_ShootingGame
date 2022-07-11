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
	// 배경 화면에 별 그리기
	// 랜덤으로 화면에 넣으면 한 쪽에 몰리는 현상이 나타날 수 있음
	// 따라서 4개(또는 9개) 구역으로 나눈 뒤, 각 구역에 일정 갯수 이상을 배치하는 것으로 이 현상을 방지할 예정
	// 영역의 시작하는 지점과 끝 지점을 정해야한다.

	for (int i = 0; i < rand() % 20 + 30; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		// 아이콘 만들기
		BGIcon* Icon = new BGIcon;
		Icon->setIcon(rand() % 2);

		// 아이콘 위치 정하기
		float Width = rand() % ConsoleWidthSize;
		float Height = rand() % ConsoleHeightSize;
		Icon->SetPosition(Width, Height);

		BGIconList.push_back(Icon);
	}
}
