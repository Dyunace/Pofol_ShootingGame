#include "LaserBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "SceneManager.h"

LaserBullet::LaserBullet() : Count(1) {}
LaserBullet::~LaserBullet(){}

void LaserBullet::Initialize()
{ 
	Buffer[0] = (char*)"¥±";

	Damage = 1;
	Color = 13;
}

int LaserBullet::Update()
{
	auto player = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	if (player)
		pObject->SetPosition(player->GetPosition().x + TargetDirection.x, pObject->GetPosition().y);

	if (pObject->GetPosition().y < 0)
		return BUFFER_OVER;

	if (Count == 0)
		return BUFFER_OVER;

	--Count;

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
