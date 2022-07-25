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
	PlayerBulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	ENormalBulletList = ObjectManager::GetInstance()->GetObjectList(ENORMALBULLET);
}

void Stage::CollisionCheck()
{
	// �÷��̾� �Ѿ� & �� �浹 �˻�
	if (NormalEnemyList)
	{
		if (PlayerBulletList)
		{
			for (auto NormalEnemyIter = NormalEnemyList->begin(); NormalEnemyIter != NormalEnemyList->end(); ++NormalEnemyIter)
			{
				bool canDamage = true;

				for (auto PlayerBulletIter = PlayerBulletList->begin(); PlayerBulletIter != PlayerBulletList->end();)
				{
					if (CollisionManager::CircleCollision(*NormalEnemyIter, *PlayerBulletIter))
					{
						// �浹 �˻� �����
						CursorManager::GetInstance()->WriteBuffer(
							(*NormalEnemyIter)->GetPosition().x,
							(*NormalEnemyIter)->GetPosition().y - (*NormalEnemyIter)->GetScale().y,
							(char*)"Hit!"
						);

						if (canDamage)
						{
							// Enemy�� ������ ���
							((EnemyBridge*)((*NormalEnemyIter)->GetBridge()))->TakeDamage(
								((BulletBridge*)((*PlayerBulletIter)->GetBridge()))->GetDamage());

							if (isLaser)
								canDamage = false;
						}

						// �Ѿ� ���� ����
						::Safe_Delete((*PlayerBulletIter)->GetBridge());

						// DisableList�� ����
						PlayerBulletIter = ObjectManager::GetInstance()->ThrowObject(PlayerBulletIter, (*PlayerBulletIter));

					}
					else
						++PlayerBulletIter;
				}
			}
		}
	}

	// �� óġ �˻�
	if (NormalEnemyList)
	{
		for (auto NormalEnemyIter = NormalEnemyList->begin(); NormalEnemyIter != NormalEnemyList->end();)
		{
			if (((EnemyBridge*)((*NormalEnemyIter)->GetBridge()))->GetHP() <= 0)
			{

				// �� ���� ����
				::Safe_Delete((*NormalEnemyIter)->GetBridge());

				// DisableList�� ����
				NormalEnemyIter = ObjectManager::GetInstance()->ThrowObject(NormalEnemyIter, (*NormalEnemyIter));
			}
			else
				++NormalEnemyIter;
		}
	}

	// �� �Ѿ� & �÷��̾� �浹 �˻�
	if (ENormalBulletList)
	{
		for (auto ENormalBulletIter = ENormalBulletList->begin(); ENormalBulletIter != ENormalBulletList->end();)
		{
			if (CollisionManager::CircleCollision(*ENormalBulletIter, pPlayer))
			{
				// �浹 �˻� �����
				CursorManager::GetInstance()->WriteBuffer(
					(pPlayer)->GetPosition().x - 1,
					(pPlayer)->GetPosition().y - 4,
					(char*)"Hit!"
				);

				// �Ѿ� ���� ����
				::Safe_Delete((*ENormalBulletIter)->GetBridge());

				// DisableList�� ����
				ENormalBulletIter = ObjectManager::GetInstance()->ThrowObject(ENormalBulletIter, (*ENormalBulletIter));
			}
			else
				++ENormalBulletIter;
		}
	}
}

void Stage::GetUserInstance()
{
	// Player�� Bullet ����
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}
