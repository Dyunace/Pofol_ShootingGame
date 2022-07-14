#pragma once
#include "Enemy.h"

class NormalEnemy : public Enemy
{
private:
	char* Buffer[4];
public:
	NormalEnemy();
	NormalEnemy(Transform _Info);
	virtual ~NormalEnemy();

	virtual Object* Clone() override { return new NormalEnemy(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void ShootBullet() override;
};

