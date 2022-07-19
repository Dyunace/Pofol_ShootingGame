#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ObjectManager.h"
#include "ObjectPool.h"

WeaponSelect::WeaponSelect() : pPlayer(nullptr), Selection(0) {}
WeaponSelect::~WeaponSelect() { Release(); }

void WeaponSelect::Initialize()
{
	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	pPlayer->Initialize("Player");
	pPlayer->SetPosition(39, 20);
}

void WeaponSelect::Update()
{
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());

	// Shoot Bullet
	((Player*)pPlayer)->ShootBullet();

	// Priview Buffer Over Check
	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			(*iter)->Update();
			int result = ((BulletBridge*)((*iter)->GetBridge()))->BulletPriview(16, 24, 7);

			if (result == BUFFER_OVER)
			{
				// Remove Bullet Data
				::Safe_Delete((*iter)->GetBridge());

				// Save in Disable List
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}

	if (InputManager::GetInstance()->GetKey() & KEY_RIGHT && Selection < 1)
	{
		ReleaseBullet();
		++Selection;
		SwitchBullet();
	}

	if (InputManager::GetInstance()->GetKey() & KEY_LEFT && Selection > 0)
	{
		ReleaseBullet();
		--Selection;
		SwitchBullet();
	}

	if (InputManager::GetInstance()->GetKey() & KEY_F || InputManager::GetInstance()->GetKey() & KEY_ENTER)
	{
		// 여기에 스테이지 넘어가기 만들기
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
	CursorManager::GetInstance()->WriteBuffer(38, 4, (char*)"Priview");
	MakeBorder(16, 7, 24, 15);


	// Weapon Select
	CursorManager::GetInstance()->WriteBuffer(28, 25, (char*)"Select Weapon With Start");

	MakeBorder(24, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(28, 30, (char*)"⊙");

	MakeBorder(46, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(50, 30, (char*)"Ⅱ");

	// Selection
	if (Selection == 0)
	{
		CursorManager::GetInstance()->WriteBuffer(28, 35, (char*)"▲", 12);

	}
	else if (Selection == 1)
	{
		CursorManager::GetInstance()->WriteBuffer(48, 35, (char*)"▲", 12);

	}

	ObjectManager::GetInstance()->Render();
}

void WeaponSelect::Release()
{
	// Remove Bullet
	ReleaseBullet();

	// Remove Player
	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList("Player")->begin(), pPlayer);
}

void WeaponSelect::SwitchBullet()
{
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
