#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "BulletManager.h"
#include "UserInstance.h"

Player::Player() : BoomDelayCount(0), RespawnCount(0), DeathCount(0)
{
	for (int i = 0; i < 6; ++i)
		Buffer[i] = nullptr;
}
Player::Player(Transform _Info) : Object(_Info), Buffer(), BoomDelayCount(0), RespawnCount(0), DeathCount(0) {}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	str = _Key;

	// Buffer[4] �ھ ����
	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";
	Buffer[2] = (char*)"��";
	Buffer[3] = (char*)"��";
	Buffer[4] = (char*)"��";
	Buffer[5] = (char*)"��";

	TransInfo.Position = Vector3(0, 0);
	TransInfo.Rotation = Vector3(0, 0);
	TransInfo.Scale = Vector3(2.0f, 1.0f); // �ھ��� ũ��

	canMove = true;
	canShoot = true;

	return this;
}

int Player::Update()
{

	if (isVisible)
	{
		DWORD dwKey = InputManager::GetInstance()->GetKey();

		// �̵�
		if (canMove)
		{
			if (dwKey & KEY_UP && TransInfo.Position.y - TransInfo.Scale.y > 0)
				TransInfo.Position.y -= 1.0;	// ���� �̵� �� ����
			if (dwKey & KEY_DOWN && TransInfo.Position.y + TransInfo.Scale.y < ConsoleHeightSize)
				TransInfo.Position.y += 1.0;	// �Ʒ��� �̵� �� ����
			if (dwKey & KEY_LEFT && TransInfo.Position.x - TransInfo.Scale.x > 0)
				TransInfo.Position.x -= 1.5;
			if (dwKey & KEY_RIGHT && TransInfo.Position.x + TransInfo.Scale.x * 2 < ConsoleWidthSize)
				TransInfo.Position.x += 1.5;
		}

		// ���� (F��ư)
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
	if (DeathCount > 0)
		--DeathCount;
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
	// �ǰ� ��
	if (DeathCount == 0 && RespawnCount == 0)
	{
		// ���� ī��Ʈ ���� ������
		DeathCount = 30;

		// ������ ī��Ʈ ���� ���� ����
		RespawnCount = 60;

		// ȭ�鿡 �Ⱥ��� + �ൿ �Ҵ�
		isVisible = false;

		// ��ġ �̸� �̵�
		TransInfo.Position = Vector3(40, 40);
	}
	else if (isVisible == false && DeathCount == 0 && RespawnCount != 0)
	{
		// ȭ�鿡 ���� + �ൿ ����
		isVisible = true;
	}
	else if (isVisible == true && DeathCount == 0 && RespawnCount != 0)
	{
		// ���� �ð� ���� ȭ�鿡 ������
		if (RespawnCount % 3 == 0)
			canRender = !canRender;

		if (RespawnCount == 1)
			canRender = true;
	}
}
