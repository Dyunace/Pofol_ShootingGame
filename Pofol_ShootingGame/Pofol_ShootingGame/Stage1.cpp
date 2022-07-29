#include "Stage1.h"

#include "ObjectManager.h"
#include "Player.h"

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

	StageWave = 1;
}

void Stage1::Update()
{
	ObjectManager::GetInstance()->Update();

	CollisionCheck();

	if (StageWave == 1)
	{
		// 이동 경로는 EnemyBridge.cpp 참조

		if (StageCount == 30)
			MakeEnemy(NORMALENEMY, 55, -1, 11);	// 0 = 정지

		else if (StageCount == 60)
			MakeEnemy(SMALLENEMY, 40, -1, 11);	// 1 = 아래로 이동, 밖으로 나가기
			
		else if (StageCount == 10)
			MakeEnemy(BIGENEMY, 70, -1, 11);		// 11 = 아래로 이동 후 정지

		else if (StageCount > 90 && WaveCheck())
		{
			++StageWave;
			StageCount = 0;
		}
	}

	else if (StageWave == 2)
	{
		if (StageCount == 30)
			MakeEnemy(BIGENEMY, 40, 5, 11);

		else if (StageCount == 60)
			MakeEnemy(BIGENEMY, 20, 10, 0);

		else if (StageCount == 90)
			MakeEnemy(BIGENEMY, 60, 5, 11);

		else if (StageCount > 90 && WaveCheck())
		{
			++StageWave;
			StageCount = 0;
		}
	}

	++StageCount;
}

void Stage1::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage1::Release()
{
}
