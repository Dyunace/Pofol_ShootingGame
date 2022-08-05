#include "NormalEnemy.h"
#include "CursorManager.h"
#include "BulletManager.h"
#include "Object.h"

NormalEnemy::NormalEnemy() : Buffer() {}
NormalEnemy::~NormalEnemy(){}

void NormalEnemy::Initialize()
{
	Buffer[0] = (char*)"¦®";
	Buffer[1] = (char*)"¦¯";
	Buffer[2] = (char*)"¥µ";
	Buffer[3] = (char*)"¥³";

	Hp = 50;
	MoveSpeed = 0.25f;
	BulletType = 2;

	if (pObject)
		pObject->SetScale(4.0f, 2.0f);
}

int NormalEnemy::Update()
{
	Movement();

	if (ShootDelay < 0)
	{
		ShootBullet(Vector3(pObject->GetPosition().x, pObject->GetPosition().y + 2));
		ShootDelay = 15;
	}

	--ShootDelay;

	if (BufferCheck())
		return BUFFER_OVER;

	return 0;
}

void NormalEnemy::Render()
{
	if (DamageEfect != 3)
	{
		if (pObject->GetPosition().y == -1)
		{
			for (int i = 0; i < 2; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i % 2 * 2),
					pObject->GetPosition().y + 1,
					Buffer[i + 2]
				);
		}
		else if (pObject->GetPosition().y > -1)
		{
			for (int i = 0; i < 4; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i % 2 * 2),
					pObject->GetPosition().y + (i / 2),
					Buffer[i]
				);
		}
	}

	if (DamageEfect != 0)
		--DamageEfect;

	//DebugRender();
}

void NormalEnemy::Release()
{
}