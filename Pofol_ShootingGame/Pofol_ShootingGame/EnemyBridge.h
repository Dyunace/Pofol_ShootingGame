#pragma once
#include "Bridge.h"
#include "Object.h"

class EnemyBridge : public Bridge
{
protected:
	char* Buffer[4];
public:
	EnemyBridge() : Buffer() {};
	virtual ~EnemyBridge() {};

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};