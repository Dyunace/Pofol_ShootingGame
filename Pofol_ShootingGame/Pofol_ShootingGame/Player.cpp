#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalBullet.h"
#include "LaserBullet.h"
#include "BulletManager.h"

Player::Player() : Buffer() {}
Player::Player(Transform _Info) : Object(_Info), Buffer() {}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	str = _Key;

	pBullet = NORMALBULLET;

	// Buffer[4] �ھ �������� ��
	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";
	Buffer[2] = (char*)"��";
	Buffer[3] = (char*)"��";
	Buffer[4] = (char*)"��";
	Buffer[5] = (char*)"��";

	TransInfo.Position = Vector3(0, 0);
	TransInfo.Rotation = Vector3(0, 0);
	TransInfo.Scale = Vector3(2, 1); // �ھ��� ũ��

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	// �̵�
	if (dwKey & KEY_UP && TransInfo.Position.y - TransInfo.Scale.y > 0)
		TransInfo.Position.y -= 0.75;	// ���� �̵� �� ����
	if (dwKey & KEY_DOWN && TransInfo.Position.y + TransInfo.Scale.y < ConsoleHeightSize)
		TransInfo.Position.y += 1.25;	// �Ʒ��� �̵� �� ����
	if (dwKey & KEY_LEFT && TransInfo.Position.x - TransInfo.Scale.x > 0)
		TransInfo.Position.x -= 1.5;
	if (dwKey & KEY_RIGHT && TransInfo.Position.x + TransInfo.Scale.x * 2 < ConsoleWidthSize)
		TransInfo.Position.x += 1.5;

	// ���� (F��ư)
	if (dwKey & KEY_F)
		ShootBullet();
	// ���� (�����̽� ��)
	if (dwKey & KEY_SPACE)
		ShootBullet();

	--DelayCount;

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 6; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x + (i % 3  * 2) - TransInfo.Scale.x,
			TransInfo.Position.y + (i / 3) - TransInfo.Scale.y,
			Buffer[i]
		);
}

void Player::Release()
{
}

void Player::ShootBullet(float _LimitY)
{
	if (DelayCount < 0)
	{
		BulletManager::GetInstance()->MakePlayerBullet(pBullet, TransInfo.Position, _LimitY);

		if (pBullet == NORMALBULLET)
			DelayCount = 1;
		else if (pBullet == LASERBULLET)
			DelayCount = 0;
	}
}
