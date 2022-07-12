#pragma once
#include "Headers.h"

class Object
{
protected:
	string str;
	const int BufferSize;
public:
	Object();
	virtual ~Object();
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

