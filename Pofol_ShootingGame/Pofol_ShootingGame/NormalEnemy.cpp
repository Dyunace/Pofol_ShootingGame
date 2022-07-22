#include "NormalEnemy.h"
#include "CursorManager.h"
#include "BulletManager.h"

NormalEnemy::NormalEnemy() : Buffer() {}
NormalEnemy::~NormalEnemy(){}

void NormalEnemy::Initialize()
{
	Buffer[0] = (char*)"┏";
	Buffer[1] = (char*)"┓";
	Buffer[2] = (char*)"Ⅵ";
	Buffer[3] = (char*)"Ⅳ";

	Hp = 10;
	MoveSpeed = 0.25f;
	pBullet = ENORMALBULLET;
}

int NormalEnemy::Update()
{
	auto Pos = pObject->GetPosition();

	Movement();

	if (ShootDelay < 0)
		ShootBullet();

	--ShootDelay;

	if (BufferCheck())
		return BUFFER_OVER;

	return 0;
}

void NormalEnemy::Render()
{
	for (int i = 0; i < 4; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x + (i % 2 * 2),
			pObject->GetPosition().y + (i / 2),
			Buffer[i]
		);

	// 체력 표시
	CursorManager::GetInstance()->WriteBuffer
	(pObject->GetPosition().x, pObject->GetPosition().y - 1,GetHP());

	// 이동 타입 표시
	CursorManager::GetInstance()->WriteBuffer
	(pObject->GetPosition().x, pObject->GetPosition().y - 2, GetMoveType());
}

void NormalEnemy::Release()
{
}

void NormalEnemy::ShootBullet()
{
	BulletManager::GetInstance()->MakeEnemyBullet(pBullet, pObject->GetPosition());

	ShootDelay = 60;
}

void NormalEnemy::SetMovement(int _Type)
{
	MoveType = _Type;
}
