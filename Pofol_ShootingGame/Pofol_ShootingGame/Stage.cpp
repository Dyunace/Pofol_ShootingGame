#include "Stage.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "UserInstance.h"

Stage::Stage(){}
Stage::Stage(string* _str){}
Stage::~Stage(){}

void Stage::Initialize()
{
	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	pPlayer->Initialize("Player");
	pPlayer->SetPosition(40, 40);

	ObjectManager::GetInstance()->AddObject("NormalEnemy");
	pEnemy = ObjectManager::GetInstance()->GetObjectList("NormalEnemy")->front();
	pEnemy->Initialize("NormalEnemy");
	pEnemy->SetPosition(40, 10);

	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}

void Stage::Update()
{
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	auto NormalEnemyList = ObjectManager::GetInstance()->GetObjectList("NormalEnemy");

	// 오브젝트 리스트 검사
	ObjectManager::GetInstance()->Update();

	// 총알 & 적 충돌 검사
	if (BulletList && NormalEnemyList)
	{
		for (auto NormalEnemyIter = NormalEnemyList->begin(); 
			NormalEnemyIter != NormalEnemyList->end();
			++NormalEnemyIter)
		{
			for (auto BulletIter = BulletList->begin();
				BulletIter != BulletList->end();)
			{
				if (CollisionManager::CircleCollision(*NormalEnemyIter, *BulletIter))
				{
					// 충돌 검사 디버그
					CursorManager::GetInstance()->WriteBuffer(
						(*NormalEnemyIter)->GetPosition().x,
						(*NormalEnemyIter)->GetPosition().y - (*NormalEnemyIter)->GetScale().y,
						(char*)"Hit!"
					);

					// 총알 정보 삭제
					::Safe_Delete((*BulletIter)->GetBridge());

					// DisableList에 보관
					BulletIter = ObjectManager::GetInstance()->ThrowObject(BulletIter, (*BulletIter));
				}
				else
					++BulletIter;
			}
		}
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}
