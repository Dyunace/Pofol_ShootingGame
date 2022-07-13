#pragma once
#include "Headers.h"

class Player;
class Bullet;
class UserInstance
{
private:
	static UserInstance* Instance;
public:
	static UserInstance* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new UserInstance;
		return Instance;
	}
private:
	UserInstance();
public:
	~UserInstance();
public:
	void Initialize();
public:
	Player* GetPlayer();
	void SetPlayer(Player* _Player);

	Bullet* GetBullet();
	void SetBullet(Bullet* _Bullet);
private:
	int Life;
	int Boom;
	int Score;
	string BulletName;
	int BulletLevel;
};

