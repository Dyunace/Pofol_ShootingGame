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
	void MakePlayerBullet(string _key, Vector3 _Position);
};

