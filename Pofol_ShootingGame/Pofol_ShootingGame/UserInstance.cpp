#include "UserInstance.h"

UserInstance::UserInstance() : Life(0), Score(0), Boom(0), BulletLevel(0) {}
UserInstance::~UserInstance(){}

void UserInstance::Initialize()
{

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

