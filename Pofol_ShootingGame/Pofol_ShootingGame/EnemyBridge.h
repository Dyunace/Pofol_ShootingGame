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

	Vector3 BulletPort;
public:
	EnemyBridge() : 
		ShootDelay(0), Hp(0), MoveSpeed(0.0f), MoveType(0), MoveCount(0), BulletType(0), DamageEfect(false), BulletPort(0, 0) {};
	virtual ~EnemyBridge() {};

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;


protected:
	void ShootBullet(Vector3 _Position);

public:
	int GetHP() const { return Hp; }
	void SetHp(int _Damage) { Hp = _Damage; }

	int GetMoveType() const { return MoveType; }
	void SetMovement(int _Type) { MoveType = _Type; MoveCount = 0; }

	int GetMoveCount() const { return MoveCount; }

	bool GetDamageEfect() { return DamageEfect; }
	void SetDamageEfect(int _Count) { DamageEfect = _Count; }
protected:
	bool BufferCheck();
	void Movement(Vector3 _MoveLimit = Vector3(0, 0));
	void DebugRender();
};