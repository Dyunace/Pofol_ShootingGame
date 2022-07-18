#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"

NormalBullet::NormalBullet() {}
NormalBullet::~NormalBullet(){}

void NormalBullet::Initialize()
{
	Buffer[0] = (char*)"¢Á";

	Damage = 1;
	Speed = 2;
	Color = 13;
}

int NormalBullet::Update()
{
	pObject->SetPosition(pObject->GetPosition().x, pObject->GetPosition().y - 1);

	if (pObject->GetPosition().y < 0)
	{
		CursorManager::GetInstance()->WriteBuffer(0, 5, (char*)"Bullet Buffer Over");
		return BUFFER_OVER;
	}

	return 0;
}

void NormalBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), Buffer[0], Color);
}

void NormalBullet::Release()
{
}