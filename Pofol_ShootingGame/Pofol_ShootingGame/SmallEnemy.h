#pragma once
#include "EnemyBridge.h"

class SmallEnemy : public EnemyBridge
{
private:
	char* Buffer[2];
public:
	SmallEnemy();
	virtual ~SmallEnemy();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	virtual void ShootBullet() override;
};