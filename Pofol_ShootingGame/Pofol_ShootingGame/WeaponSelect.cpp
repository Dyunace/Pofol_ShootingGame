#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ObjectManager.h"
#include "ObjectPool.h"

// �� �� : ���� ���� â���� ���⿡ ���� �Ѿ� �߻��ϰ� �ϱ�

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

	// �Ѿ� �߻�
	((Player*)pPlayer)->ShootBullet();

	// Priview BufferOver üũ
	if (BulletList)
	{
		for (auto iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			(*iter)->Update();
			int result = ((BulletBridge*)((*iter)->GetBridge()))->BulletPriview(17, 61, 7);

			if (result == BUFFER_OVER)
			{
				// �Ѿ� ���� ����
				::Safe_Delete((*iter)->GetBridge());

				// DisableList�� ����
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}

	// �ڷ� ����
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);
}

void WeaponSelect::Render()
{
	// �ܺ� ����
	MakeBorder(10, 3, 30, 15);
	CursorManager::GetInstance()->WriteBuffer(28, 5, (char*)"Select Weapon With Start");

	// ���� ����
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
				// �Ѿ� ���� ����
				::Safe_Delete((*iter)->GetBridge());

				// DisableList�� ����
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
			else
				++iter;
		}
	}

	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList("Player")->begin(), pPlayer);
}
