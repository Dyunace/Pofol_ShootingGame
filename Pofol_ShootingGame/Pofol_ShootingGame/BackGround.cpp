#include "BackGround.h"
#include "CursorManager.h"
#include "BGIcon.h"

BackGround* BackGround::Instance = nullptr;
BackGround::BackGround(){}
BackGround::~BackGround(){}

void BackGround::Initialize()
{
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
	// ��� ȭ�鿡 �� �׸���
	// �������� ȭ�鿡 ������ �� �ʿ� ������ ������ ��Ÿ�� �� ����
	// ���� 4��(�Ǵ� 9��) �������� ���� ��, �� ������ ���� ���� �̻��� ��ġ�ϴ� ������ �� ������ ������ ����
	// ������ �����ϴ� ������ �� ������ ���ؾ��Ѵ�.

	for (int i = 0; i < rand() % 20 + 30; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		// ������ �����
		BGIcon* Icon = new BGIcon;
		Icon->setIcon(rand() % 2);

		// ������ ��ġ ���ϱ�
		float Width = rand() % ConsoleWidthSize;
		float Height = rand() % ConsoleHeightSize;
		Icon->SetPosition(Width, Height);

		BGIconList.push_back(Icon);
	}
}
