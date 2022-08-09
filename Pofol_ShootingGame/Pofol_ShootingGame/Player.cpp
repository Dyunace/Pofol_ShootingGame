#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "BulletManager.h"
#include "UserInstance.h"

Player::Player() : BoomDelayCount(0), RespawnCount(0)
{
	for (int i = 0; i < 6; ++i)
		Buffer[i] = nullptr;
}
Player::Player(Transform _Info) : Object(_Info), Buffer(), BoomDelayCount(0), RespawnCount(0) {}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	str = _Key;

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

	canMove = true;
	canShoot = true;

	return this;
}

int Player::Update()
{

	if (isVisible)
	{
		DWORD dwKey = InputManager::GetInstance()->GetKey();

		// 이동
		if (canMove)
		{
			if (dwKey & KEY_UP && TransInfo.Position.y - TransInfo.Scale.y > 0)
				TransInfo.Position.y -= 1.0;	// 위로 이동 시 감속
			if (dwKey & KEY_DOWN && TransInfo.Position.y + TransInfo.Scale.y < ConsoleHeightSize)
				TransInfo.Position.y += 1.0;	// 아래로 이동 시 가속
			if (dwKey & KEY_LEFT && TransInfo.Position.x - TransInfo.Scale.x > 0)
				TransInfo.Position.x -= 1.5;
			if (dwKey & KEY_RIGHT && TransInfo.Position.x + TransInfo.Scale.x * 2 < ConsoleWidthSize)
				TransInfo.Position.x += 1.5;
		}

		// 공격 (F버튼)
		if (canShoot)
		{
			if (dwKey & KEY_F || dwKey & KEY_SPACE)
				ShootBullet();

			if ((dwKey & KEY_D))
				ShootBoom();
		}
	}

	if (DelayCount > 0)
		--DelayCount;
	if (BoomDelayCount > 0)
		--BoomDelayCount;
	if (RespawnCount > 0)
		--RespawnCount;

	return 0;
}

void Player::Render()
{
	if (isVisible)
	{
		if (canRender)
		{
			for (int i = 0; i < 6; ++i)
				CursorManager::GetInstance()->WriteBuffer(
					TransInfo.Position.x - TransInfo.Scale.x * 1.5f + ((i % 3) * 2),
					TransInfo.Position.y - TransInfo.Scale.y + (i / 3),
					Buffer[i]
				);
		}
	}
}

void Player::Release()
{
}

void Player::ShootBullet(float _LimitY)
{
	if (DelayCount == 0)
	{
		auto bullet = UserInstance::GetInstance()->GetBullet();

		BulletManager::GetInstance()->MakePlayerBullet(bullet, TransInfo.Position, _LimitY);

		if (bullet == NORMALBULLET)
			DelayCount = 1;
		else if (bullet == LASERBULLET)
			DelayCount = 0;
	}
}

void Player::ShootBoom()
{
	if (BoomDelayCount == 0)
	{
		if (UserInstance::GetInstance()->GetBoom() > 0)
		{
			BulletManager::GetInstance()->MakePlayerBullet(BOOM, TransInfo.Position);

			BoomDelayCount = 90;

			UserInstance::GetInstance()->AddBoom(-1);
		}
	}
}

void Player::PlayerRespawn()
{
	// 피격 시
	if (isVisible == true && RespawnCount == 0)
	{
		// 다음 시간까지 카운트
		RespawnCount = 30;

		// 화면에 안보임 + 행동 불능
		isVisible = false;

		// 위치 미리 이동
		TransInfo.Position = Vector3(40, 40);
	}
	else if (isVisible == false && RespawnCount == 1)
	{
		// 다음 시간까지 무적 판정
		RespawnCount = 30;

		// 화면에 보임 + 행동 가능
		isVisible = true;
	}
	else if (isVisible == true && RespawnCount != 0)
	{
		// 무적 시간 동안 화면에 깜빡임
		if (RespawnCount % 3 == 0)
			canRender = !canRender;

		if (RespawnCount == 1)
			canRender = true;
	}
}
