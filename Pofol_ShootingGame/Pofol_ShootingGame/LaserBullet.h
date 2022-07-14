#pragma once
#include "Bullet.h"

class LaserBullet : public Bullet
{
protected:
	char* Buffer[1];
public:
	LaserBullet();
	LaserBullet(Transform _Info);
	virtual ~LaserBullet();

	virtual Object* Clone() override { return new LaserBullet(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void ShootBullet() override;
};

