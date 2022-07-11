#include "BGIcon.h"
#include "CursorManager.h"

BGIcon::BGIcon() : MyBuffer(nullptr), MoveCount(0) {}
BGIcon::~BGIcon() { Release(); }

/// <summary>
/// �� ������ ���ϱ� �Լ�
/// </summary>
/// <param name="_type">���� ũ��</param>
/// <param name="_rand">���� ����</param>
/// <returns></returns>
void BGIcon::setIcon(const int _rand)
{
	switch (_rand)
	{
	case 0:
		MyBuffer = (char*)"��";
		break;
	case 1:
		MyBuffer = (char*)"��";
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

	// ī��Ʈ�� ������ ������ ���� �� ĭ�� ������
	if (MoveCount >= 3)
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
	CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x, TransInfo.Position.y, MyBuffer, 8);
}

void BGIcon::Release()
{
	delete MyBuffer;
	MyBuffer = nullptr;
}
