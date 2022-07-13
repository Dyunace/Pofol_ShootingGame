#pragma once
#include "Object.h"

class Player : public Object
{
private:
	char* Buffer[6];
	BULLET Bullet;
public:
	Player();
	Player(Transform _Info);
	virtual ~Player();

	virtual Object* Clone() override { return new Player(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
private:
	void ShootBullet();
public:
	void SetBullet(BULLET _Weapon);
};

