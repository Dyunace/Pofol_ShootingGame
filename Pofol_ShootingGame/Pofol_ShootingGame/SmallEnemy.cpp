#include "SmallEnemy.h"
#include "CursorManager.h"
#include "BulletManager.h"
#include "Object.h"

SmallEnemy::SmallEnemy() : Buffer() {}
SmallEnemy::~SmallEnemy(){}

void SmallEnemy::Initialize()
{
    Buffer[0] = (char*)"¥Ì";
    Buffer[1] = (char*)"¥×";

	Hp = 10;
	MoveSpeed = 0.5f;
	BulletType = 1;

	if (pObject)
		pObject->SetScale(2.0f, 1.0f);
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
	if (DamageEfect != 3)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
				pObject->GetPosition().y - pObject->GetScale().y * 0.5f + (i % 2),
				Buffer[i]
			);

	if (DamageEfect != 0)
		--DamageEfect;

	DebugRender();
}

void SmallEnemy::Release()
{
}

void SmallEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(BulletType, pObject->GetPosition());

	ShootDelay = 10;
}