#include "Stage1_Boss_Head.h"

#include "CursorManager.h"
#include "ObjectManager.h"
#include "Object.h"

Stage1_Boss_Head::Stage1_Boss_Head()
{
	for (int i = 0; i < 9; ++i)
		Buffer[i] = nullptr;
}
Stage1_Boss_Head::~Stage1_Boss_Head(){}

void Stage1_Boss_Head::Initialize()
{
	Buffer[0] = (char*)"¢Ö";
	Buffer[1] = (char*)"£þ";
	Buffer[2] = (char*)"¢Ø";

	Buffer[3] = (char*)"¡Ý";
	Buffer[4] = (char*)"¡â";
	Buffer[5] = (char*)"¡Ý";

	Buffer[6] = (char*)"¢Ù";
	Buffer[7] = (char*)"¢Ì";
	Buffer[8] = (char*)"¢×";

	Hp = HeadHp;
	BulletType = 3;

	Score = 500;

	if (pObject)
	{
		pObject->SetScale(6.0f, 3.0f);
	}

	Core = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE)->front();
}

int Stage1_Boss_Head::Update()
{
	if (ShootDelay < 0)
	{
		ShootBullet(Vector3(pObject->GetPosition().x, pObject->GetPosition().y + 2));
		ShootDelay = HeadShootDelay;
	}

	--ShootDelay;

	pObject->SetPosition(Core->GetPosition().x, Core->GetPosition().y - 4);

	return 0;
}

void Stage1_Boss_Head::Render()
{
	if (DamageEfect != 3)
	{
		if (pObject->GetPosition().y >= -1)
			for (int i = 0; i < 3; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2),
					pObject->GetPosition().y + 1,
					Buffer[i + 6]
				);

		if (pObject->GetPosition().y >= 0)
			for (int i = 0; i < 3; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2),
					pObject->GetPosition().y,
					Buffer[i + 3]
				);

		if (pObject->GetPosition().y >= 1)
			for (int i = 0; i < 3; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - pObject->GetScale().x * 0.5f + (i * 2),
					pObject->GetPosition().y - 1,
					Buffer[i]
				);
	}

	if (DamageEfect != 0)
		--DamageEfect;
}

void Stage1_Boss_Head::Release()
{
}