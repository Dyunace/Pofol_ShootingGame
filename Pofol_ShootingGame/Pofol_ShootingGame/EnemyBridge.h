#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	int Hp;
	
	float MoveSpeed;
	int MoveType;
	int MoveCount;
	
	int BulletType;
	Vector3 BulletPort;
	int ShootDelay;

	int DamageEfect;

	int Score;
public:
	EnemyBridge() : 
		ShootDelay(0), Hp(0), MoveSpeed(0.0f), MoveType(0), MoveCount(0), BulletType(0), DamageEfect(false), BulletPort(0, 0), Score(0) {};
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

	int GetScore() { return Score; }
protected:
	bool BufferCheck();
	void Movement(Vector3 _MoveLimit = Vector3(0, 0));
	void DebugRender();
};