#include "Stage1.h"

#include "CollisionManager.h"
#include "DamageManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "UserInterface.h"
#include "InputManager.h"

#include "Player.h"
#include "Object.h"

#include "Stage1_Boss.h"

Stage1::Stage1() 
{
	for (int i = 0; i < 6; ++i)
		Stage1Boss[i] = nullptr;
}
Stage1::~Stage1() { Release(); }

void Stage1::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->SetPosition(40, 40);

	// 플레이어 총알 정보 가져오기
	if (UserInstance::GetInstance()->GetBullet() == LASERBULLET)
		isLaser = true;

	// 오브젝트 정보 가져오기
	CatchObjectLists();

	CurStage = 1;
	StageWave = 0;
}

void Stage1::Update()
{
	if (ObjectManager::GetInstance()->GetPuase() == false)
	{
		StageUpdate();

		WaveUpdate();

		++StageCount;
	}

	PauseCheck();

	if (isGameOver)
		GameOver();
}

void Stage1::Render()
{
	StageRender();

	if (StageWave == 0)
	{
		int Color;

		if (StageCount % 2 == 0)
			Color = 14;
		else
			Color = 10;

		if (StageCount < ConsoleWidthSize - 16)
			CursorManager::GetInstance()->WriteBuffer((float)StageCount, 20, (char*)"Stage 1 Start !!", Color);
	}
}

void Stage1::Release()
{
	ReleaseAll();

	if (BossPhase > 0)
	{
		list<Object*>* CurrentList = Stage1Boss[0];

		for (int i = 0; i < 6; ++i)
		{
			CurrentList = Stage1Boss[i];

			if (CurrentList)
				RemoveObject(CurrentList);
		}
	}
}

void Stage1::WaveUpdate()
{
	if (StageWave == 0)
	{
		if (StageCount == ConsoleWidthSize)
			WaveCheck();
	}

	else if (StageWave == 2)
	{
		// 이동 경로는 EnemyBridge.cpp 참조
		if (StageCount == 10)
			MakeEnemy(NORMALENEMY, 55, -1, 11);	// 0 = 정지

		else if (StageCount == 20)
			MakeEnemy(SMALLENEMY, 40, -1, 11);	// 1 = 아래로 이동, 밖으로 나가기

		else if (StageCount == 30)
			MakeEnemy(BIGENEMY, 70, 0, 11);		// 11 = 아래로 이동 후 정지

		if (StageCount > 40)
			WaveCheck();
	}

	else if (StageWave == 3)
	{
		if (StageCount == 10)
			MakeEnemy(NORMALENEMY, 10, -1, 11);

		else if (StageCount == 15)
			MakeEnemy(NORMALENEMY, 70, -1, 11);

		else if (StageCount == 20)
			MakeEnemy(NORMALENEMY, 25, -1, 11);

		else if (StageCount == 25)
			MakeEnemy(NORMALENEMY, 55, -1, 11);

		else if (StageCount == 30)
			MakeEnemy(NORMALENEMY, 40, -1, 11);

		if (StageCount > 40)
			WaveCheck();
	}

	else if (StageWave == 4)
	{
		if (StageCount == 30)
			MakeEnemy(BIGENEMY, 40, 5, 11);

		else if (StageCount == 60)
			MakeEnemy(BIGENEMY, 20, 10, 10);

		else if (StageCount == 90)
			MakeEnemy(BIGENEMY, 60, 5, 11);

		else if (StageCount > 100)
			WaveCheck();
	}

	else if (StageWave == 5)
	{
		// 임시 보스 스테이지
		if (StageCount == 30)
		{
			BossPhase = 1;
			PhaseCount = 0;

			MakeEnemy(STAGE1_BOSS_CORE, 40, 0, 20);

			GetBossList();
		}
		if (StageCount > 30)
			BossCollisionCheck();
	}

	// 스테이지 클리어
	else if (StageWave == 99)
	{
		StageClear();
	}
}

void Stage1::GetBossList()
{
	Stage1Boss[0] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE);
	Stage1Boss[1] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_HEAD);
	Stage1Boss[2] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_ARM_LEFT);
	Stage1Boss[3] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_ARM_RIGHT);
	Stage1Boss[4] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_SHIELD_LEFT);
	Stage1Boss[5] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_SHIELD_RIGHT);
}

void Stage1::BossCollisionCheck()
{
	// ** 각 스테이지 별로 보스 페이즈가 다르기 때문에 스테이지에서 개별로 관리
	PhaseCount = 0;

	list<Object*>* CurrentList = Stage1Boss[0];
	
	if (BossPhase == 1)
	{
		for (int i = 0; i < 5; ++i)
		{
			CurrentList = Stage1Boss[i + 1];

			if (CurrentList->begin() != CurrentList->end())
			{
				if (PlayerBulletList)
					DamageCheck(CurrentList);

				auto iter = CurrentList->begin();
				DamageManager::DeathCheck(iter, (*iter));
			}
			else
				++PhaseCount;

			if (PhaseCount == 5)
			{
				((Stage1_Boss*)(Stage1Boss[0]->front()->GetBridge()))->SetBossPhase(2);
				BossPhase = 2;
			}
		}
	}
	else if (BossPhase == 2)
	{
		DamageCheck(CurrentList);
		auto iter = CurrentList->begin();
		DamageManager::DeathCheck(iter, (*iter));

		if (CurrentList->begin() == CurrentList->end())
		{
			// 스테이지 클리어
			BossPhase = 99;
			StageWave = 99;
			StageCount = 0;
		}
	}
}

void Stage1::TakeBossDamage()
{
	list<Object*>* CurrentList = Stage1Boss[0];

	if (BossPhase == 1)
	{
		for (int i = 0; i < 5; ++i)
		{
			CurrentList = Stage1Boss[i + 1];

			if (CurrentList->begin() != CurrentList->end())
				DamageManager::TakeDamage(PlayerBoomList->front(), CurrentList->front());
		}
	}
	else if (BossPhase == 2)
	{
		if (CurrentList->begin() != CurrentList->end())
			DamageManager::TakeDamage(PlayerBoomList->front(), CurrentList->front());
	}
}
