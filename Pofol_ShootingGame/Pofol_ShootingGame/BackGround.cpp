#include "BackGround.h"
#include "CursorManager.h"

BackGround::BackGround(){}

BackGround::~BackGround(){}

void BackGround::Initialize()
{
	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

	RandBuffer[0] = (char*)"��";
	RandBuffer[1] = (char*)"��";
	RandBuffer[2] = (char*)"��";
}

void BackGround::Update()
{
}

void BackGround::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0, 0, Buffer[0]);
}

void BackGround::Release()
{
}
