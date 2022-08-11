#include "Explosion.h"
#include "CursorManager.h"

Explosion::Explosion() : Buffer(), RemoveCount(0) {}
Explosion::Explosion(Transform _Info) : Object(_Info), Buffer(), RemoveCount(0) {}
Explosion::~Explosion(){}

Object* Explosion::Initialize(string _Key)
{
	str = _Key;

	Buffer[0] = (char*)"¢Ø";
	Buffer[1] = (char*)"¡è";
	Buffer[2] = (char*)"¢Ö";
	Buffer[3] = (char*)"¡ç";
	Buffer[4] = (char*)"¡Ø";
	Buffer[5] = (char*)"¡æ";
	Buffer[6] = (char*)"¢×";
	Buffer[7] = (char*)"¡é";
	Buffer[8] = (char*)"¢Ù";

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
