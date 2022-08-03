#pragma once
#include "Stage1_Boss.h"

class Stage1_Boss_Head : public Stage1_Boss
{
private:
	char* Buffer[9];
public:
	Stage1_Boss_Head();
	~Stage1_Boss_Head();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	virtual void ShootBullet() override;
};