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
#include "UserInterface.h"

WeaponSelect::WeaponSelect() : pPlayer(nullptr), Selection(0) {}
WeaponSelect::~WeaponSelect() { Release(); }

void WeaponSelect::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->Initialize(PLAYER);
	pPlayer->SetPosition(39, 20);

	UserInstance::GetInstance()->SetBullet(NORMALBULLET);
	UserInstance::GetInstance()->SetBulletLevel(3);
}

void WeaponSelect::Update()
{
	MakePreview();

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

	if (SelectionAccept())
	{
		if (InputManager::GetInstance()->GetInputDelay() == 0)
		{
			UserInstance::GetInstance()->SetBulletLevel();
			SceneManager::GetInstance()->SetScene(STAGE1);
		}
	}

	// Go Back
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);
}

void WeaponSelect::Render()
{
	// Side Border
	UserInterface::MakeUI(10, 2, 30, 50);

	// Priview Border
	CursorManager::GetInstance()->WriteBuffer(31, 4, (char*)"Priview Weapon Lv.3");
	UserInterface::MakeUI(16, 7, 24, 15);


	// Weapon Select
	CursorManager::GetInstance()->WriteBuffer(28, 25, (char*)"Select Weapon With Start");

	UserInterface::MakeUI(24, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(28, 30, (char*)"в┴");

	UserInterface::MakeUI(46, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(50, 30, (char*)"е▒");

	// Selection
	switch (Selection)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(28, 35, (char*)"бу", 12);
		CursorManager::GetInstance()->WriteBuffer(33, 38, (char*)"<Normal Bullet>");
		CursorManager::GetInstance()->WriteBuffer(16, 40, (char*)"Basic Bullet");
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(50, 35, (char*)"бу", 12);
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
	RemovePlayerBullet();

	// Remove Player
	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList(PLAYER)->begin(), pPlayer);
}

void WeaponSelect::MakePreview()
{
	ObjectManager::GetInstance()->Update();
	pPlayer->SetPosition(39, 20);

	auto BulletList = ObjectManager::GetInstance()->GetObjectList(UserInstance::GetInstance()->GetBullet());

	// Shoot Bullet
	((Player*)pPlayer)->ShootBullet(7);

	// Priview Buffer Over Check
	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			int result = ((BulletBridge*)((*iter)->GetBridge()))->BulletPriview(17, 21, 9);

			if (result == BUFFER_OVER)
			{
				// Remove Bullet Data
				::Safe_Delete((*iter)->GetBridge());

				// Save in Disable List
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}
}

void WeaponSelect::SwitchBullet()
{
	RemovePlayerBullet();

	switch (Selection)
	{
	case 0:
		UserInstance::GetInstance()->SetBullet(NORMALBULLET);
		break;
	case 1:
		UserInstance::GetInstance()->SetBullet(LASERBULLET);
		break;
	default:
		break;
	}
}
