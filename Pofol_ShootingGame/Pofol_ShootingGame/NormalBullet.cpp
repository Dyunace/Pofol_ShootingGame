#include "NormalBullet.h"
#include "CursorManager.h"

NormalBullet::NormalBullet() {}
NormalBullet::~NormalBullet(){}

void NormalBullet::Initialize()
{
	Buffer[0] = (char*)"??";

	Damage = 2;
	Color = 13;
}

int NormalBullet::Update()
{
	// ?̵?
	pObject->SetPosition(pObject->GetPosition().x + TargetDirection.x, pObject->GetPosition().y - 1);

	// BufferOver üũ
	if (BufferCheck())
		return BUFFER_OVER;

	return 0;
}

void NormalBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), Buffer[0], Color);
}

void NormalBullet::Release()
{
}

void NormalBullet::SetTarget(Vector3 _Target)
{
	TargetDirection = _Target;
}

void NormalBullet::SetTarget(float _x, float _y)
{
	TargetDirection = Vector3(_x, _y);
}
