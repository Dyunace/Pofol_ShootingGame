#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"

NormalBullet::NormalBullet() {}
NormalBullet::~NormalBullet(){}

void NormalBullet::Initialize()
{
	Buffer[0] = (char*)"⊙";

	Damage = 1;
	Color = 13;
}

int NormalBullet::Update()
{
	// 이동
	pObject->SetPosition(pObject->GetPosition().x + TargetDirection.x, pObject->GetPosition().y - TargetDirection.y);

	// BufferOver 체크
	if (pObject->GetPosition().y < 0)
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
