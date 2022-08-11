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
	// ��ź �̹���
	BulletBuffer[0] = (char*)"��";
	BulletBuffer[1] = (char*)"��";

	// ���� ����
	ExplosionBuffer[0] = (char*)"��";

	ExplosionBuffer[1] = (char*)"��";
	ExplosionBuffer[2] = (char*)"��";
	ExplosionBuffer[3] = (char*)"��";
	ExplosionBuffer[4] = (char*)"��";
	ExplosionBuffer[5] = (char*)"��";

	ExplosionBuffer[6] = (char*)"��";
	ExplosionBuffer[7] = (char*)"��";
	ExplosionBuffer[8] = (char*)"��";
	ExplosionBuffer[9] = (char*)"��";
	ExplosionBuffer[10] = (char*)"��";

	ExplosionBuffer[11] = (char*)"��";
	ExplosionBuffer[12] = (char*)"��";
	ExplosionBuffer[13] = (char*)"��";
	ExplosionBuffer[14] = (char*)"��";
	ExplosionBuffer[15] = (char*)"��";
	ExplosionBuffer[16] = (char*)"��";
	ExplosionBuffer[17] = (char*)"��";

	ExplosionBuffer[18] = (char*)"��";
	ExplosionBuffer[19] = (char*)"��";
	ExplosionBuffer[20] = (char*)"��";
	ExplosionBuffer[21] = (char*)"��";
	ExplosionBuffer[22] = (char*)"��";

	ExplosionBuffer[23] = (char*)"��";
	ExplosionBuffer[24] = (char*)"��";
	ExplosionBuffer[25] = (char*)"��";
	ExplosionBuffer[26] = (char*)"��";
	ExplosionBuffer[27] = (char*)"��";

	ExplosionBuffer[28] = (char*)"��";

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
		// ���� �ٲٱ�
		int Color = 15;
		if (GetTickCount64() % 2 == 0)	Color = 12;
		else Color = 14;

		// ��ǥ�� Ȯ��
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