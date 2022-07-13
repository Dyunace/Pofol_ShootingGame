#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy();
	Enemy(Transform _Info);
	virtual ~Enemy();
public:
	virtual Object* Initialize(string _Key) PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

protected:
	int Hp;
private:
	void ShootBullet();
};
