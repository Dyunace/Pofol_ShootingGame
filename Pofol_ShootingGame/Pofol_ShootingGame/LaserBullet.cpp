#include "LaserBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"

LaserBullet::LaserBullet() : Count(1) {}
LaserBullet::~LaserBullet(){}

void LaserBullet::Initialize()
{ 
	Buffer[0] = (char*)"Ⅱ";

	Damage = 3;
	Color = 13;
}

int LaserBullet::Update()
{
	auto player = ObjectManager::GetInstance()->GetObjectList(PLAYER)->front();

	// Player의 위치에 따라 함께 이동
	if (player)
		pObject->SetPosition(
			pObject->GetDirection().x + player->GetPosition().x, pObject->GetPosition().y);

	if (BufferCheck())
		return BUFFER_OVER;

	if (Count == 0)
		return BUFFER_OVER;

	--Count;

	return 0;
}

void LaserBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y,
		Buffer[0], Color);
}

void LaserBullet::Release()
{
}

void LaserBullet::SetTarget(Vector3 _Target)
{
	pObject->SetDirection(_Target);
}

void LaserBullet::SetTarget(float _x, float _y)
{
	pObject->SetDirection(_x, _y);
}
