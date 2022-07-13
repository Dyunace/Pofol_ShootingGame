#include "UserInstance.h"

UserInstance* UserInstance::Instance = nullptr;
UserInstance::UserInstance() : Life(0), Score(0), Boom(0), BulletName("NormalBullet"), BulletLevel(0) {}
UserInstance::~UserInstance(){}

void UserInstance::Initialize()
{
	Life = 3;
	Score = 0;
	Boom = 2;
	BulletName = "NormalBullet";
	BulletLevel = 1;
}

Player* UserInstance::GetPlayer()
{
	return nullptr;
}

void UserInstance::SetPlayer(Player* _Player)
{
}

Bullet* UserInstance::GetBullet()
{
	return nullptr;
}

void UserInstance::SetBullet(Bullet* _Bullet)
{
}

