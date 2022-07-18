#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalBullet.h"
#include "LaserBullet.h"

Player::Player() {}
Player::Player(Transform _Info) : Object(_Info) {}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	str = _Key;
	hp = 1;

	pBullet = "NormalBullet";

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

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	// 이동
	if (dwKey & KEY_UP && TransInfo.Position.y - TransInfo.Scale.y > 0)
		TransInfo.Position.y -= 0.75;	// 위로 이동 시 감속
	if (dwKey & KEY_DOWN && TransInfo.Position.y + TransInfo.Scale.y < ConsoleHeightSize)
		TransInfo.Position.y += 1.25;	// 아래로 이동 시 가속
	if (dwKey & KEY_LEFT && TransInfo.Position.x - TransInfo.Scale.x > 0)
		TransInfo.Position.x -= 1.5;
	if (dwKey & KEY_RIGHT && TransInfo.Position.x + TransInfo.Scale.x * 2 < ConsoleWidthSize)
		TransInfo.Position.x += 1.5;

	// 공격 (F버튼)
	if (dwKey & KEY_F)
		ShootBullet();

	// 공격 (스페이스 바)
	if (dwKey & KEY_SPACE)
		ShootBullet();

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

void Player::ShootBullet()
{
	if (pBullet == NORMALBULLET)
	{
		Bridge* pBullet = new NormalBullet;
		ObjectManager::GetInstance()->AddBullet(NORMALBULLET, pBullet, Vector3(TransInfo.Position.x, TransInfo.Position.y - 1));
	}
	else if (pBullet == LASERBULLET)
	{
		Bridge* pBullet = new LaserBullet;
		ObjectManager::GetInstance()->AddBullet(LASERBULLET, pBullet, Vector3(TransInfo.Position.x, TransInfo.Position.y - 1));
	}
}
