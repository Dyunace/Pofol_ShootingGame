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
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone() override { return new Bullet(*this); };
};

