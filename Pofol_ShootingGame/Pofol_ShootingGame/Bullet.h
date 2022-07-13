#pragma once
#include "Object.h"

class Bullet : public Object
{
protected:
	float Speed;
	int Color;
public:
	Bullet();
	Bullet(Transform _Info);
	virtual ~Bullet();
public:
	virtual Object* Initialize(string _Key) PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	virtual Object* Clone() PURE;
};

