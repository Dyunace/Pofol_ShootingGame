#include "BulletManager.h"
#include "ObjectManager.h"
#include "UserInstance.h"

#include "NormalBullet.h"
#include "LaserBullet.h"
#include "Boom.h"

#include "ENormalBullet.h"

BulletManager* BulletManager::Instance = nullptr;
BulletManager::BulletManager(){}
BulletManager::~BulletManager(){}

void BulletManager::MakePlayerBullet(string _Key, Vector3 _Position, float _LimitY)
{
	int BulletLevel = UserInstance::GetInstance()->GetBulletLevel();

	// �����
	BulletLevel = 3;

	float PosX = _Position.x;
	float PosY = ((_Position.y * 100) / 100) - 2;

	if (_Key == NORMALBULLET)
	{
		// Lv.2
		if (BulletLevel >= 2)
		{
			for (float f = 0.0f; f < 2; ++f)
			{
				Bridge* pBullet = new NormalBullet;
				ObjectManager::GetInstance()->AddBridge(_Key, pBullet, Vector3(PosX, PosY));
				((BulletBridge*)pBullet)->SetTarget(-1.0f + (f * 2), 1.0f);
			}
		}

		// Lv.3
		if (BulletLevel >= 3)
		{
			for (float f = 0; f < 2; ++f)
			{
				Bridge* pBullet = new NormalBullet;
				ObjectManager::GetInstance()->AddBridge(_Key, pBullet, Vector3(PosX, PosY));
				((BulletBridge*)pBullet)->SetTarget(-2.0f + (f * 4), 1.0f);
			}
		}

		// Lv.1
		Bridge* pBullet = new NormalBullet;
		ObjectManager::GetInstance()->AddBridge(_Key, pBullet, Vector3(PosX, PosY));
		((BulletBridge*)pBullet)->SetTarget(0.0f, 1.0f);
	}
	else if (_Key == LASERBULLET)
	{
		for (auto i = _LimitY; i < PosY; ++i)
		{
			// Lv. 1
			if (BulletLevel == 1)
			{
				Bridge* pBullet = new LaserBullet;
				ObjectManager::GetInstance()->AddBridge(_Key, pBullet, Vector3(PosX, i));
				((BulletBridge*)pBullet)->SetTarget(0.0f, 1.0f);
			}
		
			// Lv.2
			if (BulletLevel == 2)
			{
				for (float f = 0; f < 2; ++f)
				{
					Bridge* pBullet = new LaserBullet;
					ObjectManager::GetInstance()->AddBridge(
						_Key, pBullet, Vector3(PosX - 1 + (f * 2), i));
					((BulletBridge*)pBullet)->SetTarget(-1.0f + (f * 2), 1.0f);
				}
			}

			// Lv.3
			if (BulletLevel >= 3)
			{
				for (float f = 0; f < 3; ++f)
				{
					Bridge* pBullet = new LaserBullet;
					ObjectManager::GetInstance()->AddBridge(
						_Key, pBullet, Vector3(PosX - 2 + (f * 2), i));
					((BulletBridge*)pBullet)->SetTarget(-2.0f + (f * 2), 1.0f);
				}
			}
		}
	}
	else if (_Key == BOOM)
	{
		Bridge* pBoom = new Boom;
		ObjectManager::GetInstance()->AddBridge(
			_Key, pBoom, Vector3(PosX, PosY - 2)
		);
	}

	else {}
}

void BulletManager::MakeEnemyBullet(int _BulletType, Vector3 _Position)
{
	auto player = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	if (_BulletType == 1)
	{
		// �� �߸� ��� (����)
		Bridge* pBullet = new ENormalBullet;
		ObjectManager::GetInstance()->AddBridge(
			ENORMALBULLET, pBullet, Vector3(_Position.x, _Position.y + 1));

		((BulletBridge*)pBullet)->SetTarget(
			player->GetPosition().x,
			player->GetPosition().y
		);
	}
	else if (_BulletType == 2)
	{
		// �� �� ��� (����, �񽺵��ϰ� ������)
		for (int i = 0; i < 2; ++i)
		{
			Bridge* pBullet = new ENormalBullet;
			ObjectManager::GetInstance()->AddBridge(
				ENORMALBULLET,
				pBullet,
				Vector3(_Position.x - 1 + (i * 2), _Position.y + 1)
			);

			((BulletBridge*)pBullet)->SetTarget(
				player->GetPosition().x - 4 + (i * 8),
				player->GetPosition().y
			);
		}
	}
	else if (_BulletType == 3)
	{
		// �� �� ��� (����)
		for (int i = 0; i < 3; ++i)
		{
			Bridge* pBullet = new ENormalBullet;
			ObjectManager::GetInstance()->AddBridge(
				ENORMALBULLET,
				pBullet,
				Vector3(_Position.x - 2 + (i * 2), _Position.y + 1.5f)
			);

			((BulletBridge*)pBullet)->SetTarget(
				player->GetPosition().x - 6 + (i * 6),
				player->GetPosition().y
			);
		}
	}
	else { }
}

