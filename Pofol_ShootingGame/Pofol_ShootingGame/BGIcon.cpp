#include "BGIcon.h"
#include "CursorManager.h"

BGIcon::BGIcon() : MyBuffer(nullptr), MoveCount(0), MoveSpeed(0) {}
BGIcon::~BGIcon() { Release(); }

/// <summary>
/// 별 아이콘 정하기 함수
/// </summary>
/// <param name="_type">별의 크기</param>
/// <param name="_rand">별의 형태</param>
/// <returns></returns>
void BGIcon::setIcon(const int _rand)
{
	switch (_rand)
	{
	case 0:
		MyBuffer = (char*)"∴";
		break;
	case 1:
		MyBuffer = (char*)"∵";
		break;
	default:
		break;
	}

	MoveCount = 0;
	MoveSpeed = ((rand() % 3) / 2 + 0.5f);
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

	// 카운트가 충족될 때마다 별이 한 칸씩 내려감
	if (MoveCount >= 6)
	{
		TransInfo.Position.y += MoveSpeed;
		MoveCount = 0;
	}

	// 별이 화면 맨 아래로 내려가면 최상단으로 다시 올라감
	if (TransInfo.Position.y == ConsoleHeightSize)
	{
		TransInfo.Position.y = 0;

		MoveSpeed = ((rand() % 3) / 2 + 0.5f);
	}
}

void BGIcon::Render()
{
	CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x, TransInfo.Position.y, MyBuffer, 8);
}

void BGIcon::Release()
{
	delete MyBuffer;
	MyBuffer = nullptr;
}
