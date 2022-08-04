#include "Boom.h"
#include "Object.h"
#include "CursorManager.h"

#include "ObjectManager.h"
#include "DamageManager.h"

Boom::Boom() : Count(0)
{
	for (int i = 0; i < 2; ++i)
		BulletBuffer[i] = nullptr;

	for (int i = 0; i < 4; ++i)
		Buffer[i] = nullptr;

	for (int i = 0; i < 3; ++i)
		EnemyList[i] = nullptr;
}
Boom::~Boom(){}

void Boom::Initialize()
{
	BulletBuffer[0] = (char*)"Π";
	BulletBuffer[1] = (char*)"♣";

	Buffer[0] = (char*)"▥";
	Buffer[0] = (char*)"▧";
	Buffer[0] = (char*)"▨";
	Buffer[0] = (char*)"▤";

	EnemyList[0] = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	EnemyList[1] = ObjectManager::GetInstance()->GetObjectList(SMALLENEMY);
	EnemyList[2] = ObjectManager::GetInstance()->GetObjectList(BIGENEMY);
	
	Count = 0;
	Speed = 0.35f;
	Damage = 10;
}

int Boom::Update()
{
	if (Count < 30)
	{
		pObject->SetPosition(pObject->GetPosition().x, pObject->GetPosition().y - Speed);
	}
	else if (Count > 30)
	{
		// 데미지 함수
		AttackAllEnemy();

		// 총알 지우기
		RemoveAllBullet();
	}

	else if (Count > 90)
		return BUFFER_OVER;

	++Count;

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
		// 폭발 이미지 (임시)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"Boom!!!"
		);
	}
}

void Boom::Release()
{
}

void Boom::SetTarget(Vector3 _Target){}
void Boom::SetTarget(float _x, float _y){}

void Boom::AttackAllEnemy()
{
	for (int i = 0; i < 3; ++i)
	{
		if (EnemyList[i]->begin() != EnemyList[i]->end())
		{
			for (auto iter = EnemyList[i]->begin(); iter != EnemyList[i]->end(); ++i)
			{
				DamageManager::TakeDamage(pObject, (*iter));
			}
		}
	}


}

void Boom::RemoveAllBullet()
{
}
