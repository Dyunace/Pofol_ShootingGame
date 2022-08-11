#pragma once
#include "Object.h"


class Explosion : public Object
{
private:
	char* Buffer[9];
	int RemoveCount;
public:
	Explosion();
	Explosion(Transform _Info);
	virtual ~Explosion();
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual Object* Clone() override { return new Explosion(*this); } ;
};

