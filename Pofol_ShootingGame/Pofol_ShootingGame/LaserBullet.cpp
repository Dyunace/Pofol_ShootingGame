#include "LaserBullet.h"
#include "CursorManager.h"
#include "MathManager.h"

LaserBullet::LaserBullet(){}
LaserBullet::~LaserBullet(){}

void LaserBullet::Initialize()
{ 
	Buffer[0] = (char*)"¥±";

	Damage = 1;
	Color = 13;
}

int LaserBullet::Update()
{
	pObject->SetPosition(pObject->GetPosition().x + TargetDirection.x, pObject->GetPosition().y - TargetDirection.y);

	if (pObject->GetPosition().y < 0)
		return BUFFER_OVER;

	return 0;
}

void LaserBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), Buffer[0], Color);
}

void LaserBullet::Release()
{
}

void LaserBullet::SetTarget(Vector3 _Target)
{
	TargetDirection = _Target;
}

void LaserBullet::SetTarget(float _x, float _y)
{
	TargetDirection = Vector3(_x, _y);
}
