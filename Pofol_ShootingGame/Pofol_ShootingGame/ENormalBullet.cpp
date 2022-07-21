#include "ENormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"

ENormalBullet::ENormalBullet(){}
ENormalBullet::~ENormalBullet(){}

void ENormalBullet::Initialize()
{
	Buffer[0] = (char*)"▼";

	Damage = 1;
	Color = 12;
}

int ENormalBullet::Update()
{
	// 이동
	pObject->SetPosition(pObject->GetPosition().x + TargetDirection.x, pObject->GetPosition().y + TargetDirection.y);

	// BufferOver 체크
	if (BufferCheck())
		return BUFFER_OVER;

	return 0;
}

void ENormalBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), Buffer[0], Color);
}

void ENormalBullet::Release()
{
}

void ENormalBullet::SetTarget(Vector3 _Target)
{
	TargetDirection = MathManager::GetDirection(pObject->GetPosition(), _Target);
}

void ENormalBullet::SetTarget(float _x, float _y)
{
	TargetDirection = MathManager::GetDirection(pObject->GetPosition(), Vector3(_x, _y));
}
