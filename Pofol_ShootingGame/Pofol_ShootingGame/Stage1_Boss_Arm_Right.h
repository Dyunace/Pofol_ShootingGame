#pragma once
#include "Stage1_Boss.h"

class Stage1_Boss_Arm_Right : public Stage1_Boss
{
private:
	char* Buffer[12];
public:
	Stage1_Boss_Arm_Right();
	~Stage1_Boss_Arm_Right();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

