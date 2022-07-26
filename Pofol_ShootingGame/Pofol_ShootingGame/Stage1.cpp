#include "Stage1.h"
#include "CursorManager.h"
#include "ObjectManager.h"

#include "Player.h"
#include "NormalEnemy.h"
#include "SmallEnemy.h"
#include "BigEnemy.h"

#include "NormalBullet.h"

Stage1::Stage1() {}
Stage1::~Stage1(){}

void Stage1::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->SetPosition(40, 40);

	GetUserInstance();

	// Laser Bullet 중복 방지
	if (((Player*)pPlayer)->GetBullet() == LASERBULLET)
		isLaser = true;

	// 오브젝트 정보 가져오기
	GetObjectLists();
}

void Stage1::Update()
{
	ObjectManager::GetInstance()->Update();

	CollisionCheck();

	++SceneCount;

	if (SceneCount == 30)
	{
		Bridge* sEnemy = new NormalEnemy;
		ObjectManager::GetInstance()->AddBridge(NORMALENEMY, sEnemy, Vector3(40, 10));
		((EnemyBridge*)sEnemy)->SetMovement(0);
	}

	if (SceneCount == 60)
	{
		Bridge* sEnemy = new SmallEnemy;
		ObjectManager::GetInstance()->AddBridge(SMALLENEMY, sEnemy, Vector3(20, 5));
		((EnemyBridge*)sEnemy)->SetMovement(1);
	}

	if (SceneCount == 90)
	{
		Bridge* sEnemy = new BigEnemy;
		ObjectManager::GetInstance()->AddBridge(BIGENEMY, sEnemy, Vector3(60, 10));
		((EnemyBridge*)sEnemy)->SetMovement(11);
	}
}

void Stage1::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage1::Release()
{
}
