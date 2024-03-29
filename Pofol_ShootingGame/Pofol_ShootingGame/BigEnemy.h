#pragma once
#include "EnemyBridge.h"

class BigEnemy : public EnemyBridge
{
private:
	char* Buffer[16];
public:
	BigEnemy();
	virtual ~BigEnemy();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

