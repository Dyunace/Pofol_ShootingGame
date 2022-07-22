#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalEnemy.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ObjectManager.h"
#include "ObjectPool.h"
#include "UserInstance.h"

WeaponSelect::WeaponSelect() : pPlayer(nullptr), Selection(0) {}
WeaponSelect::~WeaponSelect() { Release(); }

void WeaponSelect::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->Initialize(PLAYER);
	pPlayer->SetPosition(39, 20);
}

void WeaponSelect::Update()
{
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());

	ObjectPool::GetInstance()->DedugRender();

	// Shoot Bullet
	((Player*)pPlayer)->ShootBullet(7);

	ObjectManager::GetInstance()->Update();
	pPlayer->SetPosition(39, 20);

	// Priview Buffer Over Check
	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			int result = ((BulletBridge*)((*iter)->GetBridge()))->BulletPriview(17, 21, 8);
	
			if (result == BUFFER_OVER)
			{
				CursorManager::GetInstance()->WriteBuffer((*iter)->GetPosition(), (char*)"B_O");

				// Remove Bullet Data
				::Safe_Delete((*iter)->GetBridge());
	
				// Save in Disable List
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}

	if (InputManager::GetInstance()->GetKey() & KEY_RIGHT && Selection < 1)
	{
		++Selection;
		SwitchBullet();
	}
	if (InputManager::GetInstance()->GetKey() & KEY_LEFT && Selection > 0)
	{
		--Selection;
		SwitchBullet();
	}

	if (InputManager::GetInstance()->GetKey() & KEY_F || InputManager::GetInstance()->GetKey() & KEY_ENTER)
	{
		// 여기에 스테이지 넘어가기 만들기
		UserInstance::GetInstance()->SetBullet(((Player*)pPlayer)->GetBullet());
		SceneManager::GetInstance()->SetScene(STAGE1);
	}

	// Go Back
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);
}

void WeaponSelect::Render()
{
	// Side Border
	MakeBorder(10, 2, 30, 50);

	// Priview Border
	CursorManager::GetInstance()->WriteBuffer(31, 4, (char*)"Priview Weapon Lv.3");
	MakeBorder(16, 7, 24, 15);


	// Weapon Select
	CursorManager::GetInstance()->WriteBuffer(28, 25, (char*)"Select Weapon With Start");

	MakeBorder(24, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(28, 30, (char*)"⊙");

	MakeBorder(46, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(50, 30, (char*)"Ⅱ");

	// Selection
	switch (Selection)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(28, 35, (char*)"▲", 12);
		CursorManager::GetInstance()->WriteBuffer(33, 38, (char*)"<Normal Bullet>");
		CursorManager::GetInstance()->WriteBuffer(16, 40, (char*)"Basic Bullet");
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(50, 35, (char*)"▲", 12);
		CursorManager::GetInstance()->WriteBuffer(34, 38, (char*)"<Laser Bullet>");
		CursorManager::GetInstance()->WriteBuffer(16, 40, (char*)"Small attack range, fast attack speed");
		break;
	default:
		break;
	}

	ObjectManager::GetInstance()->Render();
}

void WeaponSelect::Release()
{
	// Remove Bullet
	ReleaseBullet();

	// Remove Player
	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList(PLAYER)->begin(), pPlayer);
}

void WeaponSelect::SwitchBullet()
{
	ReleaseBullet();

	switch (Selection)
	{
	case 0:
		((Player*)pPlayer)->SetBullet(NORMALBULLET);
		break;
	case 1:
		((Player*)pPlayer)->SetBullet(LASERBULLET);
		break;
	default:
		break;
	}
}

void WeaponSelect::ReleaseBullet()
{
	// Remove All Bullets in Screen
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());

	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end();)
		{
			if (*iter)
			{
				// Remove Bullet Data
				::Safe_Delete((*iter)->GetBridge());

				// Save in Disable List
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
			else
				++iter;
		}
	}
}
