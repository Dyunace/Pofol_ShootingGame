#pragma once
#include "Stage1_Boss.h"

class Stage1_Boss_Shield_Right : public Stage1_Boss
{
private:
	char* Buffer[10];
public:
	Stage1_Boss_Shield_Right();
	~Stage1_Boss_Shield_Right();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	virtual void ShootBullet() override;
};

