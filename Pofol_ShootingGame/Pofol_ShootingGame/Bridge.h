#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	Object* pObject;
public:
	Bridge() : pObject(nullptr) {}
	virtual ~Bridge() {}
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Object* GetpObject() { return pObject; }
	void SetObject(Object* _Object) { pObject = _Object; }
};