#include "EnemyBridge.h"

#include "MathManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "BulletManager.h"

#include "Object.h"

void EnemyBridge::ShootBullet(Vector3 _Position)
{
	BulletManager::GetInstance()->MakeEnemyBullet(BulletType, _Position);
}

bool EnemyBridge::BufferCheck()
{
	if (pObject->GetPosition().y + 1 >= ConsoleHeightSize - 7 ||
		pObject->GetPosition().x + pObject->GetScale().x * 0.5f >= ConsoleWidthSize ||
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f <= 0)
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
		// 기본 이동
	case 0:
		// 정지
		break;
	case 1:
		// 아래로 쭉 이동
		pObject->SetPosition(PosX, PosY + MoveSpeed);
		break;
	case 2:
		// 플레이어를 향해 이동
		pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), pPlayer->GetPosition()));
		pObject->SetPosition(PosX + pObject->GetDirection().x, PosY + MoveSpeed);
		break;
	case 3:
		// 아래로 이동 후 플레이어를 향해 이동 (SmallEnemy)
		pObject->SetPosition(PosX, PosY + MoveSpeed);
		if (MoveCount == 15)
			this->SetMovement(2);
		break;

		// 아래로 이동 후 정지
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


		// 이동 연계
	case 20:
		// 아래로 이동 후 좌 우 이동 (우 시작)
		if (pObject->GetPosition().y - _MoveLimit.y < 0)
			pObject->SetPosition(PosX, PosY + MoveSpeed);
		else
			this->SetMovement(22);
		break;
	case 21:
		// 아래로 이동 후 좌 우 이동 (좌 시작)
		if (pObject->GetPosition().y - _MoveLimit.y < 0)
			pObject->SetPosition(PosX + MoveSpeed, PosY);
		else
			this->SetMovement(23);
		break;
	case 22:
		// 좌우 이동 (우 방향)
		pObject->SetPosition(PosX + MoveSpeed, PosY);
		if (pObject->GetPosition().x + _MoveLimit.x > ConsoleWidthSize)
			this->SetMovement(23);
		break;
	case 23:
		// 좌우 이동 (좌 방향)
		pObject->SetPosition(PosX - MoveSpeed, PosY);
		if (pObject->GetPosition().x - _MoveLimit.x < 0)
			this->SetMovement(22);
		break;

	case 99:
		// 옆으로 퇴장
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
	// 체력 표시
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y - pObject->GetScale().y * 0.5f - 1,
		GetHP());

	// 이동 타입 표시
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y - pObject->GetScale().y * 0.5f - 2,
		GetMoveType());
}
