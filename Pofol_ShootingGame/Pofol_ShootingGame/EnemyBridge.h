#pragma once
#include "Bridge.h"
#include "Object.h"

class EnemyBridge : public Bridge
{
protected:
	int ShootDelay;
	int Hp;
	int MoveType;
public:
	EnemyBridge() : ShootDelay(0), Hp(0) {};
	virtual ~EnemyBridge() {};

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	virtual void ShootBullet() PURE;

public:
	int GetHP() { return Hp; }

	void TakeDamage(int _Damage) { Hp -= _Damage; }
};