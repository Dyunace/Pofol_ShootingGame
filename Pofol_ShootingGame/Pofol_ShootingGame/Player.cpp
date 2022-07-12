#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"

Player::Player()
{
	for (int i = 0; i < 6; ++i)
		Buffer[i] = (char*)"";
}
Player::~Player(){}

void Player::Initialize()
{
	// Buffer[4] 코어를 기준으로 함
	Buffer[0] = (char*)"┏";
	Buffer[1] = (char*)"Π";
	Buffer[2] = (char*)"┓";
	Buffer[3] = (char*)"┻";
	Buffer[4] = (char*)"⊙";
	Buffer[5] = (char*)"┻";
}

void Player::Update()
{
	if (InputManager::GetInstance()->GetKey() & KEY_UP)
		TransInfo.Position.y -= 1;

	if (InputManager::GetInstance()->GetKey() & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (InputManager::GetInstance()->GetKey() & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (InputManager::GetInstance()->GetKey() & KEY_RIGHT)
		TransInfo.Position.x += 1;
}

void Player::Render()
{
	for (int i = 0; i < 6; ++i)
			CursorManager::GetInstance()->WriteBuffer(TransInfo.Position.x + (i % 3  * 2) - 2, TransInfo.Position.y + i / 3 - 1, Buffer[i]);
}

void Player::Release()
{
}