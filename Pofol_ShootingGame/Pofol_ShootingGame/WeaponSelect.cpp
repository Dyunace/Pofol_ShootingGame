#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ObjectManager.h"

// 할 일 : 무기 선택 창에서 무기에 따라 총알 발사하게 하기

WeaponSelect::WeaponSelect() : pPlayer(nullptr) {}
WeaponSelect::WeaponSelect(string* _str) : pPlayer(nullptr){}
WeaponSelect::~WeaponSelect(){}

void WeaponSelect::Initialize()
{
	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	pPlayer->Initialize("Player");
	pPlayer->SetPosition(39, 23);
}

void WeaponSelect::Update()
{
	// 뒤로 가기
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);

	auto BulletList = ObjectManager::GetInstance()->GetObjectList(pPlayer->GetBullet());

	// 총알 생성
	if (pPlayer->GetBullet() == NORMALBULLET)
	{
		Bridge* pBullet = new NormalBullet;
		ObjectManager::GetInstance()->AddBullet(NORMALBULLET, pBullet,
			Vector3(pPlayer->GetPosition().x, pPlayer->GetPosition().y - 1));
	}
	else if (pPlayer->GetBullet() == LASERBULLET)
	{
		Bridge* pBullet = new LaserBullet;
		ObjectManager::GetInstance()->AddBullet(LASERBULLET, pBullet,
			Vector3(pPlayer->GetPosition().x, pPlayer->GetPosition().y - 1));
	}

	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			// 총알만 작동
			(*iter)->Update();
			int result = (*iter)->GetBridge()->BulletPriview(7);

			if (result == BUFFER_OVER)
			{
				// 총알 정보 삭제
				::Safe_Delete((*iter)->GetBridge());

				// DisableList에 보관
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}
}

void WeaponSelect::Render()
{
	// 외부 보드
	MakeBorder(10, 3, 30, 15);
	CursorManager::GetInstance()->WriteBuffer(28, 5, (char*)"Select Weapon With Start");

	// 내부 보드
	MakeBorder(16, 7, 24, 5);

	ObjectManager::GetInstance()->Render();
}

void WeaponSelect::Release()
{
	// 다 쓴 플레이어는 DisableList에 반환
	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList("Player")->begin(), pPlayer);
}
