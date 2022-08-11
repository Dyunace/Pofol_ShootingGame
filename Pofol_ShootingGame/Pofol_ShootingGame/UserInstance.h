#pragma once
#include "Headers.h"

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
private:
	int Life;
	int Boom;
	int Score;
	string BulletName;
	int BulletLevel;

	int GettingScore;
public:
	void Update();
public:
	int GetLife() { return Life; }
	void AddLife(int _Num = 1) { Life += _Num; }

	int GetBoom() { return Boom; }
	void SetBoom(int _Num = 1) { Boom = _Num; }
	void AddBoom(int _Num = 1) { Boom += _Num; }

	string GetBullet() { return BulletName; }
	void SetBullet(string _str) { BulletName = _str; }

	int GetBulletLevel() { return BulletLevel; }
	void SetBulletLevel(int _val = 1) { BulletLevel = _val; }
	void AddBulletLevel(int _Num = 1) { BulletLevel += _Num; }

	int GetScore() { return Score; }
	int GetGettingScore() { return GettingScore; }
	void AddScore(int _Num) { GettingScore += _Num; }

public:
	void CalcScore(int _Score = 1);
	void SkipCalcScore();

	void ResetInstance();
};

