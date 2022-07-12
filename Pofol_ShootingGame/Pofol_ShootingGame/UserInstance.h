#pragma once
#include "Headers.h"

class Player;
class Bullet;
class UserInstance
{
public:
	UserInstance();
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
	int BulletLevel;
};

