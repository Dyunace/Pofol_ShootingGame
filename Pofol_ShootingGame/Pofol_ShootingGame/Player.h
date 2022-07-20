#pragma once
#include "Object.h"

class Player : public Object
{
private:
	char* Buffer[6];
	string pBullet;
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
	// 플레이어의 총알
	string GetBullet() { return pBullet; }	// 현재 총알 이름 가져오기
	void SetBullet(string _Bullet) { pBullet = _Bullet; }	// 총알 교체하기

public:
	void ShootBullet(float _LimitY = 0);
};

