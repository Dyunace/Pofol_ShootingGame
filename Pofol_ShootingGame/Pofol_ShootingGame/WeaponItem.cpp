#include "WeaponItem.h"
#include "Object.h"
#include "UserInstance.h"

WeaponItem::WeaponItem() : ItemCount(0), ItemType(0)
{
	for (int i = 0; i < 5; ++i)
		Buffer[i] = nullptr;
}
WeaponItem::~WeaponItem(){}

void WeaponItem::Initialize()
{
	Buffer[0] = (char*)"┏";
	Buffer[1] = (char*)"┓";
	Buffer[2] = (char*)"┗";
	Buffer[3] = (char*)"┛";
	
	if (UserInstance::GetInstance()->GetBullet() == NORMALBULLET)
	{
		Buffer[4] = (char*)"⊙";
		ItemType = 0;
	}
	else if (UserInstance::GetInstance()->GetBullet() == LASERBULLET)
	{
		Buffer[4] = (char*)"Ⅱ";
		ItemType = 1;
	}

	SetMoveVector();
}

int WeaponItem::Update()
{
	// 이동 방향 체크
	VectorCheck(pObject->GetPosition(), MoveVector);

	pObject->SetPosition(
		pObject->GetPosition().x + MoveVector.x,
		pObject->GetPosition().y + MoveVector.y
	);


	// 아이템 변경
	++ItemCount;
	if (ItemCount == 60)
	{
		++ItemType;

		if (ItemType == 2)
			ItemType = 0;

		if (ItemType == 0)
			Buffer[4] = (char*)"Ⅱ";
		else if (ItemType == 1)
			Buffer[4] = (char*)"⊙";
	}


	return 0;
}

void WeaponItem::Render()
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

void WeaponItem::Release()
{
}
