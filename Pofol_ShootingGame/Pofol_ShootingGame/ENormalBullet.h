#pragma once
#include "BulletBridge.h"

class ENormalBullet : public BulletBridge
{
public:
	ENormalBullet();
	virtual ~ENormalBullet();
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	virtual void SetTarget(Vector3 _Target = Vector3(0, 1))override;
	virtual void SetTarget(float _x, float _y = 1.0f)override;
};

