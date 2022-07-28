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
	pObject->SetPosition(
		pObject->GetPosition().x + pObject->GetDirection().x,
		pObject->GetPosition().y + pObject->GetDirection().y
	);

	// BufferOver 체크
	if (BufferCheck())
		return BUFFER_OVER;

	return 0;
}

void ENormalBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y,
		Buffer[0], Color);
}

void ENormalBullet::Release()
{
}

void ENormalBullet::SetTarget(Vector3 _Target)
{
	pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), _Target));
}

void ENormalBullet::SetTarget(float _x, float _y)
{
	pObject->SetDirection(MathManager::GetDirection(pObject->GetPosition(), Vector3(_x, _y)));
}
