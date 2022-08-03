#include "EnemyBridge.h"

#include "MathManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"

#include "Object.h"

bool EnemyBridge::BufferCheck()
{
	if (pObject->GetPosition().y + 1 >= ConsoleHeightSize - 1 ||
		pObject->GetPosition().x + pObject->GetScale().x * 0.5f >= ConsoleWidthSize ||
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f <= 0 )
		return true;

	return false;
};

void EnemyBridge::Movement(Vector3 _MoveLimit)
{
	float PosX = pObject->GetPosition().x;
	float PosY = pObject->GetPosition().y;

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

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
	case 10:
		if (MoveCount < 30)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;
	case 11:
		if (MoveCount < 60)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;
	case 12:
		if (MoveCount < 90)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;


		// �̵� ����
	case 20:
		// �Ʒ��� �̵� �� �� �� �̵� (�� ����)
		if (pObject->GetPosition().y - _MoveLimit.y < 0)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		else
			this->SetMovement(22);
		break;
	case 21:
		// �Ʒ��� �̵� �� �� �� �̵� (�� ����)
		if (pObject->GetPosition().y - _MoveLimit.y < 0)
			pObject->SetPosition(PosX + MoveSpeed, PosY);
		else
			this->SetMovement(23);
		break;
	case 22:
		// �¿� �̵� (�� ����)
			pObject->SetPosition(PosX + MoveSpeed, PosY);
		if (pObject->GetPosition().x + _MoveLimit.x > ConsoleWidthSize)
			this->SetMovement(23);
		break;
	case 23:
		// �¿� �̵� (�� ����)
			pObject->SetPosition(PosX - MoveSpeed, PosY);
		if (pObject->GetPosition().x - _MoveLimit.x < 0)
			this->SetMovement(22);
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

void EnemyBridge::DebugRender()
{
	// ü�� ǥ��
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y - pObject->GetScale().y * 0.5f - 1,
		GetHP());

	// �̵� Ÿ�� ǥ��
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y - pObject->GetScale().y * 0.5f - 2,
		GetMoveType());
}
