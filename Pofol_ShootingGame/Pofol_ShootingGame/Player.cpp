#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalBullet.h"

Player::Player() {}
Player::Player(Transform _Info) : Object(_Info) {}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	str = _Key;

	// Buffer[4] 코어를 기준으로 함
	Buffer[0] = (char*)"┏";
	Buffer[1] = (char*)"Π";
	Buffer[2] = (char*)"┓";
	Buffer[3] = (char*)"┻";
	Buffer[4] = (char*)"⊙";
	Buffer[5] = (char*)"┻";

	TransInfo.Position = Vector3(0, 0);
	TransInfo.Rotation = Vector3(0, 0);
	TransInfo.Scale = Vector3(2, 1); // 코어의 크기

	Bullet = BULLET::BNORMAL;

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 1;

	if (dwKey & KEY_SPACE)
	{
		switch (Bullet)
		{
		case BULLET::BNORMAL:
			ObjectManager::GetInstance()->AddBullet("NormalBullet", Vector3(TransInfo.Position.x, TransInfo.Position.y - 1));
			break;
		case BULLET::BLASER:
			break;
		default:
			break;
		}
	}

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 6; ++i)
		CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x + (i % 3  * 2) - 2, TransInfo.Position.y + (i / 3) - 1, Buffer[i]);
}

void Player::Release()
{
}

void Player::ShootBullet()
{
}

void Player::SetBullet(BULLET _Weapon)
{
	Bullet = _Weapon;
}
