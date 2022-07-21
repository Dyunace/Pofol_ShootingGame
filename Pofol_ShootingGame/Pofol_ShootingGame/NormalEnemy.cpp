#include "NormalEnemy.h"
#include "CursorManager.h"
#include "BulletManager.h"

NormalEnemy::NormalEnemy() : Buffer() {}
NormalEnemy::~NormalEnemy(){}

void NormalEnemy::Initialize()
{
	Buffer[0] = (char*)"¦®";
	Buffer[1] = (char*)"¦¯";
	Buffer[2] = (char*)"¥µ";
	Buffer[3] = (char*)"¥³";

	Hp = 10;
	pBullet = ENORMALBULLET;
}

int NormalEnemy::Update()
{
	if (ShootDelay < 0)
		ShootBullet();

	--ShootDelay;

	return 0;
}

void NormalEnemy::Render()
{
	for (int i = 0; i < 4; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x + (i % 2 * 2),
			pObject->GetPosition().y + (i / 2),
			Buffer[i]
		);
}

void NormalEnemy::Release()
{
}

void NormalEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(pBullet, pObject->GetPosition());

	ShootDelay = 60;
}
