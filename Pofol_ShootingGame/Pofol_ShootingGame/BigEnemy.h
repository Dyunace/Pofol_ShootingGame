#pragma once
#include "EnemyBridge.h"

class BigEnemy : public EnemyBridge
{
private:
	char* Buffer[9];
public:
	BigEnemy();
	virtual ~BigEnemy();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	virtual void ShootBullet() override;
};

