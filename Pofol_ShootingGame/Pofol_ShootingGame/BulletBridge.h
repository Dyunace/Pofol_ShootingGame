#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	// 불릿의 데이터만 넣음
	float Speed;
	int Color;

	char* Buffer[1];

	int Damage;
public:
	BulletBridge() : Speed(0), Color(0) {};
	virtual ~BulletBridge() {};
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};