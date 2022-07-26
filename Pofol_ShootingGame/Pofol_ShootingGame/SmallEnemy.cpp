#include "SmallEnemy.h"
#include "CursorManager.h"
#include "BulletManager.h"
#include "Object.h"

SmallEnemy::SmallEnemy() : Buffer() {}
SmallEnemy::~SmallEnemy(){}

void SmallEnemy::Initialize()
{
    Buffer[0] = (char*)"��";
    Buffer[1] = (char*)"��";

	Hp = 10;
	MoveSpeed = 0.5f;
	BulletType = 1;
}

int SmallEnemy::Update()
{
	Movement();

	if (ShootDelay < 0)
		ShootBullet();

	--ShootDelay;

	if (BufferCheck())
		return BUFFER_OVER;

    return 0;
}

void SmallEnemy::Render()
{
	for (int i = 0; i < 2; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + (i % 2),
			Buffer[i]
		);

	// ü�� ǥ��
	CursorManager::GetInstance()->WriteBuffer
	(pObject->GetPosition().x, pObject->GetPosition().y - 1, GetHP());

	// �̵� Ÿ�� ǥ��
	CursorManager::GetInstance()->WriteBuffer
	(pObject->GetPosition().x, pObject->GetPosition().y - 2, GetMoveType());
}

void SmallEnemy::Release()
{
}

void SmallEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(BulletType, pObject->GetPosition());

	ShootDelay = 10;
}