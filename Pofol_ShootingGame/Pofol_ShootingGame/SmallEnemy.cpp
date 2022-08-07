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
	{
		pObject->SetScale(2.0f, 1.0f);
	}
}

int SmallEnemy::Update()
{
	Movement();

	if (ShootDelay < 0)
	{
		ShootBullet(Vector3(pObject->GetPosition().x, pObject->GetPosition().y + 2));
		ShootDelay = 10;
	}

	--ShootDelay;

	if (BufferCheck())
		return BUFFER_OVER;

    return 0;
}

void SmallEnemy::Render()
{
	if (DamageEfect != 3)
	{
		if (pObject->GetPosition().y < -1) {}
		else if (pObject->GetPosition().y == -1)
		{
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
				pObject->GetPosition().y + 1,
				Buffer[0]
			);
		}
		else if(pObject->GetPosition().y > -1)
		{
			for (int i = 0; i < 2; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
					pObject->GetPosition().y + (i % 2),
					Buffer[i]
				);
		}
	}

	if (DamageEfect != 0)
		--DamageEfect;

	//DebugRender();
}

void SmallEnemy::Release()
{
}