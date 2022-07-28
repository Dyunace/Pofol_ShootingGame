#include "BigEnemy.h"
#include "CursorManager.h"
#include "Object.h"
#include "BulletManager.h"

BigEnemy::BigEnemy() : Buffer() {}
BigEnemy::~BigEnemy(){}

void BigEnemy::Initialize()
{
	Buffer[0] = (char*)"¢£";
	Buffer[1] = (char*)"¦³";
	Buffer[2] = (char*)"¢£";
	Buffer[3] = (char*)"¦­";
	Buffer[4] = (char*)"¥È";
	Buffer[5] = (char*)"¦­";
	Buffer[6] = (char*)"¦²";
	Buffer[7] = (char*)"¥Ð";
	Buffer[8] = (char*)"¦´";

	Hp = 50;
	MoveSpeed = 0.25f;
	BulletType = 3;

	if (pObject)
		pObject->SetScale(6.0f, 3.0f);
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
	if (DamageEfect != 3)
		for (int y = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + (x % 3 * 2),
					pObject->GetPosition().y - (pObject->GetScale().y * 0.5f) + (y % 3),
					Buffer[(x + (y * 3))]
				);

	if (DamageEfect != 0)
		--DamageEfect;

	DebugRender();
}

void BigEnemy::Release()
{
}

void BigEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(BulletType, pObject->GetPosition());

	ShootDelay = 30;
}
