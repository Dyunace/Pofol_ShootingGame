#include "Stage.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "UserInstance.h"
#include "NormalEnemy.h"
#include "DamageManager.h"

Stage::Stage() : 
	pPlayer(nullptr), 
	PlayerBulletList(nullptr),
	ENormalBulletList(nullptr),
	NormalEnemyList(nullptr),
	SmallEnemyList(nullptr),
	BigEnemyList(nullptr),
	isLaser(false) {}
Stage::~Stage(){}

void Stage::GetObjectLists()
{
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	NormalEnemyList = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	SmallEnemyList = ObjectManager::GetInstance()->GetObjectList(SMALLENEMY);
	BigEnemyList = ObjectManager::GetInstance()->GetObjectList(BIGENEMY);

	PlayerBulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	ENormalBulletList = ObjectManager::GetInstance()->GetObjectList(ENORMALBULLET);
}

void Stage::CollisionCheck()
{
	if (PlayerBulletList)
	{
		for (int i = 0; i < 3; ++i)
		{
			list<Object*>* CurrentEnemyList = nullptr;

			switch (i)
			{
			case 0:
				CurrentEnemyList = NormalEnemyList;
				break;
			case 1:
				CurrentEnemyList = SmallEnemyList;
				break;
			case 2:
				CurrentEnemyList = BigEnemyList;
				break;
			default:
				break;
			}

			if (CurrentEnemyList)
			{
				for (auto CurrentEnemyIter = CurrentEnemyList->begin();
					CurrentEnemyIter != CurrentEnemyList->end();)
				{
					bool canDamage = true;

					for (auto PlayerBulletIter = PlayerBulletList->begin();
						PlayerBulletIter != PlayerBulletList->end();)
					{
						if (CollisionManager::RectCollision
						(*CurrentEnemyIter, *PlayerBulletIter))
						{
							// 충돌 검사 디버그
							CursorManager::GetInstance()->WriteBuffer(
								(*CurrentEnemyIter)->GetPosition().x,
								(*CurrentEnemyIter)->GetPosition().y
									- (*CurrentEnemyIter)->GetScale().y,
								(char*)"Hit!"
							);

							if (canDamage)
							{
								DamageManager::TakeDamage(
									(*PlayerBulletIter), (*CurrentEnemyIter));

								if (isLaser)
									canDamage = false;
							}

							// 총알 정보 삭제
							::Safe_Delete((*PlayerBulletIter)->GetBridge());

							// DisableList에 보관
							PlayerBulletIter = ObjectManager::GetInstance()->
								ThrowObject(PlayerBulletIter, (*PlayerBulletIter));
						}
						else
							++PlayerBulletIter;
					}

					DamageManager::DeathCheck(CurrentEnemyIter, (*CurrentEnemyIter));
				}
			}
		}
	}

	if (pPlayer)
	{
		// 적 총알 & 플레이어 충돌 검사
		if (ENormalBulletList)
		{
			for (auto ENormalBulletIter = ENormalBulletList->begin();
				ENormalBulletIter != ENormalBulletList->end();)
			{
				if (CollisionManager::CircleCollision(*ENormalBulletIter, pPlayer))
				{
					// 충돌 검사 디버그
					CursorManager::GetInstance()->WriteBuffer(
						pPlayer->GetPosition().x,
						pPlayer->GetPosition().y - 2,
						(char*)"Hit!"
					);

					// 총알 정보 삭제
					::Safe_Delete((*ENormalBulletIter)->GetBridge());

					// DisableList에 보관
					ENormalBulletIter = ObjectManager::GetInstance()->
						ThrowObject(ENormalBulletIter, (*ENormalBulletIter));
				}
				else
					++ENormalBulletIter;
			}
		}
	}
}

void Stage::GetUserInstance()
{
	// Player의 Bullet 세팅
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}
