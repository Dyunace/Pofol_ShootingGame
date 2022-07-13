#pragma once
#include "Enemy.h"

class ENomal : public Enemy
{
public:
	ENomal();
	ENomal(Transform _Info);
	virtual ~ENomal();

	virtual Object* Clone() override { return new ENomal(*this); };
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

