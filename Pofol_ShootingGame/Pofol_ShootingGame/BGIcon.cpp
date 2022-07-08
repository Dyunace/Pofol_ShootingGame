#include "BGIcon.h"
#include "CursorManager.h"

BGIcon::BGIcon() : MyBuffer(nullptr), MoveCount(0) {}
BGIcon::~BGIcon() { Release(); }

/// <summary>
/// 별 아이콘 정하기 함수
/// </summary>
/// <param name="_type">별의 크기</param>
/// <param name="_rand">별의 형태</param>
/// <returns></returns>
void BGIcon::setIcon(const int _type, const int _rand)
{
	switch (_type)
	{
	case 1:
		switch (_type)
		{
		case 1:
			MyBuffer = (char*)"∴";
			break;
		case 2:
			MyBuffer = (char*)"∵";
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (_type)
		{
		case 1:
			MyBuffer = (char*)"ο";
			break;
		case 2:
			MyBuffer = (char*)"⊙";
			break;
		case 3:
			MyBuffer = (char*)"σ";
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	MoveCount = 0;
}

void BGIcon::SetPosition(float _x, float _y)
{
	TransInfo.Position.x = _x;
	TransInfo.Position.y = _y;
}

void BGIcon::SetPosition(Vector3 _Pos)
{
	TransInfo.Position = _Pos;
}

void BGIcon::Update()
{
	++MoveCount;

	if (MoveCount >= 1)
	{
		TransInfo.Position.y += 1;
		MoveCount = 0;
	}

	if (TransInfo.Position.y == ConsoleHeightSize)
	{
		TransInfo.Position.y = 0;
	}
}

void BGIcon::Render()
{
	CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x, TransInfo.Position.y, MyBuffer);
}

void BGIcon::Release()
{
	delete MyBuffer;
	MyBuffer = nullptr;
}
