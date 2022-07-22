#pragma once
#include "EnemyBridge.h"

class NormalEnemy : public EnemyBridge
{
private:
	char* Buffer[4];
	string pBullet;
public:
	NormalEnemy();
	virtual ~NormalEnemy();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	virtual void ShootBullet() override;
	virtual void SetMovement(int _Type) override;
};