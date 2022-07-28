#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	int ShootDelay;
	int Hp;
	float MoveSpeed;
	int MoveType;
	int MoveCount;
	int BulletType;

	int DamageEfect;
public:
	EnemyBridge() : 
		ShootDelay(0), Hp(0), MoveSpeed(0.0f), MoveType(0), MoveCount(0), BulletType(0), DamageEfect(false) {};
	virtual ~EnemyBridge() {};

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	virtual void ShootBullet() PURE;
public:
	int GetHP() const { return Hp; }
	void SetHp(int _Damage) { Hp = _Damage; }

	int GetMoveType() const { return MoveType; }
	void SetMovement(int _Type) { MoveType = _Type; }

	int GetMoveCount() const { return MoveCount; }

	bool GetDamageEfect() { return DamageEfect; }
	void SetDamageEfect(int _Count) { DamageEfect = _Count; }
protected:
	bool BufferCheck();
	void Movement();
	void DebugRender();
};