#pragma once
#include "Headers.h"

class Bridge;
class BulletManager
{
private:
	static BulletManager* Instance;
public:
	static BulletManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new BulletManager;

		return Instance;
	}
private:
	BulletManager();
public:
	~BulletManager();
public:
	void MakePlayerBullet(string _Key, Vector3 _Position, float _LimitY = 0);
	void MakeEnemyBullet(int _BulletType, Vector3 _Position);
};

