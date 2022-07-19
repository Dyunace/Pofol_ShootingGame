#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ObjectManager.h"
#include "ObjectPool.h"

// 할 일 : 무기 선택 창에서 무기에 따라 총알 발사하게 하기

WeaponSelect::WeaponSelect() : pPlayer(nullptr) {}
WeaponSelect::WeaponSelect(string* _str) : pPlayer(nullptr){}
WeaponSelect::~WeaponSelect() { Release(); }

void WeaponSelect::Initialize()
{
	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	pPlayer->Initialize("Player");
	pPlayer->SetPosition(39, 23);
}

void WeaponSelect::Update()
{
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());

	// 총알 발사
	((Player*)pPlayer)->ShootBullet();

	// Priview BufferOver 체크
	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			(*iter)->Update();
			int result = ((BulletBridge*)((*iter)->GetBridge()))->BulletPriview(17, 61, 7);

			if (result == BUFFER_OVER)
			{
				// 총알 정보 삭제
				::Safe_Delete((*iter)->GetBridge());

				// DisableList에 보관
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}

	// 뒤로 가기
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);
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
	auto BulletList = ObjectManager::GetInstance()->GetObjectList(((Player*)pPlayer)->GetBullet());

	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end();)
		{
			if (*iter)
			{
				// 총알 정보 삭제
				::Safe_Delete((*iter)->GetBridge());

				// DisableList에 보관
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
			else
				++iter;
		}
	}

	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList("Player")->begin(), pPlayer);
}
