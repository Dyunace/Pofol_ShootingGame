#pragma once
#include "EnemyBridge.h"

class NormalEnemy : public EnemyBridge
{

public:
	NormalEnemy();
	virtual ~NormalEnemy();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

