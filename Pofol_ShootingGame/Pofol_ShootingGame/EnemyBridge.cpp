#include "EnemyBridge.h"

#include "MathManager.h"
#include "ObjectManager.h"

#include "Object.h"

bool EnemyBridge::BufferCheck()
{
	if (pObject->GetPosition().y <= 0 || pObject->GetPosition().y + pObject->GetScale().y >= ConsoleHeightSize - 1 ||
		pObject->GetPosition().x <= 0 || pObject->GetPosition().x + pObject->GetScale().x >= ConsoleWidthSize - 1)
		return true;

	return false;
};

void EnemyBridge::Movement()
{
	float PosX = pObject->GetPosition().x;
	float PosY = pObject->GetPosition().y;

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	// ���� �� ���� �ð��� ������ ���� ����
	if (MoveCount > 1000)
		MoveType = 99;

	switch (MoveType)
	{
		// �⺻ �̵�
	case 0:
		// ����
		break;
	case 1:
		// �Ʒ��� �� �̵�
		pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;
	case 2:
		// �÷��̾ ���� �̵�
		pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), pPlayer->GetPosition()));
		pObject->SetPosition(PosX + pObject->GetDirection().x, PosY + MoveSpeed);
		break;
	case 3:
		// �Ʒ��� �̵� �� �÷��̾ ���� �̵� (SmallEnemy)
		pObject->SetPosition(PosX, PosY + MoveSpeed);
		if (MoveCount == 15)
			this->SetMovement(2);
		break;

		// �Ʒ��� �̵� �� ����
	case 11:
		if (MoveCount < 30)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;
	case 12:
		if (MoveCount < 60)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;
	case 13:
		if (MoveCount < 90)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;



	case 99:
		// ������ ����
		if (PosX < 40)
			pObject->SetPosition(PosX - MoveSpeed, PosY);
		else if (PosX >= 40)
			pObject->SetPosition(PosX + MoveSpeed, PosY);
		break;
	default:
		break;
	}

	++(this->MoveCount);
}