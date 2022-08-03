#pragma once
#include "Stage1_Boss.h"

class Stage1_Boss_Core : public Stage1_Boss
{
private:
	char* Buffer[35];
public:
	Stage1_Boss_Core();
	~Stage1_Boss_Core();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	virtual void ShootBullet() override;
};

