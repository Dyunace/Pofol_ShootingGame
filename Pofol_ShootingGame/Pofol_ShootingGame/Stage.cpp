#include "Stage.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "DamageManager.h"
#include "UserInstance.h"
#include "InputManager.h"
#include "SceneManager.h"

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

#include "BoomItem.h"
#include "WeaponItem.h"

Stage::Stage() : 
	pPlayer(nullptr), 
	CurrentEnemyList(nullptr),
	PlayerBulletList(nullptr),
	PlayerBoomList(nullptr),
	ENormalBulletList(nullptr),
	NormalEnemyList(nullptr),
	SmallEnemyList(nullptr),
	BigEnemyList(nullptr),
	BoomItemList(nullptr),
	WeaponItemList(nullptr),
	isLaser(false),
	CurStage(0),
	StageWave(0),
	StageCount(0),
	BossPhase(0),
	PhaseCount(0),
	isBoomItemDrop(false),
	isWeaponItemDrop(false)
{}
Stage::~Stage(){}

void Stage::CatchObjectLists()
{
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	NormalEnemyList = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	SmallEnemyList = ObjectManager::GetInstance()->GetObjectList(SMALLENEMY);
	BigEnemyList = ObjectManager::GetInstance()->GetObjectList(BIGENEMY);

	PlayerBulletList = ObjectManager::GetInstance()->GetObjectList (
		UserInstance::GetInstance()->GetBullet());
	PlayerBoomList = ObjectManager::GetInstance()->GetObjectList(BOOM);

	ENormalBulletList = ObjectManager::GetInstance()->GetObjectList(ENORMALBULLET);

	BoomItemList = ObjectManager::GetInstance()->GetObjectList(BOOMITEM);
	WeaponItemList = ObjectManager::GetInstance()->GetObjectList(WEAPONITEM);
}

void Stage::CollisionCheck()
{
	for (int i = 0; i < 3; ++i)
	{
		if (i == 0)
			CurrentEnemyList = NormalEnemyList;
		else if (i == 1)
			CurrentEnemyList = SmallEnemyList;
		else if (i == 2)
			CurrentEnemyList = BigEnemyList;

		if (CurrentEnemyList)
		{
			// �÷��̾� �Ѿ� & �� �浹 �˻�
			if (PlayerBulletList)
				DamageCheck(CurrentEnemyList);

			// �÷��̾� ��ź �˻�
			if (PlayerBoomList)
			{
				if (PlayerBoomList->begin() != PlayerBoomList->end())
				{
					if (((Boom*)PlayerBoomList->front()->GetBridge())->GetCount() > 30)
						for (int i = 0; i < 3; ++i)
						{
							BoomDamage(CurrentEnemyList);

							// ȭ�� �� ��� �� �Ѿ� �����ϱ�
							BoomRemoveBullet();
						}
				}
			}

			// �� óġ �˻�
			for (auto iter = CurrentEnemyList->begin(); iter != CurrentEnemyList->end();)
			{
				// ������ ��� �˻�
				if (CurrentEnemyList == BigEnemyList)
					ItemDropCheck(iter);
				else
					// �Ϲ� �˻�
					DamageManager::DeathCheck(iter, (*iter));
			}
		}
	}

	// ��ź ���� ������ �˻�
	if (BossPhase != 0 && BossPhase != 99)
		if (PlayerBoomList)
			if (PlayerBoomList->begin() != PlayerBoomList->end())
				if (((Boom*)PlayerBoomList->front()->GetBridge())->GetCount() > 30)
					TakeBossDamage();

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

				RemoveObject(ENormalBulletIter);
			}
			else
				++ENormalBulletIter;
		}
	}

	// ������ & �÷��̾� �浹 �˻�
	for (int i = 0; i < 2; ++i)
	{
		list<Object*>* CurrentList = nullptr;

		if (i == 0)
			CurrentList = BoomItemList;
		if (i == 1)
			CurrentList = WeaponItemList;

		if (CurrentList)
		{
			for (auto iter = CurrentList->begin(); iter != CurrentList->end();)
			{
				if (CollisionManager::RectCollision(pPlayer, (*iter)))
				{
					// ��ź �߰�
					if (CurrentList == BoomItemList)
					{
						if (UserInstance::GetInstance()->GetBoom() != 5)
							UserInstance::GetInstance()->AddBoom();
						else
							UserInstance::GetInstance()->AddScore(GetBoomScore);
					}

					// ���� ���� or ���� ��
					if (CurrentList == WeaponItemList)
						ItemWeaponUpgrade(iter);

					// ������ ����
					RemoveObject(iter);
				}
				else
					++iter;
			}
		}
	}
}

void Stage::DamageCheck(list<Object*>* _CurrentList)
{
	if (_CurrentList)
	{
		for (auto CurrentEnemyIter = _CurrentList->begin();
			CurrentEnemyIter != _CurrentList->end(); ++CurrentEnemyIter)
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
					}

					RemoveObject(PlayerBulletIter);
				}
				else
					++PlayerBulletIter;
			}
		}
	}
}

void Stage::BoomDamage(list<Object*>* _CurrentList)
{
	if (_CurrentList)
	{
		for (auto CurrentEnemyIter = _CurrentList->begin();
			CurrentEnemyIter != _CurrentList->end(); ++CurrentEnemyIter)
		{
			DamageManager::TakeDamage((PlayerBoomList->front()), (*CurrentEnemyIter));
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
			RemoveObject(CurrentBullet);
		}
	}
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

	// ����
	CursorManager::GetInstance()->WriteBuffer(0, 0, (char*)"Life : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetLife(); ++f)
		CursorManager::GetInstance()->WriteBuffer(8.0f + (f * 2), 0, (char*)"��");


	// ��ź
	CursorManager::GetInstance()->WriteBuffer(0, 2, (char*)"Boom : ");
	for (float f = 0; f < UserInstance::GetInstance()->GetBoom(); ++f)
		CursorManager::GetInstance()->WriteBuffer(8.0f + (f * 2), 2, (char*)"��");
	

	// �Ѿ� �� ����
	char* BulletName = nullptr;
	if (UserInstance::GetInstance()->GetBullet() == NORMALBULLET)
		BulletName = (char*)"Normal";
	else if (UserInstance::GetInstance()->GetBullet() == LASERBULLET)
		BulletName = (char*)"Laser";

	CursorManager::GetInstance()->WriteBuffer(0, 4, BulletName);
	CursorManager::GetInstance()->WriteBuffer(8, 4, (char*)"Lv.");
	CursorManager::GetInstance()->WriteBuffer(12, 4, UserInstance::GetInstance()->GetBulletLevel());


	// ����
	int Score = UserInstance::GetInstance()->GetScore();
	CursorManager::GetInstance()->WriteBuffer(0, 6, (char*)"Score : ");

	CursorManager::GetInstance()->WriteBuffer(9, 6, Score / 10000);
	Score = Score - ((Score / 10000) * 10000);

	CursorManager::GetInstance()->WriteBuffer(10, 6, Score / 1000);
	Score = Score - ((Score / 1000) * 1000);

	CursorManager::GetInstance()->WriteBuffer(11, 6, Score / 100);
	Score = Score - ((Score / 100) * 100);

	CursorManager::GetInstance()->WriteBuffer(12, 6, Score / 10);
	Score = Score - ((Score / 10) * 10);

	CursorManager::GetInstance()->WriteBuffer(13, 6, Score);
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

void Stage::MakeItem(int _ItemType, Vector3 _Positioln)
{
	if (_ItemType == 0)
	{
		Bridge* iBoom = new BoomItem;
		ObjectManager::GetInstance()->AddBridge(BOOMITEM, iBoom, _Positioln);

		isBoomItemDrop = true;
	}
	else if (_ItemType == 1)
	{
		Bridge* iWeapon = new WeaponItem;
		ObjectManager::GetInstance()->AddBridge(WEAPONITEM, iWeapon, _Positioln);

		isWeaponItemDrop = true;
	}
}

void Stage::ItemDropCheck(list<Object*>::iterator& _iter)
{
	Vector3 Pos = (*_iter)->GetPosition();

	if (DamageManager::DeathCheck(_iter, (*_iter)))
	{
		srand(DWORD(GetTickCount64()));

		int val = rand() % 100;

		if (isBoomItemDrop == false && isWeaponItemDrop == false)
		{
			if (val < 70)
				MakeItem(0, Pos);
			else
				MakeItem(1, Pos);
		}
		else if (isBoomItemDrop == false)
			MakeItem(0, Pos);
		else if (isWeaponItemDrop == false)
			MakeItem(1, Pos);
	}
}

void Stage::ItemWeaponUpgrade(list<Object*>::iterator& _iter)
{
	string ItemType = ((WeaponItem*)(*_iter)->GetBridge())->GetItemType();

	if (ItemType == UserInstance::GetInstance()->GetBullet())
	{
		if (UserInstance::GetInstance()->GetBulletLevel() != 3)
			UserInstance::GetInstance()->AddBulletLevel();
		else
			UserInstance::GetInstance()->AddScore(GetWeaponScore);
	}
	else
	{
		UserInstance::GetInstance()->SetBullet(ItemType);
		UserInstance::GetInstance()->ResetBulletLevel();
	}
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
	{
		isBoomItemDrop = false;
		isWeaponItemDrop = false;

		return true;
	}

	return false;
}

void Stage::StageClear()
{
	if (StageCount == 10)
	{
		list<Object*>* CurrentList = nullptr;

		for (int i = 0; i < 2; ++i)
		{
			((Player*)pPlayer)->SetCanShoot(false);

			if (i == 0)
				CurrentList = PlayerBulletList;
			if (i == 1)
				CurrentList = ENormalBulletList;

			if (CurrentEnemyList)
				RemoveObject(CurrentList);
		}
	}

	if (StageCount > 10)
		CursorManager::GetInstance()->WriteBuffer(32, 10, (char*)"Stage 1 Clear!!");

	int Life = UserInstance::GetInstance()->GetLife();
	int Boom = UserInstance::GetInstance()->GetBoom();

	if (StageCount == 30)
	{
		for (int i = 0; i < Life; ++i)
			UserInstance::GetInstance()->AddScore(EndLifeScore);

		for (int i = 0; i < Boom; ++i)
			UserInstance::GetInstance()->AddScore(EndBoomScore);
	}

	if (StageCount > 30 && UserInstance::GetInstance()->GetGettingScore() != 0)
	{
		if (Life > 0)
		{
			CursorManager::GetInstance()->WriteBuffer(32, 12, (char*)"Life Bonus x");
			CursorManager::GetInstance()->WriteBuffer(49, 12, Life);
		}
		
		if (Boom > 0)
		{
			CursorManager::GetInstance()->WriteBuffer(32, 13, (char*)"Boom Bonus x");
			CursorManager::GetInstance()->WriteBuffer(49, 13, Boom);
		}

		if ((InputManager::GetInstance()->GetKey() & KEY_F) || (InputManager::GetInstance()->GetKey() & KEY_SPACE))
		{
			UserInstance::GetInstance()->SkipCalcScore();
		}
	}
	else if (StageCount > 30 && UserInstance::GetInstance()->GetGettingScore() == 0)
	{
		CursorManager::GetInstance()->WriteBuffer(24, 15, (char*)"Press \" F \" or \" Space \" to Menu");

		if ((InputManager::GetInstance()->GetKey() & KEY_F) || (InputManager::GetInstance()->GetKey() & KEY_SPACE))
		{
			RemoveObject(ObjectManager::GetInstance()->GetObjectList(PLAYER));
			SceneManager::GetInstance()->SetScene(MENU);
		}
	}
}