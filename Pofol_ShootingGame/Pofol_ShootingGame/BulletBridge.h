#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	// �Ҹ��� �����͸� ����
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