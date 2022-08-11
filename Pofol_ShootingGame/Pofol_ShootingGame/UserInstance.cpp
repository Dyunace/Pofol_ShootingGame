#include "UserInstance.h"

UserInstance* UserInstance::Instance = nullptr;
UserInstance::UserInstance() : Life(2), Boom(1), Score(0), BulletName("NormalBullet"), BulletLevel(2), GettingScore(0) {};
UserInstance::~UserInstance() {};

void UserInstance::Update()
{
	if (GettingScore != 0)
	{
		if (GettingScore > 5000)
			CalcScore(1000);
		else if (GettingScore > 1000)
			CalcScore(500);

		if (GettingScore > 500)
			CalcScore(100);
		else if (GettingScore > 100)
			CalcScore(50);

		if (GettingScore > 50)
			CalcScore(10);
		else if (GettingScore > 10)
			CalcScore(5);

		if (GettingScore != 0)
			CalcScore();
	}
}

void UserInstance::CalcScore(int _Score)
{
	Score = Score + _Score;
	GettingScore = GettingScore - _Score;
}

void UserInstance::SkipCalcScore()
{
	Score = Score + GettingScore;
	GettingScore = 0;
}

void UserInstance::ResetInstance()
{
	Life = 2;
	Boom = 1;

	BulletName = "NormalBullet";
	BulletLevel = 1;

	Score = 0;
	GettingScore = 0;
}
