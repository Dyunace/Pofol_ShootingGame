#pragma once
#include "EnemyBridge.h"

class Object;
class Stage1_Boss : public EnemyBridge
{
protected:
	Object* Core;
	int BossPhase;

	int CoreHp = 150;
	int CoreShootDelay = 2;

	int HeadHp = 175;
	int HeadShootDelay = 40;

	int ArmHp = 200;
	int ArmShootDelay = 30;

	int ShieldHp = 250;
	int ShielShootDelay = 20;

public:
	Stage1_Boss() : Core(nullptr), BossPhase(0) {}
	virtual ~Stage1_Boss() {}
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

public:
	void SetBossPhase(int _Phase) { BossPhase = _Phase; }
};