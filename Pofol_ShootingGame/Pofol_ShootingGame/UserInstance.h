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
	int GetLife() { return Life; }
	void AddLife(int _Num) { Life += _Num; }

	int GetBoom() { return Boom; }
	void AddBoom(int _Num) { Boom += _Num; }

	int GetScore() { return Score; }
	void AddScore(int _Num) { Score += _Num; }

	string GetBullet() { return BulletName; }
	void SetBullet(string _str) { BulletName = _str; }

	int GetBulletLevel() { return BulletLevel; }
	void AddBulletLevel(int _Num) { BulletLevel += _Num; }

private:
	int Life;
	int Boom;
	int Score;
	string BulletName;
	int BulletLevel;
};

