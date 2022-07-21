#include "BulletManager.h"
#include "ObjectManager.h"
#include "UserInstance.h"

#include "NormalBullet.h"
#include "LaserBullet.h"
#include "ENormalBullet.h"

BulletManager* BulletManager::Instance = nullptr;
BulletManager::BulletManager(){}
BulletManager::~BulletManager(){}

void BulletManager::MakePlayerBullet(string _Key, Vector3 _Position, float _LimitY)
{
	int BulletLevel = UserInstance::GetInstance()->GetBulletLevel();

	BulletLevel = 3;

	if (_Key == NORMALBULLET)
	{
		// Lv.2
		if (BulletLevel >= 2)
		{
			Bridge* pBullet0 = new NormalBullet;
			ObjectManager::GetInstance()->AddBridge(NORMALBULLET, pBullet0, Vector3(_Position.x, _Position.y - 1));
			((BulletBridge*)pBullet0)->SetTarget(-0.5, 1);

			Bridge* pBullet1 = new NormalBullet;
			ObjectManager::GetInstance()->AddBridge(NORMALBULLET, pBullet1, Vector3(_Position.x, _Position.y - 1));
			((BulletBridge*)pBullet1)->SetTarget(0.5, 1);
		}

		// Lv.3
		if (BulletLevel >= 3)
		{
			Bridge* pBullet0 = new NormalBullet;
			ObjectManager::GetInstance()->AddBridge(NORMALBULLET, pBullet0, Vector3(_Position.x, _Position.y - 1));
			((BulletBridge*)pBullet0)->SetTarget(-1, 1);
			
			Bridge* pBullet1 = new NormalBullet;
			ObjectManager::GetInstance()->AddBridge(NORMALBULLET, pBullet1, Vector3(_Position.x, _Position.y - 1));
			((BulletBridge*)pBullet1)->SetTarget(1, 1);
		}

		// Lv.1
		Bridge* pBullet = new NormalBullet;
		ObjectManager::GetInstance()->AddBridge(NORMALBULLET, pBullet, Vector3(_Position.x, _Position.y - 1));
		((BulletBridge*)pBullet)->SetTarget(0, 1);
	}
	else if (_Key == LASERBULLET)
	{
		for (float i = _LimitY; i < _Position.y - 2; ++i)
		{
			// Lv. 1
			if (BulletLevel == 1 || BulletLevel == 3)
			{
				Bridge* pBullet = new LaserBullet;
				ObjectManager::GetInstance()->AddBridge(LASERBULLET, pBullet, Vector3(_Position.x, i));
				((BulletBridge*)pBullet)->SetTarget(0, 1);
			}
		
			// Lv.2
			if (BulletLevel == 2)
			{
				Bridge* pBullet0 = new LaserBullet;
				ObjectManager::GetInstance()->AddBridge(LASERBULLET, pBullet0, Vector3(_Position.x - 1, i));
				((BulletBridge*)pBullet0)->SetTarget(-1, 1);

				Bridge* pBullet1 = new LaserBullet;
				ObjectManager::GetInstance()->AddBridge(LASERBULLET, pBullet1, Vector3(_Position.x + 1, i));
				((BulletBridge*)pBullet1)->SetTarget(1, 1);
			}

			// Lv.3
			if (BulletLevel >= 3)
			{
				Bridge* pBullet0 = new LaserBullet;
				ObjectManager::GetInstance()->AddBridge(LASERBULLET, pBullet0, Vector3(_Position.x - 2, i));
				((BulletBridge*)pBullet0)->SetTarget(-2, 1);

				Bridge* pBullet1 = new LaserBullet;
				ObjectManager::GetInstance()->AddBridge(LASERBULLET, pBullet1, Vector3(_Position.x + 2, i));
				((BulletBridge*)pBullet1)->SetTarget(2, 1);
			}
		}

	}
}

void BulletManager::MakeEnemyBullet(string _Key, Vector3 _Position)
{
	if (_Key == ENORMALBULLET)
	{
		auto player = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

		Bridge* pBullet = new ENormalBullet;
		ObjectManager::GetInstance()->AddBridge(ENORMALBULLET, pBullet, Vector3(_Position.x, _Position.y + 1));

		// 플레이어 방향으로 날아감
		((BulletBridge*)pBullet)->SetTarget(player->GetPosition());
	}
	else if (_Key == ESPECIALBULLET)
	{

	}
}

