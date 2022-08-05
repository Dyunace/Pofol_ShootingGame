#pragma once
#include "EnemyBridge.h"

class Object;
class Stage1_Boss : public EnemyBridge
{
protected:
	Object* Core;


	int CoreHp = 400;
	int HeadHp = 550;
	int ArmHp = 700;
	int ShieldHp = 850;
public:
	Stage1_Boss() : Core(nullptr) {}
	virtual ~Stage1_Boss() {}
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;};

