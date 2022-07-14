#pragma once
#include "Bullet.h"

class NormalBullet : public Bullet
{
protected:
	char* Buffer[1];
public:
	NormalBullet();
	NormalBullet(Transform _Info);
	virtual ~NormalBullet();

	virtual Object* Clone() override { return new NormalBullet(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void ShootBullet() override;
};
