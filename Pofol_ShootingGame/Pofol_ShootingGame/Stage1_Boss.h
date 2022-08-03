#pragma once
#include "EnemyBridge.h"

class Object;
class Stage1_Boss : public EnemyBridge
{
protected:
	Object* Core;
	int BossPhase;
public:
	Stage1_Boss();
	virtual ~Stage1_Boss();
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
public:
	virtual void ShootBullet() PURE; 
public:
	int GetBossPhase() { return BossPhase; };
	void SetBossPhase(int _val) { BossPhase = _val; };
};

