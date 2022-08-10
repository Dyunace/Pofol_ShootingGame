#pragma once
#include "Bridge.h"
#include "Object.h"
#include "CursorManager.h"

class ItemBridge : public Bridge
{
public:
	ItemBridge() : MoveVector(0, 0) {};
	virtual ~ItemBridge() {};
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

protected:
	Vector3 MoveVector;
public:
	void SetMoveVector()
	{
		int val = 200;
		float x = 0;
		float y = 0;

		srand(DWORD(GetTickCount64()));

		x = (float)(rand() % val) - (val / 2);
		y = sqrt((val * val) - (x * x)) * (((rand() % 2) * 2 - 1) * (-1));

		x = x * 0.0025f;
		y = y * 0.0025f;

		MoveVector = Vector3(x, y);
	}

	void VectorCheck(Vector3 _Position, Vector3& _MoveVector)
	{
		if ((_Position.x - 4 < 0) || (_Position.x + 4 > ConsoleWidthSize))
			_MoveVector.x = _MoveVector.x * -1;

		if ((_Position.y - 2 < 0) || (_Position.y + 2 > ConsoleHeightSize))
			_MoveVector.y = _MoveVector.y * -1;
	}
};

