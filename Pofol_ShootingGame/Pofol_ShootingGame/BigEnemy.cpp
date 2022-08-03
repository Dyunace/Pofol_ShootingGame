#include "BigEnemy.h"
#include "CursorManager.h"
#include "Object.h"
#include "BulletManager.h"

BigEnemy::BigEnemy()
{
	for (int i = 0; i < 16; ++i)
		Buffer[i] = nullptr;
}
BigEnemy::~BigEnemy(){}

void BigEnemy::Initialize()
{
	// 1줄
	Buffer[0] = (char*)"Δ";

	// 2줄 3
	Buffer[1] = (char*)"↙";
	Buffer[2] = (char*)"　";
	Buffer[3] = (char*)"↘";

	// 3줄 5
	Buffer[4] = (char*)"↙";
	Buffer[5] = (char*)"　";
	Buffer[6] = (char*)"Ω";
	Buffer[7] = (char*)"　";
	Buffer[8] = (char*)"↘";

	// 4줄 7
	Buffer[9] = (char*)"〈";
	Buffer[10] = (char*)"＿";
	Buffer[11] = (char*)"＿";
	Buffer[12] = (char*)"＿";
	Buffer[13] = (char*)"＿";
	Buffer[14] = (char*)"＿";
	Buffer[15] = (char*)"〉";

	Hp = 50;
	MoveSpeed = 0.25f;
	BulletType = 3;

	if (pObject)
		pObject->SetScale(14.0f, 1.0f);
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
	{
		if (pObject->GetPosition().y < 0) {}
		else if (pObject->GetPosition().y == 0)
		{
			for (int x = 0; x < 7; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + (x * 2),
					pObject->GetPosition().y,
					Buffer[x + 9]);
		}
		else if (pObject->GetPosition().y == 1)
		{
			for (int x = 0; x < 7; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + (x * 2),
					pObject->GetPosition().y,
					Buffer[x + 9]);

			for (int x = 0; x < 5; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + 2 + (x * 2),
					pObject->GetPosition().y - 1,
					Buffer[x + 4]);
		}
		else if (pObject->GetPosition().y == 2)
		{
			for (int x = 0; x < 7; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + (x * 2),
					pObject->GetPosition().y,
					Buffer[x + 9]);

			for (int x = 0; x < 5; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + 2 + (x * 2),
					pObject->GetPosition().y - 1,
					Buffer[x + 4]);

			for (int x = 0; x < 3; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + 4 + (x * 2),
					pObject->GetPosition().y - 2,
					Buffer[x + 1]);
		}
		else if (pObject->GetPosition().y > 2)
		{
			for (int x = 0; x < 7; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + (x * 2),
					pObject->GetPosition().y,
					Buffer[x + 9]);

			for (int x = 0; x < 5; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + 2 + (x * 2),
					pObject->GetPosition().y - 1,
					Buffer[x + 4]);

			for (int x = 0; x < 3; ++x)
				CursorManager::GetInstance()->WriteBuffer(
					pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + 4 + (x * 2),
					pObject->GetPosition().y - 2,
					Buffer[x + 1]);

			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x - (pObject->GetScale().x * 0.5f) + 6,
				pObject->GetPosition().y - 3,
				Buffer[0]);
		}
	}

	if (DamageEfect != 0)
		--DamageEfect;

	//DebugRender();
}

void BigEnemy::Release()
{
}

void BigEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(BulletType, pObject->GetPosition());

	ShootDelay = 30;
}
