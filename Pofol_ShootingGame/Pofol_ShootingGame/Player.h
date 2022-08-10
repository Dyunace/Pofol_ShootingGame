#pragma once
#include "Object.h"

class Player : public Object
{
private:
	char* Buffer[6];

	int BoomDelayCount;

	int RespawnCount;
	int DeathCount;
public:
	Player();
	Player(Transform _Info);
	virtual ~Player();

	virtual Object* Clone() override { return new Player(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	/// <summary>
	/// 히히 총알 발사
	/// </summary>
	/// <param name="_LimitY">레이저 생성 한계값</param>
	void ShootBullet(float _LimitY = 0);
	void ShootBoom();

public:
	void SetCanMove(bool _b) { canMove = _b; };
	void SetCanShoot(bool _b) { canShoot = _b; };

	int GetDeathCount() { return DeathCount; }
	int GetRespawnCount() { return RespawnCount; }

public:
	void PlayerRespawn();
};

