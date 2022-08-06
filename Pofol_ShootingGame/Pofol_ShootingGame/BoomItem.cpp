#include "BoomItem.h"
#include "Object.h"
#include "CursorManager.h"

BoomItem::BoomItem()
{
	for (int i = 0; i < 5; ++i)
		Buffer[i] = nullptr;
}
BoomItem::~BoomItem(){}

void BoomItem::Initialize()
{
	Buffer[0] = (char*)"┏";
	Buffer[1] = (char*)"┓";
	Buffer[2] = (char*)"┗";
	Buffer[3] = (char*)"┛";
	Buffer[4] = (char*)"♠";

	SetMoveVector();
}

int BoomItem::Update()
{
	// 이동 방향 체크
	VectorCheck(pObject->GetPosition(), MoveVector);

	pObject->SetPosition(
		pObject->GetPosition().x + MoveVector.x,
		pObject->GetPosition().y + MoveVector.y
	);

    return 0;
}

void BoomItem::Render()
{
	for (int y = 0; y < 2; ++y)
	{
		for (int x = 0; x < 2; ++x)
		{
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - 2 + (x * 4),
				pObject->GetPosition().y - 1 + (y * 2),
				Buffer[x + y * 2]);
		}

		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			Buffer[4]);
	}
}

void BoomItem::Release()
{
}
