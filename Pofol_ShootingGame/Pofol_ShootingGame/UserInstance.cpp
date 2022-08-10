#include "UserInstance.h"

UserInstance* UserInstance::Instance = nullptr;
UserInstance::UserInstance() : Life(2), Boom(1), Score(0), BulletName("NormalBullet"), BulletLevel(2), GettingScore(0) {};
UserInstance::~UserInstance() {};

void UserInstance::Update()
{
	CalcScore();
}

void UserInstance::CalcScore()
{
	if (GettingScore != 0)
	{
		if (GettingScore > 1000)
		{
			Score = Score + 1000;
			GettingScore = GettingScore - 1000;
		}
		if (GettingScore > 100)
		{
			Score = Score + 100;
			GettingScore = GettingScore - 100;
		}
		if (GettingScore > 10)
		{
			Score = Score + 10;
			GettingScore = GettingScore - 10;
		}
		if (GettingScore != 0)
		{
			++Score;
			--GettingScore;
		}
	}
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
