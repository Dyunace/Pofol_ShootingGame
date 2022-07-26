#include "Stage.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "UserInstance.h"
#include "NormalEnemy.h"

Stage::Stage() : ENormalBulletList(), NormalEnemyList(), pPlayer(nullptr), PlayerBulletList(), isLaser(false) {}
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
	// 플레이어 총알 & 적 충돌 검사
	if (NormalEnemyList && PlayerBulletList)
	{
		for (auto NormalEnemyIter = NormalEnemyList->begin();
			NormalEnemyIter != NormalEnemyList->end(); ++NormalEnemyIter)
		{
			bool canDamage = true;

			for (auto PlayerBulletIter = PlayerBulletList->begin();
				PlayerBulletIter != PlayerBulletList->end();)
			{
				if (CollisionManager::CircleCollision(*NormalEnemyIter, *PlayerBulletIter))
				{
					// 충돌 검사 디버그
					CursorManager::GetInstance()->WriteBuffer(
						(*NormalEnemyIter)->GetPosition().x,
						(*NormalEnemyIter)->GetPosition().y - (*NormalEnemyIter)->GetScale().y,
						(char*)"Hit!"
					);

					if (canDamage)
					{
						// Enemy에 데미지 계산
						((EnemyBridge*)((*NormalEnemyIter)->GetBridge()))->TakeDamage(
							((BulletBridge*)((*PlayerBulletIter)->GetBridge()))->GetDamage());

						if (isLaser)
							canDamage = false;
					}

					// 총알 정보 삭제
					::Safe_Delete((*PlayerBulletIter)->GetBridge());

					// DisableList에 보관
					PlayerBulletIter = ObjectManager::GetInstance()->ThrowObject(PlayerBulletIter, (*PlayerBulletIter));
				}
				else
					++PlayerBulletIter;
			}
		}
	}

	if (SmallEnemyList && PlayerBulletList)
	{
		for (auto SmallEnemyIter = SmallEnemyList->begin();
			SmallEnemyIter != SmallEnemyList->end(); ++SmallEnemyIter)
		{
			bool canDamage = true;

			for (auto PlayerBulletIter = PlayerBulletList->begin();
				PlayerBulletIter != PlayerBulletList->end();)
			{
				if (CollisionManager::CircleCollision(*SmallEnemyIter, *PlayerBulletIter))
				{
					// 충돌 검사 디버그
					CursorManager::GetInstance()->WriteBuffer(
						(*SmallEnemyIter)->GetPosition().x,
						(*SmallEnemyIter)->GetPosition().y - (*SmallEnemyIter)->GetScale().y,
						(char*)"Hit!"
					);

					if (canDamage)
					{
						// Enemy에 데미지 계산
						((EnemyBridge*)((*SmallEnemyIter)->GetBridge()))->TakeDamage(
							((BulletBridge*)((*PlayerBulletIter)->GetBridge()))->GetDamage());

						if (isLaser)
							canDamage = false;
					}

					// 총알 정보 삭제
					::Safe_Delete((*PlayerBulletIter)->GetBridge());

					// DisableList에 보관
					PlayerBulletIter = ObjectManager::GetInstance()->ThrowObject(PlayerBulletIter, (*PlayerBulletIter));
				}
				else
					++PlayerBulletIter;
			}
		}
	}

	if (BigEnemyList && PlayerBulletList)
	{
		for (auto BigEnemyIter = BigEnemyList->begin();
			BigEnemyIter != BigEnemyList->end(); ++BigEnemyIter)
		{
			bool canDamage = true;

			for (auto PlayerBulletIter = PlayerBulletList->begin();
				PlayerBulletIter != PlayerBulletList->end();)
			{
				if (CollisionManager::CircleCollision(*BigEnemyIter, *PlayerBulletIter))
				{
					// 충돌 검사 디버그
					CursorManager::GetInstance()->WriteBuffer(
						(*BigEnemyIter)->GetPosition().x,
						(*BigEnemyIter)->GetPosition().y - (*BigEnemyIter)->GetScale().y,
						(char*)"Hit!"
					);

					if (canDamage)
					{
						// Enemy에 데미지 계산
						((EnemyBridge*)((*BigEnemyIter)->GetBridge()))->TakeDamage(
							((BulletBridge*)((*PlayerBulletIter)->GetBridge()))->GetDamage());

						if (isLaser)
							canDamage = false;
					}

					// 총알 정보 삭제
					::Safe_Delete((*PlayerBulletIter)->GetBridge());

					// DisableList에 보관
					PlayerBulletIter = ObjectManager::GetInstance()->ThrowObject(PlayerBulletIter, (*PlayerBulletIter));
				}
				else
					++PlayerBulletIter;
			}
		}
	}

	// 적 처치 검사
	if (NormalEnemyList)
	{
		for (auto NormalEnemyIter = NormalEnemyList->begin(); NormalEnemyIter != NormalEnemyList->end();)
		{
			if (((EnemyBridge*)((*NormalEnemyIter)->GetBridge()))->GetHP() <= 0)
			{

				// 적 정보 삭제
				::Safe_Delete((*NormalEnemyIter)->GetBridge());

				// DisableList에 보관
				NormalEnemyIter = ObjectManager::GetInstance()->ThrowObject(NormalEnemyIter, (*NormalEnemyIter));
			}
			else
				++NormalEnemyIter;
		}
	}

	// 적 처치 검사
	if (SmallEnemyList)
	{
		for (auto SmallEnemyIter = SmallEnemyList->begin(); SmallEnemyIter != SmallEnemyList->end();)
		{
			if (((EnemyBridge*)((*SmallEnemyIter)->GetBridge()))->GetHP() <= 0)
			{

				// 적 정보 삭제
				::Safe_Delete((*SmallEnemyIter)->GetBridge());

				// DisableList에 보관
				SmallEnemyIter = ObjectManager::GetInstance()->ThrowObject(SmallEnemyIter, (*SmallEnemyIter));
			}
			else
				++SmallEnemyIter;
		}
	}

	// 적 처치 검사
	if (BigEnemyList)
	{
		for (auto BigEnemyIter = BigEnemyList->begin(); BigEnemyIter != BigEnemyList->end();)
		{
			if (((EnemyBridge*)((*BigEnemyIter)->GetBridge()))->GetHP() <= 0)
			{

				// 적 정보 삭제
				::Safe_Delete((*BigEnemyIter)->GetBridge());

				// DisableList에 보관
				BigEnemyIter = ObjectManager::GetInstance()->ThrowObject(BigEnemyIter, (*BigEnemyIter));
			}
			else
				++BigEnemyIter;
		}
	}

	// 적 총알 & 플레이어 충돌 검사
	if (ENormalBulletList)
	{
		for (auto ENormalBulletIter = ENormalBulletList->begin(); ENormalBulletIter != ENormalBulletList->end();)
		{
			if (CollisionManager::CircleCollision(*ENormalBulletIter, pPlayer))
			{
				// 충돌 검사 디버그
				CursorManager::GetInstance()->WriteBuffer(
					(pPlayer)->GetPosition().x - 1,
					(pPlayer)->GetPosition().y - 4,
					(char*)"Hit!"
				);

				// 총알 정보 삭제
				::Safe_Delete((*ENormalBulletIter)->GetBridge());

				// DisableList에 보관
				ENormalBulletIter = ObjectManager::GetInstance()->ThrowObject(ENormalBulletIter, (*ENormalBulletIter));
			}
			else
				++ENormalBulletIter;
		}
	}
}

void Stage::GetUserInstance()
{
	// Player의 Bullet 세팅
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}
