#include "Stage.h"
#include "Player.h"
#include "NormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "UserInstance.h"
#include "NormalEnemy.h"

Stage::Stage() : pPlayer(nullptr), pEnemy(nullptr) {}
Stage::~Stage(){}

void Stage::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->Initialize(PLAYER);
	pPlayer->SetPosition(40, 40);

	Bridge* enemy = new NormalEnemy;
	ObjectManager::GetInstance()->AddBridge(NORMALENEMY, enemy, Vector3(40, 10));
	pEnemy = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY)->front();

	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}

void Stage::Update()
{
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	auto NormalEnemyList = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);

	// ������Ʈ ����Ʈ ������Ʈ
	ObjectManager::GetInstance()->Update();

	// �Ѿ� & �� �浹 �˻�
	if (NormalEnemyList)
	{
		if (BulletList)
		{
			for (auto NormalEnemyIter = NormalEnemyList->begin(); NormalEnemyIter != NormalEnemyList->end(); ++NormalEnemyIter)
			{
				for (auto BulletIter = BulletList->begin();	BulletIter != BulletList->end();)
				{
					if (CollisionManager::CircleCollision(*NormalEnemyIter, *BulletIter))
					{
						// �浹 �˻� �����
						CursorManager::GetInstance()->WriteBuffer(
							(*NormalEnemyIter)->GetPosition().x,
							(*NormalEnemyIter)->GetPosition().y - (*NormalEnemyIter)->GetScale().y,
							(char*)"Hit!"
						);
	
						// �Ѿ� ���� ����
						::Safe_Delete((*BulletIter)->GetBridge());
	
						// DisableList�� ����
						BulletIter = ObjectManager::GetInstance()->ThrowObject(BulletIter, (*BulletIter));
					}
					else
						++BulletIter;
				}
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

}
