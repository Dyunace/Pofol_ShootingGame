#include "Explosion.h"
#include "CursorManager.h"

Explosion::Explosion() : Buffer(), RemoveCount(0) {}
Explosion::Explosion(Transform _Info) : Object(_Info), Buffer(), RemoveCount(0) {}
Explosion::~Explosion(){}

Object* Explosion::Initialize(string _Key)
{
	str = _Key;

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";
	Buffer[2] = (char*)"��";
	Buffer[3] = (char*)"��";
	Buffer[4] = (char*)"��";
	Buffer[5] = (char*)"��";
	Buffer[6] = (char*)"��";
	Buffer[7] = (char*)"��";
	Buffer[8] = (char*)"��";

	TransInfo.Position = Vector3(0, 0);

	RemoveCount = 20;

	return this;
}

int Explosion::Update()
{
	--RemoveCount;

	if (RemoveCount <= 0)
		return 1;

	return 0;
}

void Explosion::Render()
{
	if (TransInfo.Position.y > -1)
	{
		for (int i = 0; i < 3; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(
				TransInfo.Position.x - 2 + (i * 2),
				TransInfo.Position.y + 1,
				Buffer[6 + i]);
		}
	}
	if (TransInfo.Position.y > 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(
				TransInfo.Position.x - 2 + (i * 2),
				TransInfo.Position.y,
				Buffer[3 + i]);
		}
	}
	if (TransInfo.Position.y > 1)
	{
		for (int i = 0; i < 3; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(
				TransInfo.Position.x - 2 + (i * 2),
				TransInfo.Position.y - 1,
				Buffer[i]);
		}
	}
}

void Explosion::Release()
{
}
