#pragma once
#include "Object.h"

class Player : public Object
{
private:
	char* Buffer[6];
public:
	Player();
	virtual ~Player();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

