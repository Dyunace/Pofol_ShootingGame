#include "Stage.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "DamageManager.h"
#include "UserInstance.h"

#include "ObjectManager.h"
#include "Player.h"

#include "NormalEnemy.h"
#include "SmallEnemy.h"
#include "BigEnemy.h"

#include "NormalBullet.h"
#include "LaserBullet.h"
#include "Boom.h"
#include "ENormalBullet.h"

#include "Stage1_Boss_Core.h"
#include "Stage1_Boss_Head.h"
#include "Stage1_Boss_Arm_Left.h"
#include "Stage1_Boss_Arm_Right.h"
#include "Stage1_Boss_Shield_Left.h"
#include "Stage1_Boss_Shield_Right.h"

Stage::Stage() : 
	pPlayer(nullptr), 
	CurrentEnemyList(nullptr),
	PlayerBulletList(nullptr),
	PlayerBoomList(nullptr),
	ENormalBulletList(nullptr),
	NormalEnemyList(nullptr),
	SmallEnemyList(nullptr),
	BigEnemyList(nullptr),
	isLaser(false),
	CurStage(0),
	StageWave(0),
	StageCount(0),
	BossPhase(0),
	PhaseCount(0)
{}
Stage::~Stage(){}

void Stage::CatchObjectLists()
{
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	NormalEnemyList = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	SmallEnemyList = ObjectManager::GetInstance()->GetObjectList(SMALLENEMY);
	BigEnemyList = ObjectManager::GetInstance()->GetObjectList(BIGENEMY);

	PlayerBulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	PlayerBoomList = ObjectManager::GetInstance()->GetObjectList(BOOM);

	ENormalBulletList = ObjectManager::GetInstance()->GetObjectList(ENORMALBULLET);
}

void Stage::CollisionCheck()
{
	// �÷��̾� �Ѿ� & �� �浹 �˻�
	if (PlayerBulletList)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (i == 0)
				CurrentEnemyList = NormalEnemyList;
			else if (i == 1)
				CurrentEnemyList = SmallEnemyList;
			else if (i == 2)
				CurrentEnemyList = BigEnemyList;

			DamageCheck(CurrentEnemyList);
		}
	}

	// �÷��̾� ��ź �˻�
	if (PlayerBoomList)
	{
		if (PlayerBoomList->begin() != PlayerBoomList->end())
		{
			int Count = ((Boom*)PlayerBoomList->front()->GetBridge())->GetCount();

			if (Count > 30)
				for (int i = 0; i < 3; ++i)
				{
					// ȭ�� �� ��� ������ ������ ���ϱ�
					if (i == 0)
						CurrentEnemyList = NormalEnemyList;
					else if (i == 1)
						CurrentEnemyList = SmallEnemyList;
					else if (i == 2)
						CurrentEnemyList = BigEnemyList;

					BoomDamage(CurrentEnemyList);

					if (BossPhase != 0 && BossPhase != 99)
						TakeBossDamage();


					// ȭ�� �� ��� �� �Ѿ� �����ϱ�
					BoomRemoveBullet();
				}
		}
	}

	// �� �Ѿ� & �÷��̾� �浹 �˻�
	if (pPlayer && ENormalBulletList)
	{
		for (auto ENormalBulletIter = ENormalBulletList->begin();
			ENormalBulletIter != ENormalBulletList->end();)
		{
			if (CollisionManager::CircleCollision(*ENormalBulletIter, pPlayer))
			{
				// �浹 �˻� �����
				CursorManager::GetInstance()->WriteBuffer(
					pPlayer->GetPosition().x,
					pPlayer->GetPosition().y - 2,
					(char*)"Hit!"
				);

				// Bullet Bridge ����
				::Safe_Delete((*ENormalBulletIter)->GetBridge());

				// DisableList�� ����
				ENormalBulletIter = ObjectManager::GetInstance()->
					ThrowObject(ENormalBulletIter, (*ENormalBulletIter));
			}
			else
				++ENormalBulletIter;
		}
	}
}

void Stage::DamageCheck(list<Object*>* _CurrentList)
{
	if (_CurrentList)
	{
		for (auto CurrentEnemyIter = _CurrentList->begin();
			CurrentEnemyIter != _CurrentList->end();)
		{
			bool canDamage = true;

			for (auto PlayerBulletIter = PlayerBulletList->begin();
				PlayerBulletIter != PlayerBulletList->end();)
			{
				if (CollisionManager::RectCollision
				(*CurrentEnemyIter, *PlayerBulletIter))
				{
					if (canDamage)
					{
						DamageManager::TakeDamage(
							(*PlayerBulletIter), (*CurrentEnemyIter));

						if (isLaser)
							canDamage = false;

						CursorManager::GetInstance()->WriteBuffer(
							(*CurrentEnemyIter)->GetPosition(), (char*)"Hit"
						);
					}

					// �Ѿ� ���� ����
					::Safe_Delete((*PlayerBulletIter)->GetBridge());

					// DisableList�� ����
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

void Stage::BoomDamage(list<Object*>* _CurrentList)
{
	if (_CurrentList)
	{
		for (auto CurrentEnemyIter = _CurrentList->begin();
			CurrentEnemyIter != _CurrentList->end();)
		{
			DamageManager::TakeDamage((PlayerBoomList->front()), (*CurrentEnemyIter));
			DamageManager::DeathCheck(CurrentEnemyIter, (*CurrentEnemyIter));
		}
	}
}

void Stage::BoomRemoveBullet()
{
	for (int i = 0; i < 2; ++i)
	{
		list<Object*>* CurrentBullet = nullptr;

		if (i == 0)
			CurrentBullet = ENormalBulletList;

		if (CurrentBullet)
		{
			RemoveBullet(CurrentBullet);
		}
	}
}

void Stage::GetUserInstance()
{
	// Player�� Bullet ����
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}

void Stage::RenderUserInterface()
{
	// UI ȭ�鿡 ����ϱ� (�ӽ�)
	/*
		ȭ�鿡 ����� ���

		1. ����
		2. ���� ź + ����
		3. ���� ��ź ��
		4. ���� �������� (���̺�)
		5. ���� ����
		6. ����� �� ������
	*/
	CursorManager::GetInstance()->WriteBuffer(0, 0, (char*)"Life : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetLife(); ++f)
		CursorManager::GetInstance()->WriteBuffer(8.0f + (f * 2), 0, (char*)"��");

	CursorManager::GetInstance()->WriteBuffer(0, 2, (char*)"Boom : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetBoom(); ++f)
		CursorManager::GetInstance()->WriteBuffer(8.0f + (f * 2), 2, (char*)"��");
	
	char* BulletName = nullptr;

	if (((Player*)pPlayer)->GetBullet() == NORMALBULLET)
		BulletName = (char*)"Normal";
	else if (((Player*)pPlayer)->GetBullet() == LASERBULLET)
		BulletName = (char*)"Laser";

	CursorManager::GetInstance()->WriteBuffer(0, 4, BulletName);
	CursorManager::GetInstance()->WriteBuffer(8, 4, (char*)"Lv.");
	CursorManager::GetInstance()->WriteBuffer(12, 4, UserInstance::GetInstance()->GetBulletLevel());

	CursorManager::GetInstance()->WriteBuffer(0, 6, StageWave);
	

}

void Stage::MakeEnemy(string _EnemyType, float _x, float _y, int _MoveType)
{
	if (_EnemyType == NORMALENEMY)
	{
		Bridge* eNormal = new NormalEnemy;
		ObjectManager::GetInstance()->AddBridge(NORMALENEMY, eNormal, Vector3(_x, _y));
		((EnemyBridge*)eNormal)->SetMovement(_MoveType);
	}
	else if (_EnemyType == SMALLENEMY)
	{
		Bridge* eSmall = new SmallEnemy;
		ObjectManager::GetInstance()->AddBridge(SMALLENEMY, eSmall, Vector3(_x, _y));
		((EnemyBridge*)eSmall)->SetMovement(_MoveType);
	}
	else if (_EnemyType == BIGENEMY)
	{
		Bridge* eBig = new BigEnemy;
		ObjectManager::GetInstance()->AddBridge(BIGENEMY, eBig, Vector3(_x, _y));
		((EnemyBridge*)eBig)->SetMovement(_MoveType);
	}

	// ����
	else if (_EnemyType == STAGE1_BOSS_CORE)
	{
		Bridge* b1Core = new Stage1_Boss_Core;
		ObjectManager::GetInstance()->AddBridge(STAGE1_BOSS_CORE, b1Core, Vector3(_x, _y));
		((EnemyBridge*)b1Core)->SetMovement(_MoveType);

		Bridge* b1Head = new Stage1_Boss_Head;
		ObjectManager::GetInstance()->AddBridge(STAGE1_BOSS_HEAD, b1Head, Vector3(_x, _y - 4));

		Bridge* b1ArmL = new Stage1_Boss_Arm_Left;
		ObjectManager::GetInstance()->AddBridge(STAGE1_BOSS_ARM_LEFT, b1ArmL, Vector3(_x + 8, _y - 3));

		Bridge* b1ArmR = new Stage1_Boss_Arm_Right;
		ObjectManager::GetInstance()->AddBridge
		(STAGE1_BOSS_ARM_RIGHT, b1ArmR, Vector3(_x + 8, _y - 3));

		Bridge* b1ShieldL = new Stage1_Boss_Shield_Left;
		ObjectManager::GetInstance()->AddBridge
		(STAGE1_BOSS_SHIELD_LEFT, b1ShieldL, Vector3(_x - 5, _y + 4));

		Bridge* b1ShieldR = new Stage1_Boss_Shield_Right;
		ObjectManager::GetInstance()->AddBridge
		(STAGE1_BOSS_SHIELD_RIGHT, b1ShieldR, Vector3(_x + 5, _y + 4));
	}

	else {}
}

bool Stage::WaveCheck()
{
	int WaveCount = 0;

	if (NormalEnemyList)
	{
		if (NormalEnemyList->size() == 0)
			++WaveCount;
	}
	else
		++WaveCount;
	if (SmallEnemyList)
	{
		if (SmallEnemyList->size() == 0)
			++WaveCount;
	}
	else
		++WaveCount;
	if (BigEnemyList)
	{
		if (BigEnemyList->size() == 0)
			++WaveCount;
	}
	else
		++WaveCount;

	if (WaveCount == 3)
		return true;

	return false;
}
