#pragma once
#include "Stage1_Boss.h"

class Stage1_Boss_Shield_Left : public Stage1_Boss
{
private:
	char* Buffer[10];
public:
	Stage1_Boss_Shield_Left();
	~Stage1_Boss_Shield_Left();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

