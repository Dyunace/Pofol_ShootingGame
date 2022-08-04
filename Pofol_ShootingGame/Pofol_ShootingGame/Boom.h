#pragma once
#include "BulletBridge.h"

class Boom : public BulletBridge
{
private:
	int Count;

	char* BulletBuffer[2];
	char* Buffer[4];

	list<Object*>* EnemyList[3];
public:
	Boom();
	virtual ~Boom();
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	virtual void SetTarget(Vector3 _Target = Vector3(0, 1))override;
	virtual void SetTarget(float _x, float _y = 1.0f)override;

private:
	void AttackAllEnemy();
	void RemoveAllBullet();
};

