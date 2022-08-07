#include "Stage1_Boss_Core.h"
#include "CursorManager.h"
#include "BulletManager.h"

#include "Object.h"

Stage1_Boss_Core::Stage1_Boss_Core()
{
	for (int i = 0; i < 35; ++i)
		Buffer[i] = nullptr;
}
Stage1_Boss_Core::~Stage1_Boss_Core(){}

void Stage1_Boss_Core::Initialize()
{
	// 이미지
	{
		// 1줄
		Buffer[0] = (char*)"↙";
		Buffer[1] = (char*)"￣";
		Buffer[2] = (char*)"￣";
		Buffer[3] = (char*)"￣";
		Buffer[4] = (char*)"↘";

		// 2줄
		Buffer[5] = (char*)"↘";
		Buffer[6] = (char*)"＿";
		Buffer[7] = (char*)"＿";
		Buffer[8] = (char*)"＿";
		Buffer[9] = (char*)"↙";

		// 3줄
		Buffer[10] = (char*)"▥";
		Buffer[11] = (char*)"　";
		Buffer[12] = (char*)"▲";
		Buffer[13] = (char*)"　";
		Buffer[14] = (char*)"▥";

		// 4줄
		Buffer[15] = (char*)"▥";
		Buffer[16] = (char*)"◀";
		Buffer[17] = (char*)"◆";
		Buffer[18] = (char*)"▶";
		Buffer[19] = (char*)"▥";

		// 5줄
		Buffer[20] = (char*)"▥";
		Buffer[21] = (char*)"　";
		Buffer[22] = (char*)"▼";
		Buffer[23] = (char*)"　";
		Buffer[24] = (char*)"▥";

		// 6줄
		Buffer[25] = (char*)"▥";
		Buffer[26] = (char*)"　";
		Buffer[27] = (char*)"　";
		Buffer[28] = (char*)"　";
		Buffer[29] = (char*)"▥";

		// 7줄
		Buffer[30] = (char*)"↖";
		Buffer[31] = (char*)"▤";
		Buffer[32] = (char*)"▤";
		Buffer[33] = (char*)"▤";
		Buffer[34] = (char*)"↗";
	}

	Hp = CoreHp;
	MoveSpeed = 0.25f;

	BulletType = 0;

	if (pObject)
	{
		pObject->SetScale(6.0f, 3.0f);
	}
}

int Stage1_Boss_Core::Update()
{
	if (BossPhase == 2)
	{
		if (ShootDelay < 0)
		{
			ShootCoreBullet(BulletType);
			ShootDelay = CoreShootDelay;

			++BulletType;

			if (BulletType == 3)
				BulletType = 0;
		}

		--ShootDelay;
	}

	Movement(Vector3(15, 10));

	return 0;
}

void Stage1_Boss_Core::Render()
{
	if (DamageEfect != 3)
	{
		if (pObject->GetPosition().y >= -3)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y + 3,
					Buffer[i + 30]
				);
		}

		if (pObject->GetPosition().y >= -2)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y + 2,
					Buffer[i + 25]
				);
		}

		if (pObject->GetPosition().y >= -1)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y + 1,
					Buffer[i + 20]
				);
		}

		if (pObject->GetPosition().y >= 0)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y,
					Buffer[i + 15]
				);
		}

		if (pObject->GetPosition().y >= 1)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y - 1,
					Buffer[i + 10]
				);
		}

		if (pObject->GetPosition().y >= 2)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y - 2,
					Buffer[i + 5]
				);
		}

		if (pObject->GetPosition().y >= 3)
		{
			for (int i = 0; i < 5; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) - 2 + (i * 2),
					pObject->GetPosition().y - 3,
					Buffer[i]
				);
		}
	}

	if (DamageEfect != 0)
		--DamageEfect;
}
void Stage1_Boss_Core::Release(){}

void Stage1_Boss_Core::ShootCoreBullet(int _Type)
{
	BulletManager::GetInstance()->MakeBossBullet(_Type, pObject->GetPosition());
}
