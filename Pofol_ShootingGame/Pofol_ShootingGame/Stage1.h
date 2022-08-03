#pragma once
#include "Stage.h"

class Stage1 : public Stage
{
protected:
	list<Object*>* Stage1Boss[6];
public:
	Stage1();
	virtual ~Stage1();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	void GetBossList();
	void BossCollisionCheck();
};