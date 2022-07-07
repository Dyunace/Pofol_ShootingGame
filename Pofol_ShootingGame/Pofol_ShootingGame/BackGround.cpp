#include "BackGround.h"
#include "CursorManager.h"

BackGround::BackGround(){}

BackGround::~BackGround(){}

void BackGround::Initialize()
{
	Buffer[0] = (char*)"¡Å";
	Buffer[1] = (char*)"¡ñ";

	RandBuffer[0] = (char*)"¥ï";
	RandBuffer[1] = (char*)"¢Á";
	RandBuffer[2] = (char*)"¥ò";
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
