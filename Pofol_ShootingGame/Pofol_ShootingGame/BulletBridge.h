#pragma once
#include "Bridge.h"
#include "Object.h"

class BulletBridge : public Bridge
{
protected:
	// Bullet 기본 정보
	char* Buffer[1];
	float Speed;
	int Color;

	int Damage;

	Vector3 TargetDirection;
public:
	BulletBridge() : Speed(0), Color(0), Damage(0), TargetDirection(0, 1), Buffer() {};
	virtual ~BulletBridge() {};
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	virtual void SetTarget(Vector3 _Target = Vector3(0, 1))PURE;
	virtual void SetTarget(float _x, float _y = 1.0f)PURE;

public:
	int BulletPriview(float _left, float _right, float _up)
	{
		//if (pObject->GetPosition().x >= _right || pObject->GetPosition().y <= _up)
		if (pObject->GetPosition().x <= _left || pObject->GetPosition().x >= _right || pObject->GetPosition().y <= _up)
			return BUFFER_OVER;
		else
			return 0; 
	}
};