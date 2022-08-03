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
#include "ENormalBullet.h"

#include "Stage1_Boss_Core.h"
#include "Stage1_Boss_Head.h"
#include "Stage1_Boss_Arm_Left.h"
#include "Stage1_Boss_Arm_Right.h"
#include "Stage1_Boss_Shield_Left.h"
#include "Stage1_Boss_Shield_Right.h"

Stage::Stage() : 
	pPlayer(nullptr), 
	PlayerBulletList(nullptr),
	ENormalBulletList(nullptr),
	NormalEnemyList(nullptr),
	SmallEnemyList(nullptr),
	BigEnemyList(nullptr),
	isLaser(false),
	CurStage(0),
	StageWave(0),
	StageCount(0)
{}
Stage::~Stage(){}

void Stage::GetObjectLists()
{
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	NormalEnemyList = ObjectManager::GetInstance()->GetObjectList(NORMALENEMY);
	SmallEnemyList = ObjectManager::GetInstance()->GetObjectList(SMALLENEMY);
	BigEnemyList = ObjectManager::GetInstance()->GetObjectList(BIGENEMY);

	PlayerBulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());
	ENormalBulletList = ObjectManager::GetInstance()->GetObjectList(ENORMALBULLET);
}

void Stage::CollisionCheck()
{
	// 플레이어 총알 & 적 충돌 검사
	if (PlayerBulletList)
	{
		for (int i = 0; i < 3; ++i)
		{
			list<Object*>* CurrentEnemyList = nullptr;

			switch (i)
			{
			case 0:
				CurrentEnemyList = NormalEnemyList;
				break;
			case 1:
				CurrentEnemyList = SmallEnemyList;
				break;
			case 2:
				CurrentEnemyList = BigEnemyList;
				break;
			default:
				break;
			}

			DamageCheck(CurrentEnemyList);
		}
	}

	// 적 총알 & 플레이어 충돌 검사
	if (pPlayer)
	{
		if (ENormalBulletList)
		{
			for (auto ENormalBulletIter = ENormalBulletList->begin();
				ENormalBulletIter != ENormalBulletList->end();)
			{
				if (CollisionManager::CircleCollision(*ENormalBulletIter, pPlayer))
				{
					// 충돌 검사 디버그
					CursorManager::GetInstance()->WriteBuffer(
						pPlayer->GetPosition().x,
						pPlayer->GetPosition().y - 2,
						(char*)"Hit!"
					);

					// Bullet Bridge 삭제
					::Safe_Delete((*ENormalBulletIter)->GetBridge());

					// DisableList에 보관
					ENormalBulletIter = ObjectManager::GetInstance()->
						ThrowObject(ENormalBulletIter, (*ENormalBulletIter));
				}
				else
					++ENormalBulletIter;
			}
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
					}

					// 총알 정보 삭제
					::Safe_Delete((*PlayerBulletIter)->GetBridge());

					// DisableList에 보관
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

void Stage::GetUserInstance()
{
	// Player의 Bullet 세팅
	((Player*)pPlayer)->SetBullet(UserInstance::GetInstance()->GetBullet());
}

void Stage::MakeEnemy(string _EnemyType, Vector3 _Position, int _MoveType)
{
	if (_EnemyType == NORMALENEMY)
	{
		Bridge* sEnemy = new NormalEnemy;
		ObjectManager::GetInstance()->AddBridge(NORMALENEMY, sEnemy, _Position);
		((EnemyBridge*)sEnemy)->SetMovement(_MoveType);
	}
	else if (_EnemyType == SMALLENEMY)
	{
		Bridge* sEnemy = new SmallEnemy;
		ObjectManager::GetInstance()->AddBridge(SMALLENEMY, sEnemy, _Position);
		((EnemyBridge*)sEnemy)->SetMovement(_MoveType);
	}
	else if (_EnemyType == BIGENEMY)
	{
		Bridge* sEnemy = new BigEnemy;
		ObjectManager::GetInstance()->AddBridge(BIGENEMY, sEnemy, _Position);
		((EnemyBridge*)sEnemy)->SetMovement(_MoveType);
	}

	else {	}
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

	// 보스
	else if (_EnemyType == STAGE1_BOSS_CORE)
	{
		Bridge* b1Core = new Stage1_Boss_Core;
		ObjectManager::GetInstance()->AddBridge(STAGE1_BOSS_CORE, b1Core, Vector3(_x, _y));
		((EnemyBridge*)b1Core)->SetMovement(_MoveType);

		Bridge* b1Head = new Stage1_Boss_Head;
		ObjectManager::GetInstance()->AddBridge(STAGE1_BOSS_HEAD, b1Head, Vector3(_x, _y - 4));

		Bridge* b1ArmL = new Stage1_Boss_Arm_Left;
		ObjectManager::GetInstance()->AddBridge
		(STAGE1_BOSS_ARM_LEFT, b1ArmL, Vector3(_x + 8, _y - 3));

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
	if (NormalEnemyList->begin() == NormalEnemyList->end() &&
		SmallEnemyList->begin() == SmallEnemyList->end() &&
		BigEnemyList->begin() == BigEnemyList->end())
		return true;

	return false;
}
