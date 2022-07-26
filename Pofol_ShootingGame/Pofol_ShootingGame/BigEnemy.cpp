#include "BigEnemy.h"
#include "CursorManager.h"
#include "Object.h"
#include "BulletManager.h"

BigEnemy::BigEnemy() : Buffer() {}
BigEnemy::~BigEnemy(){}

void BigEnemy::Initialize()
{
	Buffer[0] = (char*)"∀";
	Buffer[1] = (char*)"┳";
	Buffer[2] = (char*)"∀";
	Buffer[3] = (char*)"┃";
	Buffer[4] = (char*)"Θ";
	Buffer[5] = (char*)"┃";
	Buffer[6] = (char*)"┣";
	Buffer[7] = (char*)"Π";
	Buffer[8] = (char*)"┫";

	Hp = 50;
	MoveSpeed = 0.25f;
	BulletType = 3;
}

int BigEnemy::Update()
{
	Movement();

	if (ShootDelay < 0)
		ShootBullet();

	--ShootDelay;

	if (BufferCheck())
		return BUFFER_OVER;

	return 0;
}

void BigEnemy::Render()
{
	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 3; ++x)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x + (x % 3 * 2),
				pObject->GetPosition().y + (y % 3),
				Buffer[(x + (y * 3))]
			);

	// 체력 표시
	CursorManager::GetInstance()->WriteBuffer
	(pObject->GetPosition().x, pObject->GetPosition().y - 1, GetHP());

	// 이동 타입 표시
	CursorManager::GetInstance()->WriteBuffer
	(pObject->GetPosition().x, pObject->GetPosition().y - 2, GetMoveType());
}

void BigEnemy::Release()
{
}

void BigEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(BulletType, pObject->GetPosition());

	ShootDelay = 30;
}
