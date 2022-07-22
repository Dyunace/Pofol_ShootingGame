#pragma once
#include "Stage.h"

class Stage1 : public Stage
{
public:
	Stage1();
	virtual ~Stage1();
private:
	Object* pEnemy;
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

