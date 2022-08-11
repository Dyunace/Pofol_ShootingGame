#include "Stage.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "DamageManager.h"
#include "UserInstance.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "UserInterface.h"
#include "Warning.h"

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

	isPause(false),
	isGameOver(false),

	CurStage(0),
	StageWave(0),
	StageCount(0),
	BossPhase(0),
	PhaseCount(0),
	isBoomItemDrop(false),
	isWeaponItemDrop(false)
{}
Stage::~Stage(){}

void Stage::StageUpdate()
{
	ObjectManager::GetInstance()->Update();

	UserInstance::GetInstance()->Update();

	CatchObjectLists();

	CollisionCheck();
}

void Stage::StageRender()
{
	ObjectManager::GetInstance()->Render();

	UserInterface::GetInstance()->Render();

	if (isPause)
		Warning::GetInstance()->Render();
}

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
	// �� �浹 �˻�
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
					{
						for (int i = 0; i < 3; ++i)
						{
							BoomDamage(CurrentEnemyList);

							// ȭ�� �� ��� �� �Ѿ� �����ϱ�
							BoomRemoveBullet();
						}
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
					DamageManager::DeathCheck(iter, (*iter));
			}
		}
	}

	// ��ź ���� ������ �˻�
	if (BossPhase != 0 && BossPhase != 99)
	{
		if (PlayerBoomList)
			if (PlayerBoomList->begin() != PlayerBoomList->end())
				if (((Boom*)PlayerBoomList->front()->GetBridge())->GetCount() > 30)
					TakeBossDamage();
	}	

	// �÷��̾� �浹 �˻�
	if (pPlayer)
	{
		// ������ üũ
		if (((Player*)pPlayer)->GetRespawnCount() == 0)
		{
			// �� �Ѿ� �浹 �˻�
			if (ENormalBulletList)
			{
				for (auto ENormalBulletIter = ENormalBulletList->begin();
					ENormalBulletIter != ENormalBulletList->end();)
				{
					if (CollisionManager::CircleCollision(*ENormalBulletIter, pPlayer))
					{
						// �������� �������� ��
						if (UserInstance::GetInstance()->GetLife() > 0)
						{
							// ������ ����
							UserInstance::GetInstance()->AddLife(-1);

							// ��� �� ������ ���
							MakeItem(0, pPlayer->GetPosition());		// ��ź�� �ݵ�� �� �� ���

							if (UserInstance::GetInstance()->GetBulletLevel() > 1)
								MakeItem(1, pPlayer->GetPosition());	// źȯ�� 2���� �̻��� �� �� �� ���

							// ��ź�� �Ѿ� ���� �ʱ�ȭ
							UserInstance::GetInstance()->SetBoom();
							UserInstance::GetInstance()->SetBulletLevel();

							// ���� ����Ʈ
							ObjectManager::GetInstance()->AddObject(EXPLOSION);
							auto explo = ObjectManager::GetInstance()->GetObjectList(EXPLOSION);
							explo->back()->SetPosition(pPlayer->GetPosition());

							// �÷��̾� ��� ó�� ����
							((Player*)pPlayer)->PlayerRespawn();
						}

						// �������� ������ ���� ����
						else
						{
							// ������Ʈ �Ͻ� ����
							ObjectManager::GetInstance()->SetPause(true);

							// �÷��̾�� óġ ����
							pPlayer->SetVisible(false);

							// ���� ���� ���� ��ȯ
							isGameOver = true;

							// ���� ������ Ÿ�̸�
							StageCount = 0;

							// ���� ���� ���ڸ��� ���� ���� (���� �ؽ�Ʈ ���� �� ����)
							InputManager::GetInstance()->SetInputDelay(50);
						}

						// �� �Ѿ� ����
						RemoveObject(ENormalBulletIter);
					}
					else
						++ENormalBulletIter;
				}
			}
		}
		else
			// ������ �ϴ� ���� ���� ����
			((Player*)pPlayer)->PlayerRespawn();


		// ������ & �÷��̾� �浹 �˻�
		if (((Player*)pPlayer)->GetDeathCount() == 0)
		{
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
	}
	else if (_ItemType == 1)
	{
		Bridge* iWeapon = new WeaponItem;
		ObjectManager::GetInstance()->AddBridge(WEAPONITEM, iWeapon, _Positioln);
	}
}

void Stage::ItemDropCheck(list<Object*>::iterator& _iter)
{
	Vector3 Pos = (*_iter)->GetPosition();

	if (DamageManager::DeathCheck(_iter, (*_iter)))
	{
		if (isBoomItemDrop == false && isWeaponItemDrop == false)
		{
			srand(DWORD(GetTickCount64()));
			int val = rand() % 100;

			if (val < 70)
			{
				isBoomItemDrop = true;
					MakeItem(0, Pos);
			}
			else
			{
				isWeaponItemDrop = true;
				MakeItem(1, Pos);
			}
		}
		else if (isBoomItemDrop == false)
		{
			isBoomItemDrop = true;
			MakeItem(0, Pos);
		}
		else if (isWeaponItemDrop == false)
		{
			isWeaponItemDrop = true;
			MakeItem(1, Pos);
		}
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
		UserInstance::GetInstance()->SetBulletLevel();
	}
}

bool Stage::WaveCheck()
{
	int WaveCount = 0;

	for (int i = 0; i < 3; ++i)
	{
		list<Object*>* CurList = nullptr;

		if (i == 0)
			CurList = NormalEnemyList;
		else if (i == 1)
			CurList = SmallEnemyList;
		else if (i == 2)
			CurList = BigEnemyList;

		if (CurList)
		{
			if (CurList->size() == 0)
				++WaveCount;
		}
		else
			++WaveCount;
	}

	if (WaveCount == 3)
	{
		isBoomItemDrop = false;
		isWeaponItemDrop = false;

		NextWave();

		return true;
	}

	return false;
}

void Stage::NextWave()
{
	++StageWave;
	StageCount = 0;
}

void Stage::StageClear()
{
	// Ŭ���� �� �Ѿ� ����
	if (StageCount == 1)
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

	// Ŭ���� ���� ����
	if (StageCount > 30)
		CursorManager::GetInstance()->WriteBuffer(32, 10, (char*)"Stage 1 Clear!!");

	int Life = UserInstance::GetInstance()->GetLife();
	int Boom = UserInstance::GetInstance()->GetBoom();

	// ���� ����
	if (StageCount == 60)
	{
		for (int i = 0; i < Life; ++i)
			UserInstance::GetInstance()->AddScore(EndLifeScore);

		for (int i = 0; i < Boom; ++i)
			UserInstance::GetInstance()->AddScore(EndBoomScore);
	}

	// ���� ���� �Ǵ� ���� ���� ����
	if (StageCount > 60 && UserInstance::GetInstance()->GetGettingScore() != 0)
	{
		if (Life > 0)
		{
			CursorManager::GetInstance()->WriteBuffer(32, 12, (char*)"Life Bonus x ");
			CursorManager::GetInstance()->WriteBuffer(46, 12, Life);
		}
		
		if (Boom > 0)
		{
			CursorManager::GetInstance()->WriteBuffer(32, 13, (char*)"Boom Bonus x ");
			CursorManager::GetInstance()->WriteBuffer(46, 13, Boom);
		}

		// ��ŵ Ű
		if ((InputManager::GetInstance()->GetKey() & KEY_F) ||
			(InputManager::GetInstance()->GetKey() & KEY_SPACE))
		{
			InputManager::GetInstance()->SetInputDelay();
			UserInstance::GetInstance()->SkipCalcScore();
		}
	}
	else if (StageCount > 60 && UserInstance::GetInstance()->GetGettingScore() == 0)
	{
		CursorManager::GetInstance()->WriteBuffer(24, 15, 
			(char*)"Press \"F\" or \"Space Bar\" for Menu");

		if ((InputManager::GetInstance()->GetKey() & KEY_F) ||
			(InputManager::GetInstance()->GetKey() & KEY_SPACE))
		{
			if (InputManager::GetInstance()->GetInputDelay() == 0)
			{
				InputManager::GetInstance()->SetInputDelay();
				SceneManager::GetInstance()->SetScene(MENU);
			}
		}
	}
}

void Stage::PauseCheck()
{
	// esc ������ ���� �޴� ����
	if (isPause == false)
	{
		if (InputManager::GetInstance()->GetKey() == KEY_ESC)
		{
			if (InputManager::GetInstance()->GetInputDelay() == 0)
			{
				InputManager::GetInstance()->SetInputDelay();
				ObjectManager::GetInstance()->SetPause(true);

				Warning::GetInstance()->SetWarning(WPAUSE);

				isPause = true;
			}
		}
	}
	else
		PauseMenu();
}

void Stage::PauseMenu()
{
	// ������
	int ans = Warning::GetInstance()->Update();

	if (InputManager::GetInstance()->GetKey() == KEY_F || InputManager::GetInstance()->GetKey() == KEY_SPACE)
	{
		ObjectManager::GetInstance()->SetPause(false);

		if (ans == 0)
			SceneManager::GetInstance()->SetScene(MENU);
		else if (ans == 1)
		{
			// �޴� ����
			InputManager::GetInstance()->SetInputDelay();
			isPause = false;
		}
	}
	else if (InputManager::GetInstance()->GetKey() == KEY_ESC)
	{
		// �޴� ����
		InputManager::GetInstance()->SetInputDelay();
		ObjectManager::GetInstance()->SetPause(false);
		isPause = false;
	}
}

void Stage::GameOver()
{
	if (StageCount > 30)
	{
		UserInterface::GetInstance()->MakeUI(21, 24, 19, 6);

		CursorManager::GetInstance()->WriteBuffer(36, 25,
			(char*)"Game Over", 12);
	}

	if (StageCount > 50)
	{
		CursorManager::GetInstance()->WriteBuffer(23, 28,
			(char*)"Press \"F\" or \"Space Bar\" for Menu");

		if (InputManager::GetInstance()->GetInputDelay() == 0)
		{
			if (InputManager::GetInstance()->GetKey() == KEY_F ||
				InputManager::GetInstance()->GetKey() == KEY_SPACE)
			{
				ObjectManager::GetInstance()->SetPause(false);
				pPlayer->SetVisible(true);

				InputManager::GetInstance()->SetInputDelay();
				SceneManager::GetInstance()->SetScene(MENU);
			}
		}
	}
}

void Stage::ReleaseAll()
{
	auto iPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->begin();
	ObjectManager::GetInstance()->ThrowObject(iPlayer, (*iPlayer));

	for (int i = 0; i < 7; ++i)
	{
		list<Object*>* CurList = nullptr;

		if (i == 0)
			CurList = PlayerBulletList;
		else if (i == 1)
			CurList = ENormalBulletList;
		else if (i == 2)
			CurList = NormalEnemyList;
		else if (i == 3)
			CurList = SmallEnemyList;
		else if (i == 4)
			CurList = BigEnemyList;
		else if (i == 5)
			CurList = PlayerBoomList;
		else if (i == 6)
			CurList = BoomItemList;
		else if (i == 7)
			CurList = WeaponItemList;

		if (CurList)
		{
			RemoveObject(CurList);
		}
	}
}
