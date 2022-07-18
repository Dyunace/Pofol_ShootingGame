#include "LaserBullet.h"

LaserBullet::LaserBullet(){}
LaserBullet::~LaserBullet(){}

void LaserBullet::Initialize()
{ 
	Buffer[0] = (char*)"";

	Damage = 1;
	Speed = 1;
	Color = 13;
}

int LaserBullet::Update()
{
	return 0;
}

void LaserBullet::Render()
{
}

void LaserBullet::Release()
{
}
