#include "NormalBullet.h"
#include "CursorManager.h"

NormalBullet::NormalBullet() {}
NormalBullet::~NormalBullet(){}

void NormalBullet::Initialize()
{
	Buffer[0] = (char*)"⊙";

	Damage = 4;
	Color = 13;
	Speed = 2.0f;
}

int NormalBullet::Update()
{
	// 이동
	pObject->SetPosition(
		pObject->GetPosition().x + pObject->GetDirection().x, 
		pObject->GetPosition().y - Speed);

	// BufferOver 체크
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
	pObject->SetDirection(_Target);
}

void NormalBullet::SetTarget(float _x, float _y)
{
	pObject->SetDirection(_x, _y);
}
