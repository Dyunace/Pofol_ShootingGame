#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy();
	Enemy(Transform _Info);
	virtual ~Enemy();

	virtual Object* Clone() override { return new Enemy(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
protected:
	int Hp;
};
