#include "Boom.h"
#include "Object.h"
#include "CursorManager.h"

#include "ObjectManager.h"
#include "DamageManager.h"

Boom::Boom() : Count(0)
{
	for (int i = 0; i < 2; ++i)
		BulletBuffer[i] = nullptr;

	for (int i = 0; i < 29; ++i)
		ExplosionBuffer[i] = nullptr;

	for (int i = 0; i < 3; ++i)
		EnemyList[i] = nullptr;
}
Boom::~Boom(){}

void Boom::Initialize()
{
	// ÆøÅº ÀÌ¹ÌÁö
	BulletBuffer[0] = (char*)"¥Ð";
	BulletBuffer[1] = (char*)"¢À";

	// Æø¹ß ¹üÀ§
	ExplosionBuffer[0] = (char*)"¢Ç";

	ExplosionBuffer[1] = (char*)"¢Ê";
	ExplosionBuffer[2] = (char*)"¢Ê";
	ExplosionBuffer[3] = (char*)"¢Ç";
	ExplosionBuffer[4] = (char*)"¢É";
	ExplosionBuffer[5] = (char*)"¢É";

	ExplosionBuffer[6] = (char*)"¢Ê";
	ExplosionBuffer[7] = (char*)"¢Ê";
	ExplosionBuffer[8] = (char*)"¢Ç";
	ExplosionBuffer[9] = (char*)"¢É";
	ExplosionBuffer[10] = (char*)"¢É";

	ExplosionBuffer[11] = (char*)"¢È";
	ExplosionBuffer[12] = (char*)"¢È";
	ExplosionBuffer[13] = (char*)"¢È";
	ExplosionBuffer[14] = (char*)"¢Ì";
	ExplosionBuffer[15] = (char*)"¢È";
	ExplosionBuffer[16] = (char*)"¢È";
	ExplosionBuffer[17] = (char*)"¢È";

	ExplosionBuffer[18] = (char*)"¢É";
	ExplosionBuffer[19] = (char*)"¢É";
	ExplosionBuffer[20] = (char*)"¢Ç";
	ExplosionBuffer[21] = (char*)"¢Ê";
	ExplosionBuffer[22] = (char*)"¢Ê";

	ExplosionBuffer[23] = (char*)"¢É";
	ExplosionBuffer[24] = (char*)"¢É";
	ExplosionBuffer[25] = (char*)"¢Ç";
	ExplosionBuffer[26] = (char*)"¢Ê";
	ExplosionBuffer[27] = (char*)"¢Ê";

	ExplosionBuffer[28] = (char*)"¢Ç";

	EnemyList[0] = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	EnemyList[1] = ObjectManager::GetInstance()->GetObjectList(SMALLENEMY);
	EnemyList[2] = ObjectManager::GetInstance()->GetObjectList(BIGENEMY);
	
	Count = 0;
	Speed = 0.35f;
	Damage = 2;
}

int Boom::Update()
{
	++Count;

	if (Count < 30)
	{
		pObject->SetPosition(pObject->GetPosition().x, pObject->GetPosition().y - Speed);
	}

	else if (Count > 90)
		return BUFFER_OVER;

	return 0;
}

void Boom::Render()
{
	if (Count < 30)
	{
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x,
				pObject->GetPosition().y + i,
				BulletBuffer[i]
			);
	}
	else
	{
		// »ö»ó ¹Ù²Ù±â
		int Color = 15;
		if (GetTickCount64() % 2 == 0)	Color = 12;
		else Color = 14;

		// ÁÂÇ¥°ª È®ÀÎ
		Vector3 Pos = pObject->GetPosition();

		if (Pos.x > -12 && Pos.x < ConsoleWidthSize - 12)
		{
			CursorManager::GetInstance()->WriteBuffer(
				Pos.x + 12,
				Pos.y,
				ExplosionBuffer[28], Color);
		}
		if (Pos.x > -8 && Pos.x < ConsoleWidthSize - 8)
		{
			for (int i = 0; i < 5; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(
					Pos.x + 8,
					Pos.y - 4 + i * 2,
					ExplosionBuffer[23 + i], Color);
			}
		}
		if (Pos.x > -4 && Pos.x < ConsoleWidthSize - 4)
		{
			for (int i = 0; i < 5; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(
					Pos.x + 4,
					Pos.y - 4 + i * 2,
					ExplosionBuffer[18 + i], Color);
			}
		}
		if (Pos.x > 0 && Pos.x < ConsoleWidthSize)
		{
			for (int i = 0; i < 7; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(
					Pos.x,
					Pos.y - 6 + i * 2,
					ExplosionBuffer[11 + i], Color);
			}
		}
		if (Pos.x > 4 && Pos.x < ConsoleWidthSize + 4)
		{
			for (int i = 0; i < 5; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(
					Pos.x - 4,
					Pos.y - 4 + i * 2,
					ExplosionBuffer[6 + i], Color);
			}
		}
		if (Pos.x > 8 && Pos.x < ConsoleWidthSize + 8)
		{
			for (int i = 0; i < 5; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(
					Pos.x - 8,
					Pos.y - 4 + i * 2,
					ExplosionBuffer[1 + i], Color);
			}
		}
		if (Pos.x > 12 && Pos.x < ConsoleWidthSize + 12)
		{
			CursorManager::GetInstance()->WriteBuffer(
				Pos.x - 12,
				Pos.y,
				ExplosionBuffer[0], Color);
		}
	}
}

void Boom::Release()
{
}