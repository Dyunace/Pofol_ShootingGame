#include "Stage1.h"

#include "CollisionManager.h"
#include "DamageManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "Object.h"

#include "Stage1_Boss.h"

Stage1::Stage1() 
{
	for (int i = 0; i < 6; ++i)
		Stage1Boss[i] = nullptr;
}
Stage1::~Stage1(){}

void Stage1::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->SetPosition(40, 40);

	GetUserInstance();

	// Laser Bullet �ߺ� ����
	if (((Player*)pPlayer)->GetBullet() == LASERBULLET)
		isLaser = true;

	// ������Ʈ ���� ��������
	GetObjectLists();

	CurStage = 1;
	StageWave = 1;
}

void Stage1::Update()
{
	ObjectManager::GetInstance()->Update();

	CollisionCheck();

	if (StageWave == 1)
	{
		// �̵� ��δ� EnemyBridge.cpp ����

		if (StageCount == 10)
			MakeEnemy(NORMALENEMY, 55, -1, 10);	// 0 = ����

		else if (StageCount == 20)
			MakeEnemy(SMALLENEMY, 40, -1, 10);	// 1 = �Ʒ��� �̵�, ������ ������
			
		else if (StageCount == 30)
			MakeEnemy(BIGENEMY, 70, -1, 10);		// 11 = �Ʒ��� �̵� �� ����

		else if (StageCount > 30 && WaveCheck())
		{
			++StageWave;
			StageCount = 0;
		}
	}

	else if (StageWave == 3)
	{
		if (StageCount == 30)
			MakeEnemy(BIGENEMY, 40, 5, 11);

		else if (StageCount == 60)
			MakeEnemy(BIGENEMY, 20, 10, 10);

		else if (StageCount == 90)
			MakeEnemy(BIGENEMY, 60, 5, 11);

		else if (StageCount > 90 && WaveCheck())
		{
			++StageWave;
			StageCount = 0;
		}
	}

	else if (StageWave == 2)
	{
		// �ӽ� ���� ��������
		if (StageCount == 30)
		{
			MakeEnemy(STAGE1_BOSS_CORE, 40, 0, 20);

			GetBossList();
		}

		if (StageCount > 30 && (Stage1Boss[0]->begin() != Stage1Boss[0]->end()))
			BossCollisionCheck();
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

void Stage1::GetBossList()
{
	Stage1Boss[0] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_CORE);
	Stage1Boss[1] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_HEAD);
	Stage1Boss[2] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_ARM_LEFT);
	Stage1Boss[3] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_ARM_RIGHT);
	Stage1Boss[4] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_SHIELD_LEFT);
	Stage1Boss[5] = ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_SHIELD_RIGHT);

	BossList->push_back(ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_HEAD)->front());
	BossList->push_back(ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_ARM_LEFT)->front());
	BossList->push_back(ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_ARM_RIGHT)->front());
	BossList->push_back(ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_SHIELD_LEFT)->front());
	BossList->push_back(ObjectManager::GetInstance()->GetObjectList(STAGE1_BOSS_SHIELD_RIGHT)->front());
}

void Stage1::BossCollisionCheck()
{
	// ** �� �������� ���� ���� ����� �ٸ��� ������ ������������ ������ ����
	//if (PlayerBulletList)
	//{
	//	auto Core = Stage1Boss[0]->front()->GetBridge();
	//	list<Object*>* CurrentList = Stage1Boss[0];
	//
	//	if (((Stage1_Boss*)Core)->GetBossPhase() == 0)
	//	{
	//		int PhaseCount = 0;
	//
	//		for (int i = 0; i < 5; ++i)
	//		{
	//			switch (i)
	//			{
	//			case 0:
	//				CurrentList = Stage1Boss[1];
	//				break;
	//			case 1:
	//				CurrentList = Stage1Boss[2];
	//				break;
	//			case 2:
	//				CurrentList = Stage1Boss[3];
	//				break;
	//			case 3:
	//				CurrentList = Stage1Boss[4];
	//				break;
	//			case 4:
	//				CurrentList = Stage1Boss[5];
	//				break;
	//			default:
	//				break;
	//			}
	//
	//			if (CurrentList->begin() != CurrentList->end())
	//				DamageCheck(CurrentList);
	//			else
	//				++PhaseCount;
	//
	//			if (PhaseCount == 5)
	//				((Stage1_Boss*)Core)->SetBossPhase(1);
	//		}
	//	}
	//	else
	//		DamageCheck(CurrentList);
	//
	//	CursorManager::GetInstance()->WriteBuffer(80, 0, (char*)"BossCheck");
	//}
}
