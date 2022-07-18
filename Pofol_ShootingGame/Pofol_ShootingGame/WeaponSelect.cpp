#include "WeaponSelect.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ObjectManager.h"

// �� �� : ���� ���� â���� ���⿡ ���� �Ѿ� �߻��ϰ� �ϱ�

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
	// �ڷ� ����
	if (InputManager::GetInstance()->GetKey() & KEY_ESC)
		SceneManager::GetInstance()->SetScene(MENU);

	auto BulletList = ObjectManager::GetInstance()->GetObjectList(pPlayer->GetBullet());

	// �Ѿ� ����
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
			// �Ѿ˸� �۵�
			(*iter)->Update();
			int result = (*iter)->GetBridge()->BulletPriview(7);

			if (result == BUFFER_OVER)
			{
				// �Ѿ� ���� ����
				::Safe_Delete((*iter)->GetBridge());

				// DisableList�� ����
				iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
			}
		}
	}
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
	// �� �� �÷��̾�� DisableList�� ��ȯ
	ObjectManager::GetInstance()->ThrowObject(ObjectManager::GetInstance()->GetObjectList("Player")->begin(), pPlayer);
}
