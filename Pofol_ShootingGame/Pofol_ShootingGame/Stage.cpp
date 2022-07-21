#include "Stage.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "UserInstance.h"
#include "NormalEnemy.h"

Stage::Stage() : pPlayer(nullptr), pEnemy(nullptr), isLaser(false) {}
Stage::~Stage(){}

void Stage::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->Initialize(PLAYER);
	pPlayer->SetPosition(40, 40);
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
	
	// LaserBullet 중복 체크 방지
	if (((Player*)pPlayer)->GetBullet() == LASERBULLET)
		isLaser = true;

	Bridge* enemy = new NormalEnemy;
	ObjectManager::GetInstance()->AddBridge(NORMALENEMY, enemy, Vector3(40, 10));
	pEnemy = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY)->front();

	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}

void Stage::Update()
{
	auto NormalEnemyList = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	auto PlayerBulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	auto ENormalBulletList = ObjectManager::GetInstance()->GetObjectList(ENORMALBULLET);

	// 오브젝트 리스트 업데이트
	ObjectManager::GetInstance()->Update();

	// 플레이어 총알 & 적 충돌 검사
	if (NormalEnemyList)
	{
		if (PlayerBulletList)
		{
			for (auto NormalEnemyIter = NormalEnemyList->begin(); NormalEnemyIter != NormalEnemyList->end(); ++NormalEnemyIter)
			{
				bool canDamage = true;

				for (auto PlayerBulletIter = PlayerBulletList->begin();	PlayerBulletIter != PlayerBulletList->end();)
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
	}

	// 적 처치 검사
	if (NormalEnemyList)
	{
		for (auto NormalEnemyIter = NormalEnemyList->begin(); NormalEnemyIter != NormalEnemyList->end();)
		{
			// 체력 표시
			CursorManager::GetInstance()->WriteBuffer
			((*NormalEnemyIter)->GetPosition().x, (*NormalEnemyIter)->GetPosition().y - 1,
				((EnemyBridge*)((*NormalEnemyIter)->GetBridge()))->GetHP());

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

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{

}
