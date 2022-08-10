#include "WeaponSelect.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"
#include "CursorManager.h"

#include "Player.h"

#include "NormalBullet.h"
#include "LaserBullet.h"

#include "UserInstance.h"
#include "UserInterface.h"

WeaponSelect::WeaponSelect() : pPlayer(nullptr), Selection(0), BulletList(nullptr) {}
WeaponSelect::~WeaponSelect() { Release(); }

void WeaponSelect::Initialize()
{
	ObjectManager::GetInstance()->AddObject(PLAYER);
	pPlayer = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();
	pPlayer->Initialize(PLAYER);
	pPlayer->SetPosition(39, 20);

	UserInstance::GetInstance()->ResetInstance();
	UserInstance::GetInstance()->SetBulletLevel(3);

	BulletList = ObjectManager::GetInstance()->GetObjectList(UserInstance::GetInstance()->GetBullet());
}

void WeaponSelect::Update()
{
	// 프리뷰 생성
	MakePreview();

	// 조작 키 입력
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

	// 선택
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

	if (!BulletList)
		SwitchBullet();
}

void WeaponSelect::Render()
{
	// Side Border
	UserInterface::GetInstance()->MakeUI(10, 2, 30, 50);

	// Priview Border
	CursorManager::GetInstance()->WriteBuffer(31, 4, (char*)"Priview Weapon Lv.3");
	UserInterface::GetInstance()->MakeUI(16, 7, 24, 15);


	// Weapon Select
	CursorManager::GetInstance()->WriteBuffer(28, 25, (char*)"Select Weapon With Start");

	// show bullet
	UserInterface::GetInstance()->MakeUI(24, 28, 5, 5);
	CursorManager::GetInstance()->WriteBuffer(28, 30, (char*)"⊙");

	UserInterface::GetInstance()->MakeUI(46, 28, 5, 5);
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

	// 오브젝트 렌더
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
	// 오브젝트 업데이트 및 플레이어 위치 고정
	ObjectManager::GetInstance()->Update();
	pPlayer->SetPosition(39, 20);

	// Shoot Bullet
	((Player*)pPlayer)->ShootBullet(8);

	// Priview Buffer Over Check
	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			auto target = (*iter);

			int result = ((BulletBridge*)target->GetBridge())->PriviewCheck(16, 64, 7);

			if (result == BUFFER_OVER)
				RemoveObject(iter);
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

	BulletList = ObjectManager::GetInstance()->GetObjectList(UserInstance::GetInstance()->GetBullet());
}
