#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player();
	virtual ~Player();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

