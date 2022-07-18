#pragma once
#include "BulletBridge.h"

class LaserBullet : public BulletBridge
{
public:
	LaserBullet();
	virtual ~LaserBullet();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

