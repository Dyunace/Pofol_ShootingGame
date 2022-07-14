#include "LaserBullet.h"

LaserBullet::LaserBullet(){}
LaserBullet::LaserBullet(Transform _Info){}
LaserBullet::~LaserBullet(){}

Object* LaserBullet::Initialize(string _Key)
{ 
	str = "NormalBullet";

	Buffer[0] = (char*)"";

	BulletDamage = 1;
	Speed = 1;
	Color = 13;

	TransInfo.Position = Vector3(0, 0);
	TransInfo.Rotation = Vector3(0, 0);
	TransInfo.Scale = Vector3(2, 1); // ÅºÈ¯ÀÇ Å©±â

	return nullptr;
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

void LaserBullet::ShootBullet()
{
}
