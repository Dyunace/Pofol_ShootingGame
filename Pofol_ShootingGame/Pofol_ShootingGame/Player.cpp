#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "BulletManager.h"

Player::Player() : pBullet(), BoomDelayCount(0)
{
	for (int i = 0; i < 6; ++i)
		Buffer[i] = nullptr;
}
Player::Player(Transform _Info) : Object(_Info), Buffer() {}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	str = _Key;

	pBullet = NORMALBULLET;

	// Buffer[4] 코어가 기준
	Buffer[0] = (char*)"┏";
	Buffer[1] = (char*)"Π";
	Buffer[2] = (char*)"┓";
	Buffer[3] = (char*)"┻";
	Buffer[4] = (char*)"⊙";
	Buffer[5] = (char*)"┻";

	TransInfo.Position = Vector3(0, 0);
	TransInfo.Rotation = Vector3(0, 0);
	TransInfo.Scale = Vector3(2.0f, 1.0f); // 코어의 크기

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	// 이동
	if (dwKey & KEY_UP && TransInfo.Position.y - TransInfo.Scale.y > 0)
		TransInfo.Position.y -= 1.0;	// 위로 이동 시 감속
	if (dwKey & KEY_DOWN && TransInfo.Position.y + TransInfo.Scale.y < ConsoleHeightSize)
		TransInfo.Position.y += 1.0;	// 아래로 이동 시 가속
	if (dwKey & KEY_LEFT && TransInfo.Position.x - TransInfo.Scale.x > 0)
		TransInfo.Position.x -= 1.5;
	if (dwKey & KEY_RIGHT && TransInfo.Position.x + TransInfo.Scale.x * 2 < ConsoleWidthSize)
		TransInfo.Position.x += 1.5;

	// 공격 (F버튼)
	if (dwKey & KEY_F || dwKey & KEY_SPACE)
		ShootBullet();

	if (dwKey & KEY_D)
		ShootBoom();

	if (DelayCount > 0)
		--DelayCount;
	if (BoomDelayCount > 0)
		--BoomDelayCount;

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 6; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 1.5f + ((i % 3) * 2),
			TransInfo.Position.y - TransInfo.Scale.y + (i / 3),
			Buffer[i]
		);
}

void Player::Release()
{
}

void Player::ShootBullet(float _LimitY)
{
	if (DelayCount == 0)
	{
		BulletManager::GetInstance()->MakePlayerBullet(pBullet, TransInfo.Position, _LimitY);

		if (pBullet == NORMALBULLET)
			DelayCount = 1;
		else if (pBullet == LASERBULLET)
			DelayCount = 0;
	}
}

void Player::ShootBoom()
{
	if (BoomDelayCount == 0)
	{
		BulletManager::GetInstance()->MakePlayerBullet(BOOM, TransInfo.Position);

		BoomDelayCount = 90;
	}
}
